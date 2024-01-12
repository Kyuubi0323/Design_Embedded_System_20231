/*
 * common.c
 *
 *  Created on: Jan 9, 2024
 *      Author: Kyuubi
 */

#include "common.h"
#include <math.h>
#include <stdio.h>
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
