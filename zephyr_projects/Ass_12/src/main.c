#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>


/* The devicetree node identifier for the "led0" alias. */
#define LED0_NODE DT_ALIAS(led0)



/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
static const struct gpio_dt_spec leda0 = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
     
typedef enum
{
	INIT,
	led_on,
	led_off,
	delay,
}

state_t;


int  main(void)
{
	



	if(!gpio_is_ready_dt(&leda0))
	{
		printf("GPIO PIN not ready\n");
		return 0;
	}

	if(gpio_pin_configure_dt(&leda0,GPIO_OUTPUT_ACTIVE) <0)
	{
		return 0;
	}

	state_t state = INIT;
	while(1)
	{
		switch(state)
		{
			case INIT:
			printf("initilization complete\n");
			state = led_on;
			break;

			case led_on:
			gpio_pin_set_dt(&leda0,1);
			printf("LED ON\n");
			state = delay;
			break;


			case led_off:
			gpio_pin_set_dt(&leda0,0);
			printf("LED OFF\n");
			state = delay;
			break;

			case delay:
				k_msleep(1000);
				if(gpio_pin_get_dt(&leda0))
				{
					state = led_off;
				}
				else
				{
					state = led_on;
				}
				break;	
		}


	}
	
}

          
	


