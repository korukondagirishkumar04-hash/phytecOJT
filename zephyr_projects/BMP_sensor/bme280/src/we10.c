#include "we10.h"
#include <zephyr/drivers/uart.h>
#include <zephyr/device.h>
#include <string.h>
#include <stdio.h>
#include <zephyr/sys/printk.h>

#define WE10_UART_NODE DT_NODELABEL(usart1)
#define WE10_LINE_MAX  256

static const struct device *we10_uart = DEVICE_DT_GET(WE10_UART_NODE);

int we10_init(void)
{
        if (!device_is_ready(we10_uart)) {
                return -ENODEV;
        }
        return 0;
}

static void we10_send_raw(const char *cmd)
{
        for (size_t i = 0; i < strlen(cmd); i++) {
                uart_poll_out(we10_uart, cmd[i]);
        }
}

/* Reads and logs whatever comes back for a fixed window, without requiring
 * a specific prefix. Mirrors the CubeIDE version's forgiving behavior. */
static void we10_drain_response(uint32_t window_ms)
{
        char line[WE10_LINE_MAX];
        size_t pos = 0;
        int64_t deadline = k_uptime_get() + window_ms;

        while (k_uptime_get() < deadline) {
                unsigned char c;

                if (uart_poll_in(we10_uart, &c) == 0) {
                        if (c == '\n') {
                                line[pos] = '\0';
                                if (pos > 0) {
                                        printk("WE10 <- %s\n", line);
                                }
                                pos = 0;
                        } else if (c != '\r' && pos < sizeof(line) - 1) {
                                line[pos++] = c;
                        }
                } else {
                        k_msleep(5);
                }
        }
}

static void we10_send_cmd(const char *cmd, uint32_t response_window_ms)
{
        printk("WE10 -> %s", cmd);
        we10_send_raw(cmd);
        we10_drain_response(response_window_ms);
}

int we10_wait_ready(uint32_t timeout_ms)
{
        ARG_UNUSED(timeout_ms);

        we10_send_cmd("CMD+RESET\r\n", 5000);
        return 0;
}

int we10_connect_wifi(const char *ssid, const char *password, uint32_t timeout_ms)
{
        ARG_UNUSED(timeout_ms);
        char cmd[128];

        we10_send_cmd("CMD+WIFIMODE=1\r\n", 2000);

        snprintf(cmd, sizeof(cmd), "CMD+CONTOAP=%s,%s\r\n", ssid, password);
        we10_send_cmd(cmd, 5000);

        we10_send_cmd("CMD?WIFI\r\n", 2000);

        return 0;
}

int we10_mqtt_connect(const char *client_id, const char *broker, uint16_t port,
                       uint32_t timeout_ms)
{
        ARG_UNUSED(timeout_ms);
        char cmd[160];

        snprintf(cmd, sizeof(cmd), "CMD+MQTTNETCFG=%s,%u\r\n", broker, port);
        we10_send_cmd(cmd, 2000);

        snprintf(cmd, sizeof(cmd), "CMD+MQTTCONCFG=3,%s,,,,,,,,,\r\n", client_id);
        we10_send_cmd(cmd, 2000);

        we10_send_cmd("CMD+MQTTSTART=1\r\n", 5000);

        return 0;
}

int we10_mqtt_publish(const char *topic, const char *data)
{
        char cmd[300];

        snprintf(cmd, sizeof(cmd), "CMD+MQTTPUB=%s,%s\r\n", topic, data);
        we10_send_cmd(cmd, 2000);

        return 0;
}
