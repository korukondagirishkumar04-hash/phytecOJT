#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/devicetree.h>
#include <stdio.h>
// 1. Corrected macro check for the existence of the 'led0' alias
#if !DT_HAS_ALIAS(led0)
   # error "Missing device tree alias  led0,add it in device tree"
#endif
//2.Get the led device from the device tree using the led0 alias.
static const struct gpio_dt_spec led =GPIO_DT_SPEC_GET(DT_ALIAS(led0),gpios);
int main()
{
        bool led_state =false;
        //3.verify the device is ready with device is ready.
        if(!gpio_is_ready_dt(&led))
        {
                return 0;
        }
        //4.Configure the led pin as a GPIO Output with inital  state as off
         if(gpio_pin_configure_dt(&led,GPIO_OUTPUT_INACTIVE)<0)
         {
                 return 0;
         }
         //5.Loop for toggle the led
         while(1)
         {
                 led_state=!led_state;
                 if(gpio_pin_toggle_dt(&led)<0)
                 {
                         return 0;
                 }
                 printf("Led STATE:%s\n\r",led_state ? "ON":"OFF");
                 k_msleep(1000);
         }
         return 0;
}
