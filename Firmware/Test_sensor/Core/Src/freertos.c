/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "i2c.h"
#include "max30102.h"
#include "usart.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

char *TxBuffer;
char str[80];
/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for Sensor */
osThreadId_t SensorHandle;
const osThreadAttr_t Sensor_attributes = {
  .name = "Sensor",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for Basic_timer */
osTimerId_t Basic_timerHandle;
const osTimerAttr_t Basic_timer_attributes = {
  .name = "Basic_timer"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void Sensor_task(void *argument);
void Timer_Callback(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* Create the timer(s) */
  /* creation of Basic_timer */
  Basic_timerHandle = osTimerNew(Timer_Callback, osTimerPeriodic, NULL, &Basic_timer_attributes);

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of Sensor */
  SensorHandle = osThreadNew(Sensor_task, NULL, &Sensor_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
	TxBuffer = "Default_here\r\n";
  /* Infinite loop */
  for(;;)
  {

    osDelay(1000);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_Sensor_task */
/**
* @brief Function implementing the Sensor thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Sensor_task */
void Sensor_task(void *argument)
{
  /* USER CODE BEGIN Sensor_task */
	max30102_init();
  /* Infinite loop */
  for(;;)
  {
	  HAL_UART_Transmit(&huart1, (uint8_t *) "oke\r\n", 5, 100);
	  if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12) == GPIO_PIN_RESET)
		  {
			  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
			  max30102_cal();
			  uint8_t spo2 = max30102_getSpO2();
//			  uint8_t spo2 = max30102_getStatus();
			  uint8_t heartRate = max30102_getHeartRate();
+
			  HAL_UART_Transmit(&huart1, "gotheart\r\n", 10, 500 );
			  sprintf(str, "bpm %d spo2 %d\r\n", heartRate, spo2); //

			  HAL_UART_Transmit(&huart1, (uint8_t*)str, strlen(str), 500 );
			  HAL_UART_Transmit(&huart1, "done\r\n", 6, 500 );
	      }
    osDelay(2000);
  }
  /* USER CODE END Sensor_task */
}

/* Timer_Callback function */
void Timer_Callback(void *argument)
{
  /* USER CODE BEGIN Timer_Callback */

  /* USER CODE END Timer_Callback */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

