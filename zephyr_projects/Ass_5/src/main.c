#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define BLINK_TIME 100
#define PAUSE_TIME 800

/* The devicetree node identifier for the "led6" alias. */
#define LED6_NODE DT_ALIAS(led6)
/* The devicetree node identifier for the "led1" alias. */
#define LED1_NODE DT_ALIAS(led1)


/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
static const struct gpio_dt_spec leda6 = GPIO_DT_SPEC_GET(LED6_NODE, gpios);
static const struct gpio_dt_spec leda1 = GPIO_DT_SPEC_GET(LED1_NODE, gpios);


int main(void)
{
        int ret;

        if (!gpio_is_ready_dt(&leda6)) {
                return 0;
        }
         
	 if (!gpio_is_ready_dt(&leda1)) {
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
                ret = gpio_pin_set_dt(&leda6,1);
                printf("LED BLINK\n ");
                k_msleep(100);
                ret = gpio_pin_set_dt(&leda6,0);
	         k_msleep(100);
		 printf("LED OFF\n");

		  ret = gpio_pin_set_dt(&leda1,1);
                printf("LED BLINK\n ");
                k_msleep(100);
                ret = gpio_pin_set_dt(&leda1,0);
                 k_msleep(100);
                 printf("LED OFF\n");
                         
	      printf("PAUSE\n");
	      k_msleep(800);

}
        return 0;

	}
