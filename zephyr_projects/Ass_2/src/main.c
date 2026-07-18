#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define DELAY_1 1000

/* The devicetree node identifier for the "led0" alias. */
#define LED6_NODE DT_ALIAS(led6)

/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
static const struct gpio_dt_spec leda6 = GPIO_DT_SPEC_GET(LED6_NODE, gpios);

int main(void)
{
        int ret;

        if (!gpio_is_ready_dt(&leda6)) {
                return 0;
        }

        ret = gpio_pin_configure_dt(&leda6, GPIO_OUTPUT_ACTIVE);

        if (ret < 0) {
                return 0;
        }

while (1) {
               for(int i=0;i<5;i++)
	       {
                ret = gpio_pin_set_dt(&leda6,1);
                printf("LED BLINK %d\n",i);
                k_msleep(DELAY_1);
                ret = gpio_pin_set_dt(&leda6,0);
	         k_msleep(DELAY_1);
	    if(i>6)
	    {
		    printf("LED BLINK finshing");

	    }
}
        return 0;

	}
}
