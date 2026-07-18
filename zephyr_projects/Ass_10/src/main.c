#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <errno.h>

/* The devicetree node identifier for the "led2" alias. */
#define LED2_NODE DT_ALIAS(led2)



/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
static const struct gpio_dt_spec leda2 = GPIO_DT_SPEC_GET(LED2_NODE, gpios);
     

int  main(void)
{
	int ret;

	if(!gpio_is_ready_dt(&leda2))
	{
		printf("GPIO pin not ready\n");
		return -ENODEV;
	}

	ret = gpio_pin_configure_dt(&leda2,GPIO_OUTPUT_ACTIVE);

	if(ret!=0)
	{
		printf("LED configuration failed");
		return ret;
	}

	while(1)
	{
		

		ret = gpio_pin_set_dt(&leda2, 1);

		if(ret!=0)
		{
			printf("led toggle failed\n");
			return ret;
		}
		k_msleep(1000);
	}
	
}

          
	


