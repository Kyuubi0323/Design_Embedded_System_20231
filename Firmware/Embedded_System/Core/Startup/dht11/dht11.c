

/************** MAKE CHANGES HERE ********************/
#include "main.h"
#include "stm32f4xx_hal.h"
#include "dht11.h"
#include "cmsis_os.h"
#include "FreeRTOSConfig.h"
#define TYPE_DHT11    // define according to your sensor
//#define TYPE_DHT22


#define DHT_PORT GPIOC
#define DHT_PIN GPIO_PIN_14




/*******************************************     NO CHANGES AFTER THIS LINE      ****************************************************/

uint8_t Rh_byte1, Rh_byte2, Temp_byte1, Temp_byte2;
uint16_t SUM; uint8_t Presence = 0;
extern TIM_HandleTypeDef htim11;


//void Set_Pin_Output (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
//{
//	GPIO_InitTypeDef GPIO_InitStruct = {0};
//	GPIO_InitStruct.Pin = GPIO_Pin;
//	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//	HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
//}
//
//void Set_Pin_Input (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
//{
//	GPIO_InitTypeDef GPIO_InitStruct = {0};
//	GPIO_InitStruct.Pin = GPIO_Pin;
//	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
//	GPIO_InitStruct.Pull = GPIO_NOPULL;
//	HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
//}
void delay_us(uint16_t us)
{
	__HAL_TIM_SET_COUNTER(&htim11, 0);
	while (__HAL_TIM_GET_COUNTER(&htim11) < us);
}

void DHT_Start (void)
{

//	Set_Pin_Output (DHT_PORT, DHT_PIN);  // set the pin as output
	HAL_GPIO_WritePin (DHT_PORT, DHT_PIN, 0);   // pull the pin low
	osDelay(18);
    HAL_GPIO_WritePin (DHT_PORT, DHT_PIN, 1);   // pull the pin high
    osDelay(1);   // wait for 30us
//	Set_Pin_Input(DHT_PORT, DHT_PIN);    // set as input
}

uint8_t DHT_Check_Response (void)
{
	uint8_t Response = 0;
	osDelay(1);
	if (!(HAL_GPIO_ReadPin (DHT_PORT, DHT_PIN)))
	{
//		delay_us (80);
		if ((HAL_GPIO_ReadPin (DHT_PORT, DHT_PIN))) Response = 1;
		else Response = -1;
	}
	while ((HAL_GPIO_ReadPin (DHT_PORT, DHT_PIN)));   // wait for the pin to go low

	return Response;
}

uint8_t DHT_Read (void)
{
	uint8_t i,j;
	for (j=0;j<8;j++)
	{
		while (!(HAL_GPIO_ReadPin (DHT_PORT, DHT_PIN)));   // wait for the pin to go high
		delay_us (40);   // wait for 40 us
		if (!(HAL_GPIO_ReadPin (DHT_PORT, DHT_PIN)))   // if the pin is low
		{
			i&= ~(1<<(7-j));   // write 0
		}
		else i|= (1<<(7-j));  // if the pin is high, write 1
		while ((HAL_GPIO_ReadPin (DHT_PORT, DHT_PIN)));  // wait for the pin to go low
	}
	return i;
}



void DHT_GetData (DHT_DataTypedef *DHT_Data)
{
    DHT_Start ();
	Presence = DHT_Check_Response ();
	Rh_byte1 = DHT_Read ();
	Rh_byte2 = DHT_Read ();
	Temp_byte1 = DHT_Read ();
	Temp_byte2 = DHT_Read ();
	SUM = DHT_Read();

	if (SUM == (Rh_byte1+Rh_byte2+Temp_byte1+Temp_byte2))
	{
		#if defined(TYPE_DHT11)
			DHT_Data->Temperature = Temp_byte1;
			DHT_Data->Humidity = Rh_byte1;
		#endif

		#if defined(TYPE_DHT22)
			DHT_Data->Temperature = ((Temp_byte1<<8)|Temp_byte2);
			DHT_Data->Humidity = ((Rh_byte1<<8)|Rh_byte2);
		#endif
	}
}


