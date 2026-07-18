#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>


/* The devicetree node identifier for the "led2" alias. */
#define LED2_NODE DT_ALIAS(led2)
#define LED0_NODE DT_ALIAS(led0)



/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
static const struct gpio_dt_spec leda2 = GPIO_DT_SPEC_GET(LED2_NODE, gpios);
static const struct gpio_dt_spec leda0 = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

    

int  main(void)
{
	int ret;

	if(!gpio_is_ready_dt(&leda2))
	{
		printf("GPIO pin not ready\n");
		return 0;
	}

	if(!gpio_is_ready_dt(&leda0))
        {
                printf("GPIO pin not ready\n");
                return 0;
        }


	ret = gpio_pin_configure_dt(&leda2,GPIO_OUTPUT_ACTIVE);
        ret = gpio_pin_configure_dt(&leda0,GPIO_OUTPUT_ACTIVE);


	if(ret<0)
	{
		printf("LED configuration failed");
		return 0;
	}

	 if(ret<0)
        {
                printf("LED configuration failed");
                return 0;
        }


	while(1)
	{
		gpio_pin_set_dt(&leda2 ,1);
		gpio_pin_set_dt(&leda0 ,0);
		k_msleep(1000);

		                gpio_pin_set_dt(&leda2 ,0);
                                gpio_pin_set_dt(&leda0 ,1);
				k_msleep(1000);



	}
	
}

          
	


