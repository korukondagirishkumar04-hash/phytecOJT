#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>



/* The devicetree node identifier for the "led2" alias. */
#define LED0_NODE DT_ALIAS(led0)



/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
static const struct gpio_dt_spec leda0 = GPIO_DT_SPEC_GET(LED0_NODE, gpios);




int main(void)
{
        int ret;
         
	 if (!gpio_is_ready_dt(&leda0)) {
                return 0;
        }
           
	       ret = gpio_pin_configure_dt(&leda0, GPIO_OUTPUT_ACTIVE);

        if (ret < 0) {
                return 0;
        }

while (1) {  

	gpio_pin_set_dt(&leda0,1);
	printf("led on\n");
	k_msleep(500);
	gpio_pin_set_dt(&leda0,0);
	printf("led off\n");
	k_msleep(500);


	}
}
