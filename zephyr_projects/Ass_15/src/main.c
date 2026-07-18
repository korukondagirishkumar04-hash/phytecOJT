#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>


/* The devicetree node identifier for the "led2" alias. */
#define LED2_NODE DT_ALIAS(led2)
#define LED0_NODE DT_ALIAS(led0)
#define LED1_NODE DT_ALIAS(led1)
#define LED6_NODE DT_ALIAS(led6)

/* * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
static const struct gpio_dt_spec leda2 = GPIO_DT_SPEC_GET(LED2_NODE, gpios);
static const struct gpio_dt_spec leda0 = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
static const struct gpio_dt_spec leda1 = GPIO_DT_SPEC_GET(LED1_NODE, gpios);
static const struct gpio_dt_spec leda6 = GPIO_DT_SPEC_GET(LED6_NODE, gpios);
    

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

        if(!gpio_is_ready_dt(&leda1))
        {
                printf("GPIO pin not ready\n");
                return 0;
        }

        if(!gpio_is_ready_dt(&leda6))
        {
                printf("GPIO pin not ready\n");
                return 0;
        }


  	ret = gpio_pin_configure_dt(&leda2,GPIO_OUTPUT_ACTIVE);
        ret = gpio_pin_configure_dt(&leda0,GPIO_OUTPUT_ACTIVE);

        ret = gpio_pin_configure_dt(&leda1,GPIO_OUTPUT_ACTIVE);
        ret = gpio_pin_configure_dt(&leda6,GPIO_OUTPUT_ACTIVE);


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
		
           for (int i = 0; i < 4; i++)
		{
             gpio_pin_set_dt(&leds[i], 1);
               k_msleep(200);
             gpio_pin_set_dt(&leds[i], 0);
		}

                 /* Backward direction */
               for (int i = 2; i > 0; i--)
	       {
                gpio_pin_set_dt(&leds[i], 1);
                 k_msleep(200);
                gpio_pin_set_dt(&leds[i], 0);
                }
}
	
	
}

          
	


