#include <zephyr/kernel.h>
#include <stdio.h>

#include "led.h"

int main(void)
{
    printf("LED Driver Demo Started\n");

    /* Initialize LED */
    led_init();

    while (1)
    {
        printf("LED ON\n");
        led_on();
        k_msleep(1000);

        printf("LED OFF\n");
        led_off();
        k_msleep(1000);

        printf("LED TOGGLE\n");
        led_toggle();
        k_msleep(1000);

        printf("Blink LED 5 Times\n");
        led_blink(5, 500);

        printf("Waiting 2 Seconds...\n\n");
        k_msleep(2000);
    }

    return 0;
}
