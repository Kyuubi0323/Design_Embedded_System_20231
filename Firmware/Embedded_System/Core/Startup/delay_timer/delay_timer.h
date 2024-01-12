/*
 * delay_timer.h
 *
 *  Created on: Jan 8, 2024
 *      Author: Admin
 */
// set clock as 84Mhz --> prescale = 84 - 1; ARR = 0xffff - 1;
#ifndef STARTUP_DELAY_TIMER_DELAY_TIMER_H_
#define STARTUP_DELAY_TIMER_DELAY_TIMER_H_

#include "stm32f4xx_hal.h"
void DELAY_TIM_Init(TIM_HandleTypeDef *htim);
void DELAY_TIM_Us(TIM_HandleTypeDef *htim, uint16_t time);
void DELAY_TIM_Ms(TIM_HandleTypeDef *htim, uint16_t Time);

#endif /* STARTUP_DELAY_TIMER_DELAY_TIMER_H_ */
