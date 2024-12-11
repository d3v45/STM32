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
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	    char name[50];
	    char message0[]="wh47 sh0u1d I call y0u h4ck3r?";
	    char message2[10000];
	    char answer[10];
	    char message[] = "s0 d0 y0u 4c7u4lly want t0 be a h4rdw4re h4ck3r?";
	    char yes_message[] = "g00d luck 0n y0ur j0urn3y :";
	    char no_message[] = " ¯\\_(ツ)_/¯ no flag then ¯\\_(ツ)_/¯";
	    char thanku_msg[10000];
	    int i;
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
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

	  for (i=0; message0[i]!='\0';i++) {
	  		HAL_UART_Transmit(&huart2, (char*)message0[i], 30, HAL_MAX_DELAY);
	  		fflush(stdout);
	  		HAL_Delay(50000); //delay
	  	}
	  // Wait until a character is received
	    while (__HAL_UART_GET_FLAG(&huart2, UART_FLAG_RXNE) == RESET) {}

	    // Read the received character
	    char ch;
	    HAL_UART_Receive(&huart2, (uint8_t *)&ch, 1, HAL_MAX_DELAY);

	    // Check if it's a newline character
	    if (ch == '\n' || ch == '\r') {
	      name[i] = '\0';  // Add null termination character
	      break;  // Exit the loop
	    }

	    // Store the character in the name buffer
	    name[i] = ch;
	    i++;
	    if (i >= 50) {
	      name[i] = '\0';  // Add null termination character
	      break;  // Exit the loop
	    }
	  	name[strcspn(name, "\n")] = 0; // remove newline character from the end of the name
	  	sprintf(message2, "Here are some wise words by two famous people, %s:\n \n          In the world of electronics, the Joker would say that we're all just a bunch of criminals. We use UART communication protocols to take advantage of a service that's already available without paying for something that should be free. But is it really that simple? \n \n UART, like the exquisite baud of the electronic world, is a tool that we can use to communicate without bias or prejudice. It's a protocol that exists without skin color, country or religious affiliation. We use it to seek knowledge and to connect with one another in new and exciting ways.\n \n But just like the Joker, we're often accused of being criminals simply for exploring the limits of this protocol. We're called hackers, or worse, simply because we want to know what's possible. \n \n The truth is, UART communication protocols are a powerful tool that can be used for both good and bad. Just like any technology, it's up to us to decide how we use it. Will we use it to develop life-saving medical devices or to create new opportunities for education and communication? Or will we use it to perpetrate crimes and cause chaos?\n \n As the Joker said, 'It's not about money. It's about sending a message.' In the world of UART, the message we send is up to us. We can choose to use this protocol to bring people together or to tear them apart. We can use it to share knowledge and to build a better future, or we can use it to spread hate and destruction.\n \n So let's take a cue from the Joker and embrace the madness of UART communication protocols. Let's use them to push the limits of what's possible and to create a world that's more connected and more inclusive. And let's do it all with a smile on our faces, just like the Joker would have wanted.\n \n ",name);
	  	for (i=0; message2[i]!='\0';i++) {
	  		putchar(message2[i]);
	  		fflush(stdout);
	  		HAL_Delay(10000); //delay
	  	}



	      while (1) {
	          // Print message
	          for (i = 0; message[i] != '\0'; i++) {
	              putchar(message[i]);
	              fflush(stdout);
	              HAL_Delay(50000); //delay
	          }

	          // Get answer from user
	          // Wait until a character is received
	           while (__HAL_UART_GET_FLAG(&huart2, UART_FLAG_RXNE) == RESET) {}

	           // Read the received character
	           char ch;
	           HAL_UART_Receive(&huart2, (uint8_t *)&ch, 1, HAL_MAX_DELAY);

	           // Check if it's a newline character or the buffer is full
	           if (ch == '\n' || ch == '\r' || strlen(answer) >= 10) {
	             answer[strlen(answer)] = '\0';  // Add null termination character
	             break;  // Exit the loop
	           }

	           // Store the character in the answer buffer
	           strncat(answer, &ch, 1);

	          // Check if answer is yes or ya
	          if (strcmp(answer, "yes\n") == 0 || strcmp(answer, "ya\n") == 0) {
	              // Print yes message
	              for (i = 0; yes_message[i] != '\0'; i++) {
	                  putchar(yes_message[i]);
	                  fflush(stdout);
	                  HAL_Delay(50000); //delay
	              }

	              // Loop until the user types "thanks" or "thankyou"
	              while (1) {
	            	  // Wait until a character is received
	            	   while (__HAL_UART_GET_FLAG(&huart2, UART_FLAG_RXNE) == RESET) {}

	            	   // Read the received character
	            	   char ch;
	            	   HAL_UART_Receive(&huart2, (uint8_t *)&ch, 1, HAL_MAX_DELAY);

	            	   // Check if it's a newline character or the buffer is full
	            	   if (ch == '\n' || ch == '\r' || strlen(answer) >= 10) {
	            	     answer[strlen(answer)] = '\0';  // Add null termination character
	            	     break;  // Exit the loop
	            	   }

	            	   // Store the character in the answer buffer
	            	   strncat(answer, &ch, 1);

	                  if (strcmp(answer, "thankyou\n") == 0 || strcmp(answer, "thanks\n") == 0) {
	                      // Print thanku_msg
	                      sprintf(thanku_msg,"\n %s, y0u w1ll n33d 7h15 t0 c0nt1nu3 y0ur j0urn3y\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n  _____                             _      _____    _____\n /  __ \\                           | |    |_   _|  |_   _|\n | /  \\/ ___  _ __ ___  _ __   __ _| |_ _ __| |  ___ | |\n | |    / _ \\| '_ ` _ \\| '_ \\ / _` | __| '__| | / _ \\| |\n | \\__/\\ (_) | | | | | | |_) | (_| | |_| | _| || (_) | |\n  \\____/\\___/|_| |_| |_| .__/ \\__,_|\\__|_| \\___/\\___/\\_/\n                       | |\n                       |_|\n \n compatrIoT{w3lc0m3_70_7h3_w0rld_0f_h4rdw4r3_h4ck1ng}\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n",name);
	                      for (i = 0; thanku_msg[i] != '\0'; i++) {
	                          putchar(thanku_msg[i]);
	                          fflush(stdout);
	                          HAL_Delay(10000); //delay
	                      }
	                      break;
	                  } else {
	                      // Repeat the question
	                      for (i = 0; yes_message[i] != '\0'; i++) {
	                          putchar(yes_message[i]);
	                          fflush(stdout);
	                          HAL_Delay(50000); //delay
	                      }
	                  }
	              }

	              break;

	          } else if (strcmp(answer, "no\n") == 0) {
	              // Print no message
	              for (i = 0; no_message[i] != '\0'; i++) {
	                  putchar(no_message[i]);
	                  fflush(stdout);
	                  HAL_Delay(50000); //delay
	              }
	              break;

	          } else {
	              // If the answer is invalid, repeat the question
	              continue;
	          }


	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

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
