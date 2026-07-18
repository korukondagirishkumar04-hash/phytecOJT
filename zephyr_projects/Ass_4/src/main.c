#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define DOT_TIME 200
#define DASH_TIME 600

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

               
	printf("S\n");
	for(int i=0;i<3;i++)
	       {
                ret = gpio_pin_set_dt(&leda6,1);
                printf("LED BLINK ON %d\n",i+1);
                k_msleep(200);
                ret = gpio_pin_set_dt(&leda6,0);
	         k_msleep(200);
		 printf("LED OFF%d\n",i+1);

	   
}

            printf("O\n");
                  for(int i=0;i<3;i++)
               {
                ret = gpio_pin_set_dt(&leda6,1);
                printf("LED BLINK ON %d\n",i+1);
                k_msleep(600);
                ret = gpio_pin_set_dt(&leda6,0);
                 k_msleep(200);
               printf("LED OFF %d\n",i+1);
                         

}
               printf("S\n");  
                      for(int i=0;i<3;i++)
               {
                ret = gpio_pin_set_dt(&leda6,1);
                printf("LED BLINK ON  %d\n",i+1);
                k_msleep(200);
                ret = gpio_pin_set_dt(&leda6,0);
                 k_msleep(200);
                printf("LED OFF %d\n",i+1);


}
  
        

	}
}

