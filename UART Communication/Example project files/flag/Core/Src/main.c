/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
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
UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void lab3_uart(){
	uint8_t flag[100] = "bi0s";
	  uint8_t ans[100]= "";
	  uint8_t received_char;
    uint8_t exit[100]="x";
    uint8_t restart[100]="r";
    uint8_t input[100]="";
    uint8_t input2;

    while (1) {
    		HAL_UART_Transmit(&huart1, (char *)"Enter the flag: ", strlen("Enter the flag: "), HAL_MAX_DELAY);

    		int i = 0;
    		do {
    			HAL_UART_Receive(&huart1, (uint8_t *) &received_char, 1, HAL_MAX_DELAY);
    			if (received_char != '\n') {
    				ans[i] = received_char;
    				i++;
    			}
    		} while (received_char != '\n' && i < 100	);
    		ans[i] = '\0';

    		if (strcmp(flag,ans) == 0) {
    			HAL_UART_Transmit(&huart1, (uint8_t *)"Yes, you found the flag\n", 25, HAL_MAX_DELAY);
    			HAL_Delay(2000);

    			while (1) {
    				HAL_UART_Transmit(&huart1, (char *)"Enter 'x' to quit or 'r' to restart\n",38 , HAL_MAX_DELAY);
    				int i = 0;
    				do {
    					HAL_UART_Receive(&huart1, (uint8_t *) &input2, 1, HAL_MAX_DELAY);
    					if (input2 != '\n') {
    						input[i] = input2;
    						i++;
    					}
    				} while (input2 != '\n' && i < 100	);
    				input[i] = '\0';

    				if (strcmp(input,exit)==0) {
    					HAL_UART_Transmit(&huart1, "Exiting...\n", 12, 1000);
    					__BKPT(0);
    				}
    				else if (strcmp(input,restart)==0) {
    					HAL_UART_Transmit(&huart1,"Restarting...\n", 15, 1000);
    					break;
    				}
    				else {
    					HAL_UART_Transmit(&huart1, "Invalid input, please try again.\n", 34, 1000);
    				}
    			}
    		} else {
    			HAL_UART_Transmit(&huart1, (uint8_t *)"Incorrect flag\n", 15, HAL_MAX_DELAY);

    			while (1) {
    				HAL_UART_Transmit(&huart1, (char *)"Enter 'x' to quit or 'r' to restart\n",38 , HAL_MAX_DELAY);
    				int i = 0;
    				do {
    					HAL_UART_Receive(&huart1, (uint8_t *) &input2, 1, HAL_MAX_DELAY);
    					if (input2 != '\n') {
    						input[i] = input2;
    						i++;
    					}
    				} while (input2 != '\n' && i < 100	);
    				input[i] = '\0';

    				if (strcmp(input,exit)==0) {
    					HAL_UART_Transmit(&huart1, "Exiting...\n", 12, 2000);
    					__BKPT(0);
    				}
    				else if (strcmp(input,restart)==0) {
    					HAL_UART_Transmit(&huart1,"Restarting...\n", 15, 1000);
    					break;

	      	     }else{
	      	    	 HAL_UART_Transmit(&huart1, "Invalid input, please try again.\n", 34, 1000);

	      	     }
    			}
    		}
    }
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	  /* USER CODE BEGIN 1 */


  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  lab3_uart();


  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_9B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_EVEN;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
