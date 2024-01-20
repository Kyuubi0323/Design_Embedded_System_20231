/*
 * common.h
 *
 *  Created on: Jan 9, 2024
 *      Author: Kyuubi
 */
#include <stdio.h>
#include "usart.h"
#ifndef STARTUP_COMMON_COMMON_H_
#define STARTUP_COMMON_COMMON_H_

#define UART_DEBUG  &huart2

#define DEBUG   1
#define PLOT    0

void ftoa(float n, char *res, int afterpoint);

int intToStr(int x, char str[], int d);

void reverse(char* str, int len);

void Debug_Init(void);

void debug_callback(void);

void logPC(const char *fmt, ...);

#endif /* STARTUP_COMMON_COMMON_H_ */
