 #include<stm32f4xx.h>
#define RS 0
#define RW 1
#define EN 4

void delay(void){
	for(volatile int i=0;i<5000;i++);
}
void LCD_Enable(void){
	GPIOA->ODR|=(1<<EN);   //EN=1
	delay();
	GPIOA->ODR&=~(1<<EN);  //EN=0
	delay();
}

void LCD_Command(uint8_t cmd){
	GPIOA->ODR&=~(1<<RS);   //RS=0
	GPIOA->ODR&=~(1<<RW);   //RW=0

	GPIOC->ODR&=~0x00FF;    //CLEAR PC0-PC7
	GPIOC->ODR|=cmd;
	LCD_Enable();
}
void LCD_Data(uint8_t data){
	GPIOA->ODR|=(1<<RS);    //RS=1
	GPIOA->ODR&=~(1<<RW);   //RW=0

	GPIOC->ODR&=~0x00FF;    //CLEAR PC0-PC7
	GPIOC->ODR|=data;
	LCD_Enable();
}
void LCD_String(char *str){
	while(*str){
		LCD_Data(*str++);
	}
}
void LCD_Init(void){
	delay();
	LCD_Command(0x38);   //8 BIT MODE
	LCD_Command(0x0c);   //DISPLAY ON.CURSOR OFF
	LCD_Command(0x06);   //AUTO INCREMNRT
	LCD_Command(0x01);   //CLEAR DISPLAY
	delay();
}
int main(void){
	RCC->AHB1ENR|=(1<<0);
	RCC->AHB1ENR|=(1<<2);

	//PA0,PA1,PA4 AS OUTPUT

	GPIOA->MODER&=~((3<<(0*2))|(3<<(1*2))|(3<<(4*2)));
	GPIOA->MODER|=((1<<(0*2))|(1<<(1*2))|(1<<(4*2)));

	//PC0 - PC7 AS OUTPUT
	 GPIOC->MODER&=~0x0000FFFF;
	 GPIOC->MODER|=0x00005555;

	 LCD_Init();
	 LCD_Command(0x80+0); //LINE 1
	 LCD_String("LINE 1");
	 LCD_Command(0xC0+0); //LINE 2
	 LCD_String("LINE 2");
	 LCD_Command(0x94+0); //LINE 3
	 LCD_String("LINE 3");
	 LCD_Command(0x80+0); //LINE 4
	 LCD_String("LINE 4");
	 while(1){

	 }

}
