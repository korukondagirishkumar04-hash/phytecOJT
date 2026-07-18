#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>


/* The devicetree node identifier for the "led2" alias. */
#define LED2_NODE DT_ALIAS(led2)



/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
static const struct gpio_dt_spec leda2 = GPIO_DT_SPEC_GET(LED2_NODE, gpios);
     

int pattern[] = {1,0,1,1,0,0,1};

int  main(void)
{
	int ret;

	if(!gpio_is_ready_dt(&leda2))
	{
		printf("GPIO pin not ready\n");
		return 0;
	}

	ret = gpio_pin_configure_dt(&leda2,GPIO_OUTPUT_ACTIVE);

	if(ret<0)
	{
		printf("LED configuration failed");
		return 0;
	}

	while(1)
	{
		for(int i=0;i < sizeof(pattern)/sizeof(pattern[0]);i++)
		{
			gpio_pin_set_dt(&leda2,pattern[i]);
			printf("pattern:%d\n",pattern[i]);

			k_msleep(1000);
		}


		printf("pattern completed\n");
		k_msleep(1000);
	}
	
}

          
	


