#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define DOT_TIME 200
#define DASH_TIME 600
#define WORD_GAP 2000
#define LETTER_GAP 600


/* The devicetree node identifier for the "led2" alias. */
#define LED2_NODE DT_ALIAS(led2)



/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
static const struct gpio_dt_spec leda2 = GPIO_DT_SPEC_GET(LED2_NODE, gpios);

void dot(void)
{
    	gpio_pin_set_dt(&leda2,1);
	printf(".");
   k_msleep(200);
   gpio_pin_set_dt(&leda2,0);
   k_msleep(200);

}

void dash(void)
{
     gpio_pin_set_dt(&leda2,1);
     printf("-");
      k_msleep(600);
      gpio_pin_set_dt(&leda2,0);
      k_msleep(600);

}


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

	/* G --*/
       
	dash();
	dash();
	dot();
         printf("G\n");
	k_msleep(600);

	/* I*/
       
	dot();
	dot();
	printf("I\n");

	k_msleep(600);

	/* R*/
       


	dot();
	dash();
	dot();
	printf("R\n");

	k_msleep(600);

	/* I */
        


	dot();
	dot();
      printf("I\n");
      k_msleep(600);
	/* s */
             


	dot();
	dot();
	dot();
	printf("S\n");
	k_msleep(600);

	/* H */
   

	dot();
	dot();
	dot();
	dot();
        printf("H\n");
        printf("Named Displayed in morse\n");
	k_msleep(2000);
}
        return 0;

	}
