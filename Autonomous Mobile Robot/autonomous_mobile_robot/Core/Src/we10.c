#include "we10.h"

static UART_HandleTypeDef *_hwifi;
static UART_HandleTypeDef *_hdebug;
static char _rx_buf[128];

/* -----------------------------------------------------------------------
 * Internal helper: send AT command to WE10, print response to TeraTerm
 * ----------------------------------------------------------------------- */
static void send_cmd(const char *cmd)
{
    memset(_rx_buf, 0, sizeof(_rx_buf));

    /* Send command to WE10 and echo to TeraTerm */
    HAL_UART_Transmit(_hwifi,  (uint8_t *)cmd, strlen(cmd), 1000);
    HAL_UART_Transmit(_hdebug, (uint8_t *)cmd, strlen(cmd), 1000);

    /* Wait for response */
    HAL_StatusTypeDef status = HAL_UART_Receive(_hwifi,
                                                 (uint8_t *)_rx_buf,
                                                 sizeof(_rx_buf) - 1,
                                                 2000);

    /* Forward response to TeraTerm */
    HAL_UART_Transmit(_hdebug, (uint8_t *)_rx_buf, strlen(_rx_buf), 1000);

    if (status != HAL_OK)
    {
        const char *err = "[WE10] No/timeout response\r\n";
        HAL_UART_Transmit(_hdebug, (uint8_t *)err, strlen(err), 1000);
    }
}

/* -----------------------------------------------------------------------
 * Public: initialise WiFi connection
 * ----------------------------------------------------------------------- */
void WE10_Init(UART_HandleTypeDef *hwifi, UART_HandleTypeDef *hdebug,
               const char *ssid, const char *password)
{
    _hwifi  = hwifi;
    _hdebug = hdebug;

    char buf[128];

    /* Reset module */
    send_cmd("CMD+RESET\r\n");
    HAL_Delay(5000);

    /* Station mode */
    send_cmd("CMD+WIFIMODE=1\r\n");
    HAL_Delay(2000);

    /* Connect to AP */
    sprintf(buf, "CMD+CONTOAP=%s,%s\r\n", ssid, password);
    send_cmd(buf);
    HAL_Delay(5000);

    /* Verify connection */
    send_cmd("CMD?WIFI\r\n");
    HAL_Delay(2000);

    WE10_Log("[WE10] WiFi init done\r\n");
}

/* -----------------------------------------------------------------------
 * Public: initialise MQTT connection to Rightech
 * ----------------------------------------------------------------------- */
void WE10_MQTT_Init(void)
{
    char buf[128];

    /* Broker address */
    sprintf(buf, "CMD+MQTTNETCFG=%s,%s\r\n", MQTT_BROKER, MQTT_PORT);
    send_cmd(buf);
    HAL_Delay(2000);

    /* Client config */
    sprintf(buf, "CMD+MQTTCONCFG=3,%s,,,,,,,,,\r\n", MQTT_CLIENT_ID);
    send_cmd(buf);
    HAL_Delay(2000);

    /* Start MQTT */
    send_cmd("CMD+MQTTSTART=1\r\n");
    HAL_Delay(5000);

    WE10_Log("[MQTT] Connected to Rightech\r\n");
}

/* -----------------------------------------------------------------------
 * Public: publish a payload string to an MQTT topic
 * ----------------------------------------------------------------------- */
void WE10_MQTT_Publish(const char *topic, const char *payload)
{
    char buf[128];
    sprintf(buf, "CMD+MQTTPUB=%s,%s\r\n", topic, payload);

    HAL_UART_Transmit(_hwifi, (uint8_t *)buf, strlen(buf), 1000);
    HAL_Delay(500);

    /* Log to TeraTerm */
    HAL_UART_Transmit(_hdebug, (uint8_t *)buf, strlen(buf), 1000);
}

/* -----------------------------------------------------------------------
 * Public: send a plain debug string to TeraTerm
 * ----------------------------------------------------------------------- */
void WE10_Log(const char *msg)
{
    HAL_UART_Transmit(_hdebug, (uint8_t *)msg, strlen(msg), 1000);
}
