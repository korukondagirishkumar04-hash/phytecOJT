#ifndef WE10_H
#define WE10_H

#include "main.h"
#include <string.h>
#include <stdio.h>

/* UART handles */
/* huart1 = WE10 WiFi module (38400 baud) */
/* huart2 = TeraTerm debug   (115200 baud) */

/* Rightech MQTT broker */
#define MQTT_BROKER     "dev.rightech.io"
#define MQTT_PORT       "1883"
#define MQTT_CLIENT_ID  "mqtt-sailenka222-phmkvv"

/* MQTT topic definitions */
#define TOPIC_ULTRASONIC    "base/state/ultrasonic"
#define TOPIC_FLAME         "base/state/flame"
#define TOPIC_MOTOR         "base/state/motor"

/* Function prototypes */
void WE10_Init(UART_HandleTypeDef *hwifi, UART_HandleTypeDef *hdebug,
               const char *ssid, const char *password);
void WE10_MQTT_Init(void);
void WE10_MQTT_Publish(const char *topic, const char *payload);
void WE10_Log(const char *msg);

#endif /* WE10_H */
