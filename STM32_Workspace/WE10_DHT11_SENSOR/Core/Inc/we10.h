#ifndef WE10_H
#define WE10_H

#include "main.h"
#include "dht11.h"

/* dht11_data lives in main.c, filled each loop by DHT11_Read_Data() */
extern DHT11_Data dht11_data;

void WE10_Init(char *SSID, char *PASSWD);
void MQTT_Init(void);
void mqtt_publish_data(void);

#endif /* WE10_H */
