/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 * Copyright (c) 2021 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/drivers/sensor_data_types.h>
#include <zephyr/rtio/rtio.h>
#include <zephyr/dsp/print_format.h>
#include <math.h>
#include <stdio.h>

#include "we10.h"

#define SEA_LEVEL_PRESSURE_HPA 1013.25



#define WIFI_SSID     "Hero"
#define WIFI_PASSWORD "hero1234"

#define MQTT_CLIENT_ID "mqtt-dokulamohitkumar-9wkkrs"
#define MQTT_BROKER    "dev.rightech.io"
#define MQTT_PORT      1883

const struct device *const dev = DEVICE_DT_GET_ANY(bosch_bme280);

SENSOR_DT_READ_IODEV(iodev, DT_COMPAT_GET_ANY_STATUS_OKAY(bosch_bme280),
                {SENSOR_CHAN_AMBIENT_TEMP, 0},
                {SENSOR_CHAN_PRESS, 0});

RTIO_DEFINE(ctx, 1, 1);

static const struct device *check_bmp280_device(void)
{
        if (dev == NULL) {
                printk("\nError: no device found.\n");
                return NULL;
        }
        if (!device_is_ready(dev)) {
                printk("\nError: Device \"%s\" is not ready; "
                       "check the driver initialization logs for errors.\n",
                       dev->name);
                return NULL;
        }
        printk("Found device \"%s\", getting sensor data\n", dev->name);
        return dev;
}

static double q31_to_double(int32_t q, int8_t shift)
{
        return (double)q * pow(2.0, shift - 31);
}

static double calculate_altitude(double pressure_hpa)
{
        return 44330.0 * (1.0 - pow(pressure_hpa / SEA_LEVEL_PRESSURE_HPA, 1.0 / 5.255));
}

static int we10_setup(void)
{
        int ret;

        ret = we10_init();
        if (ret != 0) {
                printk("WE10: init failed: %d\n", ret);
                return ret;
        }

        printk("WE10: waiting for module ready...\n");
        ret = we10_wait_ready(5000);
        if (ret != 0) {
                printk("WE10: module did not report ready: %d\n", ret);
                return ret;
        }

        printk("WE10: connecting to WiFi \"%s\"...\n", WIFI_SSID);
        ret = we10_connect_wifi(WIFI_SSID, WIFI_PASSWORD, 15000);
        if (ret != 0) {
                printk("WE10: WiFi connect failed: %d\n", ret);
                return ret;
        }

        printk("WE10: connecting to MQTT broker \"%s\"...\n", MQTT_BROKER);
        ret = we10_mqtt_connect(MQTT_CLIENT_ID, MQTT_BROKER, MQTT_PORT, 10000);
        if (ret != 0) {
                printk("WE10: MQTT connect failed: %d\n", ret);
                return ret;
        }

        printk("WE10: MQTT connected, ready to publish\n");
        return 0;
}

int main(void)
{
        const struct device *dev = check_bmp280_device();

        if (dev == NULL) {
                return 0;
        }

        bool mqtt_ready = (we10_setup() == 0);

        if (!mqtt_ready) {
                printk("WE10: continuing without MQTT publish (sensor-only mode)\n");
        }

        while (1) {
                uint8_t buf[128];
                int rc = sensor_read(&iodev, &ctx, buf, 128);

                if (rc != 0) {
                        printk("%s: sensor_read() failed: %d\n", dev->name, rc);
                        return rc;
                }

                const struct sensor_decoder_api *decoder;

                rc = sensor_get_decoder(dev, &decoder);
                if (rc != 0) {
                        printk("%s: sensor_get_decode() failed: %d\n", dev->name, rc);
                        return rc;
                }

                uint32_t temp_fit = 0;
                struct sensor_q31_data temp_data = {0};

                decoder->decode(buf,
                        (struct sensor_chan_spec) {SENSOR_CHAN_AMBIENT_TEMP, 0},
                        &temp_fit, 1, &temp_data);

                uint32_t press_fit = 0;
                struct sensor_q31_data press_data = {0};

                decoder->decode(buf,
                        (struct sensor_chan_spec) {SENSOR_CHAN_PRESS, 0},
                        &press_fit, 1, &press_data);

                double pressure_kpa = q31_to_double(press_data.readings[0].pressure,
                                                     press_data.shift);
                double pressure_hpa = pressure_kpa * 10.0;
                double altitude = calculate_altitude(pressure_hpa);

                printk("temp: %s%d.%d; press: %s%d.%d kPa; altitude: %d.%d m\n",
                        PRIq_arg(temp_data.readings[0].temperature, 6, temp_data.shift),
                        PRIq_arg(press_data.readings[0].pressure, 6, press_data.shift),
                        (int)altitude, (int)((altitude - (int)altitude) * 100));

                if (mqtt_ready) {
                        char payload[32];
                        double temp_c = q31_to_double(temp_data.readings[0].temperature,
                                                       temp_data.shift);

                        snprintf(payload, sizeof(payload), "%d.%d",
                                (int)temp_c,
                                (int)((temp_c - (int)temp_c) * 100));
                        we10_mqtt_publish("base/state/temperature", payload);

                        snprintf(payload, sizeof(payload), "%d.%d",
                                 (int)pressure_hpa,
                                 (int)((pressure_hpa - (int)pressure_hpa) * 100));
                        we10_mqtt_publish("base/state/pressure", payload);

                        snprintf(payload, sizeof(payload), "%d.%d",
                                 (int)altitude,
                                 (int)((altitude - (int)altitude) * 100));
                        we10_mqtt_publish("base/state/altitude", payload);
                }

                k_sleep(K_MSEC(1000));
        }

        return 0;
}
