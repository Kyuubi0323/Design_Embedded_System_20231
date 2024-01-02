/* vim: set ai et ts=4 sw=4: */
#ifndef __ILI9341_TOUCH_H__
#define __ILI9341_TOUCH_H__

#include <stdbool.h>

/*** Redefine if necessary ***/

// Warning! Use SPI bus with < 1.3 Mbit speed, better ~650 Kbit to be save.
#define ILI9341_TOUCH_SPI_PORT hspi1
extern SPI_HandleTypeDef ILI9341_TOUCH_SPI_PORT;

#define ILI9341_TOUCH_IRQ_Pin       GPIO_PIN_8
#define ILI9341_TOUCH_IRQ_GPIO_Port GPIOA
#define ILI9341_TOUCH_CS_Pin        GPIO_PIN_12
#define ILI9341_TOUCH_CS_GPIO_Port  GPIOA

// change depending on screen orientation
#define ILI9341_TOUCH_SCALE_X 240
#define ILI9341_TOUCH_SCALE_Y 320

// to calibrate uncomment UART_Printf line in ili9341_touch.c
#define ILI9341_TOUCH_MIN_RAW_X 1500
#define ILI9341_TOUCH_MAX_RAW_X 31000
#define ILI9341_TOUCH_MIN_RAW_Y 2000
#define ILI9341_TOUCH_MAX_RAW_Y 31500

typedef struct
{
	uint16_t pos_x;
	uint16_t pos_y;

	uint16_t shape_r;
	uint16_t shape_w;
	uint16_t shape_h;

	uint16_t color;

	bool state;
	//pFunc_t pHandlerFunc;
} myButton_t;
// call before initializing any SPI devices
void ILI9341_TouchUnselect();

bool ILI9341_TouchPressed();
bool ILI9341_TouchGetCoordinates(uint16_t* x, uint16_t* y);

#endif // __ILI9341_TOUCH_H__
