/*
 * common.c
 *
 *  Created on: Jan 9, 2024
 *      Author: Kyuubi
 */

#include "common.h"
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
// Converts a floating-point/double number to a string.
void ftoa(float n, char* res, int afterpoint)
{
    // Extract integer part
    int ipart = (int)n;
    // Extract floating part
    float fpart = n - (float)ipart;
    // convert integer part to string
    int i = intToStr(ipart, res, 0);
    // check for display option after point
    if (afterpoint != 0)
    {
        res[i] = '.'; // add dot
        fpart = fpart * pow(10, afterpoint);
        intToStr((int)fpart, res + i + 1, afterpoint);
    }
}

int intToStr(int x, char str[], int d)
{
    int i = 0;
    if (x == 0)
    {
        str[i++] = '0';
    }
    else
    {
        while (x)
        {
            str[i++] = (x % 10) + '0';
            x = x / 10;
        }
    }

    // If number of digits required is more, then
    // add 0s at the beginning
    while (i < d)
        str[i++] = '0';

    reverse(str, i);
    str[i] = '\0';
    return i;
}

void reverse(char* str, int len)
{
    int i = 0, j = len - 1, temp;
    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}
static uint8_t rx_debug = 0;
bool isNaize = false;

void Debug_Init(void)
{
    HAL_UART_Receive_IT(UART_DEBUG, &rx_debug, 1);
}

void debug_callback(void)
{
    if(rx_debug == '^')
    {
        HAL_NVIC_SystemReset();
    }
    else if (rx_debug == 'F')
    {
        isNaize = !isNaize;
    }
    HAL_UART_Receive_IT(UART_DEBUG, &rx_debug, 1);
}

#if DEBUG ==1
void vprint(const char *fmt, va_list argp)
{
    char string[200];
    if(0 < vsprintf(string, fmt, argp)) // build string
    {
        HAL_UART_Transmit(UART_DEBUG, (uint8_t*)string, strlen(string), 100); // send message via UART
    }
}

/**
    * @brief custom printf() function
    *
    * @param fmt
    * @param ...
*/
void logPC(const char *fmt, ...)
{
    va_list argp;
    va_start(argp, fmt);
    vprint(fmt, argp);
    va_end(argp);
}
#else
void logPC(const char *fmt, ...)
{
    UNUSED(fmt);
}
#endif
