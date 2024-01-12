/*
 * dht11.h
 *
 *  Created on: Jan 8, 2024
 *      Author: Admin
 */

#ifndef INC_DHT11_H_
#define INC_DHT11_H_

typedef struct
{
	float Temperature;
	float Humidity;
}DHT_DataTypedef;


void DHT_GetData (DHT_DataTypedef *DHT_Data);


#endif /* INC_DHT11_H_ */
