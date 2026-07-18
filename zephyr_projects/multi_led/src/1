#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define DELAY_1 1000

/* The devicetree node identifier for the "led0" alias. */
#define LED0_NODE DT_ALIAS(led0)
#define LED6_NODE DT_ALIAS(led6)
#define LED1_NODE DT_ALIAS(led1)


/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
static const struct gpio_dt_spec leda5 = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
static const struct gpio_dt_spec leda6 = GPIO_DT_SPEC_GET(LED6_NODE, gpios);
static const struct gpio_dt_spec leda1 = GPIO_DT_SPEC_GET(LED1_NODE, gpios);


int main(void)
{
        int ret;

        if (!gpio_is_ready_dt(&leda5)) {
                return 0;
        }

	        if (!gpio_is_ready_dt(&leda6)) {
                return 0;
        }

		        if (!gpio_is_ready_dt(&leda1)) {
                return 0;
        }


        ret = gpio_pin_configure_dt(&leda5, GPIO_OUTPUT_ACTIVE);

        if (ret < 0) {
                return 0;
        }
	        ret = gpio_pin_configure_dt(&leda6, GPIO_OUTPUT_ACTIVE);

        if (ret < 0) {
                return 0;
        }
          
	        ret = gpio_pin_configure_dt(&leda1, GPIO_OUTPUT_ACTIVE);

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

		ret = gpio_pin_set_dt(&leda6,1);
                printf("LED 5 ON for 200ms \n");
                k_msleep(DELAY_1);

             
	     ret = gpio_pin_set_dt(&leda6,0);
                printf("LED 5 OFF for 200ms \n");
                k_msleep(DELAY_1);
                if (ret < 0) {
                       return 0;
              }
                     
		ret = gpio_pin_set_dt(&leda1,1);
                printf("LED 5 ON for 200ms \n");
                k_msleep(DELAY_1);

                ret = gpio_pin_set_dt(&leda1,0);
                printf("LED 5 OFF for 200ms \n");
                k_msleep(DELAY_1);
                if (ret < 0) {
                      return 0;
               }
                    

        }
        return 0;
}
