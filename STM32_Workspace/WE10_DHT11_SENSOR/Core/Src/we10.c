
#include "we10.h"
#include <stdio.h>
#include <string.h>

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;

void WE10_Init(char *SSID, char *PASSWD)
{
    char buffer[128];
    HAL_StatusTypeDef status;

    void send_cmd(const char *cmd) {
        HAL_UART_Transmit(&huart1, (uint8_t*)cmd, strlen(cmd), 1000);
        HAL_UART_Transmit(&huart2, (uint8_t*)cmd, strlen(cmd), 1000);

        memset(buffer, 0, sizeof(buffer));
        status = HAL_UART_Receive(&huart1, (uint8_t*)buffer, sizeof(buffer) - 1, 2000);
        HAL_UART_Transmit(&huart2, (uint8_t*)buffer, strlen(buffer), 1000);

        if (status != HAL_OK) {
            printf("Error receiving response for %s\n", cmd);
        } else {
            printf("Response for %s: %s\n", cmd, buffer);
        }
    }

    /********* CMD+RESET **********/
    send_cmd("CMD+RESET\r\n");
    HAL_Delay(5000);

    /********* CMD+WIFIMODE=1 **********/
    send_cmd("CMD+WIFIMODE=1\r\n");
    HAL_Delay(2000);

    /********* CMD+CONTOAP=SSID,PASSWD **********/
    sprintf(buffer, "CMD+CONTOAP=%s,%s\r\n", SSID, PASSWD);
    send_cmd(buffer);
    HAL_Delay(5000);

    /********* CMD?WIFI **********/
    send_cmd("CMD?WIFI\r\n");
    HAL_Delay(2000);
}

void MQTT_Init(void)
{
    char buffer[128];

    void send_cmd(const char *cmd) {
        HAL_StatusTypeDef status;
        HAL_UART_Transmit(&huart1, (uint8_t*)cmd, strlen(cmd), 1000);
        HAL_UART_Transmit(&huart2, (uint8_t*)cmd, strlen(cmd), 1000);

        memset(buffer, 0, sizeof(buffer));
        status = HAL_UART_Receive(&huart1, (uint8_t*)buffer, sizeof(buffer) - 1, 2000);

        printf("Command: %s\n", cmd);
        if (status == HAL_OK) {
            printf("Response: %s\n", buffer);
        } else if (status == HAL_TIMEOUT) {
            printf("Response timeout for command: %s\n", cmd);
        } else {
            printf("Error receiving response for command: %s\n", cmd);
        }
    }

    /********* CMD+MQTTNETCFG **********/
    send_cmd("CMD+MQTTNETCFG=dev.rightech.io,1883\r\n");
    HAL_Delay(2000);

    /********* CMD+MQTTCONCFG **********/
    send_cmd("CMD+MQTTCONCFG=3,mqtt-korukondagirishkumar04-7rw8t7,,,,,,,,,\r\n");
    HAL_Delay(2000);

    /********* CMD+MQTTSTART **********/
    send_cmd("CMD+MQTTSTART=1\r\n");
    HAL_Delay(5000);

    /********* CMD+MQTTSUB **********/
    send_cmd("CMD+MQTTSUB=base/relay/led1\r\n");
    HAL_Delay(2000);
}

void mqtt_publish_data(void)
{
    char buffer[128];
    char temp_msg[32];
    char humid_msg[32];

    // Convert float to integer parts (x10 to keep 1 decimal place)
    int temp_int  = (int)(dht11_data.temperature * 10);
    int humid_int = (int)(dht11_data.humidity * 10);

    sprintf(temp_msg, "%d.%d", temp_int / 10, temp_int % 10);
    sprintf(humid_msg, "%d.%d", humid_int / 10, humid_int % 10);

    // Debug info
    char debug_dht[128];
    sprintf(debug_dht, "DHT11 Debug - Presence: %d, Raw: %d,%d,%d,%d, Sum: %d, Calc: %d\r\n",
            Presence, Rh_byte1, Rh_byte2, Temp_byte1, Temp_byte2, SUM,
            (Rh_byte1 + Rh_byte2 + Temp_byte1 + Temp_byte2));
    HAL_UART_Transmit(&huart2, (uint8_t*)debug_dht, strlen(debug_dht), 1000);

    // Publish temperature
    sprintf(buffer, "CMD+MQTTPUB=base/state/temperature,%s\r\n", temp_msg);
    HAL_UART_Transmit(&huart1, (uint8_t*)buffer, strlen(buffer), 1000);
    HAL_Delay(1000);

    // Publish humidity
    sprintf(buffer, "CMD+MQTTPUB=base/state/humidity,%s\r\n", humid_msg);
    HAL_UART_Transmit(&huart1, (uint8_t*)buffer, strlen(buffer), 1000);
    HAL_Delay(1000);

    // Check for any incoming messages (e.g. LED control)
    memset(buffer, 0, sizeof(buffer));
    HAL_StatusTypeDef status = HAL_UART_Receive(&huart1, (uint8_t*)buffer, sizeof(buffer) - 1, 100);

    if (status == HAL_OK && strlen(buffer) > 0) {
        HAL_UART_Transmit(&huart2, (uint8_t*)buffer, strlen(buffer), 1000);

        for (size_t i = 0; i < sizeof(buffer); i++) {
            if (buffer[i] == 'N') {
                HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
            } else if (buffer[i] == 'F') {
                HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
            }
        }
    }
}
