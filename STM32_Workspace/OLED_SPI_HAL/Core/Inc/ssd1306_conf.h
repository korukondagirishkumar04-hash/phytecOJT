#ifndef __SSD1306_CONF_H__
#define __SSD1306_CONF_H__
// Choose interface — SPI only
#define SSD1306_USE_SPI
// Your SPI handle
#define SSD1306_SPI_PORT    hspi2
// DC and RES GPIO
#define SSD1306_DC_Port     GPIOB
#define SSD1306_DC_Pin      GPIO_PIN_1
#define SSD1306_RES_Port    GPIOB
#define SSD1306_RES_Pin     GPIO_PIN_0
// Display resolution
#define SSD1306_WIDTH       128
#define SSD1306_HEIGHT      64
#define SSD1306_INCLUDE_FONT_6x8
#define SSD1306_INCLUDE_FONT_7x10
#define SSD1306_INCLUDE_FONT_11x18
#define SSD1306_INCLUDE_FONT_16x26
// No CS pin on your module, so leave CS undefined or comment it out
// #define SSD1306_CS_Port
// #define SSD1306_CS_Pin
#endif /* __SSD1306_CONF_H__ */
