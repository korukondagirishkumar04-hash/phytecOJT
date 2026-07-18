#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define BLINK_TIME 100
#define PAUSE_TIME 500

/* The devicetree node identifier for the "led2" alias. */
#define LED2_NODE DT_ALIAS(led2)



/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
static const struct gpio_dt_spec leda2 = GPIO_DT_SPEC_GET(LED2_NODE, gpios);


int main(void)
{
        int ret;
         
	 if (!gpio_is_ready_dt(&leda2)) {
                return 0;
        }
           
	       ret = gpio_pin_configure_dt(&leda2, GPIO_OUTPUT_ACTIVE);

        if (ret < 0) {
                return 0;
        }

while (1) {  
	for(int count=1;count<=10;count++)
	{
		   printf("count %d\n",count);


	           for(int blinky=1;blinky<=count;blinky++)
		   {
			   printf(" blink %d\n",blinky);
	            ret = gpio_pin_set_dt(&leda2,1);
                     k_msleep(100);
                       
		    ret = gpio_pin_set_dt(&leda2,0);
		    k_msleep(100);
		   }
	}

	printf("pause\n");
	k_msleep(500);


}
        return 0;

	}
