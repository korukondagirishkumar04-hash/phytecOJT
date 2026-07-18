#ifndef WE10_H_
#define WE10_H_

#include <zephyr/kernel.h>

int we10_init(void);
int we10_wait_ready(uint32_t timeout_ms);
int we10_connect_wifi(const char *ssid, const char *password,uint32_t timeout_ms);
int we10_mqtt_connect(const char *client_id,const char *broker,uint16_t port, uint32_t timeout_ms);
int we10_mqtt_publish(const char *topic,const char *data);

#endif

