#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define DELAY_1 200
#define DELAY_2 500
#define DELAY_3 2000

/* The devicetree node identifier for the "led0" alias. */
#define LED0_NODE DT_ALIAS(led0)

/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
static const struct gpio_dt_spec leda5 = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

int main(void)
{
        int ret;

        if (!gpio_is_ready_dt(&leda5)) {
                return 0;
        }

        ret = gpio_pin_configure_dt(&leda5, GPIO_OUTPUT_ACTIVE);

        if (ret < 0) {
                return 0;
        }

while (1) {

                ret = gpio_pin_set_dt(&leda5,1);
                printf("LED 5 ON for 200ms \n");
                k_msleep(DELAY_1);

                ret = gpio_pin_set_dt(&leda5,0);
                printf("LED 5 OFF for 200ms \n");
                k_msleep(DELAY_1);
                if (ret < 0) {
                        return 0;
                }

                ret = gpio_pin_set_dt(&leda5,1);
                printf("LED 5 ON for 500ms \n");
                k_msleep(DELAY_2);

                ret = gpio_pin_set_dt(&leda5,0);
                printf("LED 5 OFF for 500ms \n");
                k_msleep(DELAY_2);
                if (ret < 0) {
                        return 0;
                }

                ret = gpio_pin_set_dt(&leda5,1);
                printf("LED 5 ON for 2sec\n");
                k_msleep(DELAY_3);

                ret = gpio_pin_set_dt(&leda5,0);
                printf("LED 5 OFF for 2sec\n");
                k_msleep(DELAY_3);
                if (ret < 0) {
                        return 0;
                }
        }
        return 0;
}
