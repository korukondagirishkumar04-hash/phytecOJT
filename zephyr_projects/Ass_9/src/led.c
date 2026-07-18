#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#include "led.h"

/* Device Tree LED Alias */
#define LED0_NODE DT_ALIAS(led0)

/* Get LED GPIO information */
static const struct gpio_dt_spec led =GPIO_DT_SPEC_GET(LED0_NODE, gpios);

/* Initialize LED */
void led_init(void)
{
    if (!gpio_is_ready_dt(&led))
    {
        return;
    }

    gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
}

/* Turn LED ON */
void led_on(void)
{
    gpio_pin_set_dt(&led, 1);
}

/* Turn LED OFF */
void led_off(void)
{
    gpio_pin_set_dt(&led, 0);
}

/* Toggle LED */
void led_toggle(void)
{
    gpio_pin_toggle_dt(&led);
}

/* Blink LED multiple times */
void led_blink(int times, int delay_ms)
{
    for (int i = 0; i < times; i++)
    {
        led_on();
        k_msleep(delay_ms);

        led_off();
        k_msleep(delay_ms);
    }
}
