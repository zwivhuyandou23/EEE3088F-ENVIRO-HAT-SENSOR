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
#include "string.h"
#include "stm32f0xx_hal.h"
#include <stdio.h>
#include "eeprom_lib.h"
#include "temp_sensor_lib.h"
#include "lcd_stm32f0.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define DELAY 250
#define SW0 GPIO_IDR_0
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC_Init(void);
//static void MX_USART1_UART_Init(void);

/* USER CODE BEGIN PFP */
void init_usart(void);
static uint32_t check_for_eeprom_magic(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

<<<<<<< HEAD

=======
uint32_t adcValue;
uint8_t i, j, Loop = 0;
>>>>>>> 1e31e118fe8bf7d21dbed644b77001b693547427
//uint8_t *adcPointer = &adcValue;


	char str[60] = { 0 }; //Useful buffer for printing to UART
  	

	uint16_t EEPROM_DEVICE_ADDR = 0;
  //    uint16_t EEPROM_DEVICE_ADDR = 0b00001010; //Address of EEPROM device on SPI bus
      //uint16_t EEPROM_DEVICE_ADDR = 0xDE;
     // uint16_t EEPROM_DEVICE_ADDR = 0xAD;
      //uint16_t EEPROM_DEVICE_ADDR = 0xBA;
      //uint16_t EEPROM_DEVICE_ADDR = 0xBE;
     // uint16_t EEPROM_DEVICE_ADDR = 0;
    	uint8_t temperature  ; //run time variable containing temperature values; sStarting value to write to memory, could be any 8bit value
    	
      uint8_t adcValue;	//run time data for the ADC to be stored in the variable


      uint8_t tempEEpromRead, adcValueEEpromRead ;

      char strAdc[100];
       char strTemp[100];
       char strTempRead[100];
	   char strAdcRead[100];


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
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
  MX_ADC_Init();
  //MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
<<<<<<< HEAD
  
  uint32_t memo;
  memo =  check_for_eeprom_magic();
   HAL_ADC_Start (&hadc);
   temp_sensor_init_iic();
   eeprom_init_spi();
   init_usart();
   lcd_init(); // set up LCD lines and send initialisation commands
    lcd_command(LCD_CLEAR_DISPLAY);
=======
  // MX_I2C1_Init();
>>>>>>> 1e31e118fe8bf7d21dbed644b77001b693547427


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
    	



        	  //eeprom_write_to_address(EEPROM_DEVICE_ADDR, temperature );
      
    	//debugPrintln(&huart1, "Hello, this is STMF0 Discovery board: ");


 uint8_t data[255] ;
  while (1)
  {
<<<<<<< HEAD

	// lcd_string("Zwivhuya Ndou");
	          	   // go to lower line

	  uint8_t count;
	  while((GPIOA->IDR & SW0)!=0){
		  HAL_ADC_Start (&hadc);
		  temperature  = temp_sensor_read();

		  data[count] = temperature;
		  adcValue =  HAL_ADC_GetValue(&hadc); //we are using a 512x8 eeprom
	      	eeprom_write_to_address(EEPROM_DEVICE_ADDR, adcValue  );
	      	eeprom_write_to_address(EEPROM_DEVICE_ADDR, temperature );
	      	HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_3);
	      	//count++;
	        HAL_Delay(100);

	        sprintf(strTemp, "temperature = %d", temperature);
	        sprintf(strAdc, "ADC = %d", adcValue);

	        lcd_two_line_write(strTemp, strAdc);
=======
	  HAL_ADC_Start (&hadc);
>>>>>>> 1e31e118fe8bf7d21dbed644b77001b693547427


	        }
	  while(1)
	  {

<<<<<<< HEAD
		    lcd_command(LCD_CLEAR_DISPLAY);

=======
	  					  	adcValue =  HAL_ADC_GetValue(&hadc);
	  					  	i++;
	  					  	j = j+2;
>>>>>>> 1e31e118fe8bf7d21dbed644b77001b693547427

      //adcValueEEpromRead =10; test

      tempEEpromRead = eeprom_read_from_address(EEPROM_DEVICE_ADDR);;;// eeprom_read_from_address(EEPROM_DEVICE_ADDR);

      sprintf(strTempRead,  "temperature = %d", tempEEpromRead);


		 	        lcd_two_line_write(strTempRead, strTempRead);



		  	 HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_0);

		  	 HAL_Delay(500);
		  	GPIOB->ODR |= 0xAA;
		  	 init_usart();

		  	  }




	  }
	  exit(1);




	       //lcd_string(str);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
}

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

  /* USER CODE END 3 */


/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSI14;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSI14State = RCC_HSI14_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.HSI14CalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}


static uint32_t check_for_eeprom_magic(void) {

	uint8_t eeprom_magic[] = {0xDE, 0xAD, 0xBA, 0xBE};
  lcd_two_line_write("Attemping to", "read from EEPROM");
  uint32_t pos;
  eeprom_init_spi();
  for(pos = 0; pos < sizeof(eeprom_magic); pos++) {
    if (eeprom_read_from_address(pos) != eeprom_magic[pos]) {
      return 0;
    }
    eeprom_write_to_address(pos, 0x00); // erase the byte after verifying it
  }
  return 1;
}
void delay(void) {
  volatile int i = 0;
  for(; i < 565535; i++);
}



void init_usart(void) {
  // clock to USART1
  RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
  // clock to GPIOA
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
  // PA9 and PA10 to AF
  GPIOA->MODER |= GPIO_MODER_MODER9_1;
  GPIOA->MODER |= GPIO_MODER_MODER10_1;
  // remap to correct AF
  GPIOA->AFR[1] |= (1 << (1*4)); // remap pin 9 to AF1
  GPIOA->AFR[1] |= (1 << (2*4)); // remap pin 10 to AF1
  // BRR = fclk / baud = fclk / 115200
  SystemCoreClockUpdate();
  USART1->BRR = SystemCoreClock/115200;
  // enable with UE in CR1
  USART1->CR1 |= USART_CR1_UE;
  USART1->CR1 |= USART_CR1_RE;
  USART1->CR1 |= USART_CR1_TE;
}


/**
  * @brief ADC Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC_Init(void)
{

  /* USER CODE BEGIN ADC_Init 0 */

  /* USER CODE END ADC_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC_Init 1 */

  /* USER CODE END ADC_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc.Instance = ADC1;
  hadc.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc.Init.Resolution = ADC_RESOLUTION_12B;
  hadc.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc.Init.ScanConvMode = ADC_SCAN_DIRECTION_FORWARD;
  hadc.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc.Init.LowPowerAutoWait = DISABLE;
  hadc.Init.LowPowerAutoPowerOff = DISABLE;
  hadc.Init.ContinuousConvMode = DISABLE;
  hadc.Init.DiscontinuousConvMode = DISABLE;
  hadc.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc.Init.DMAContinuousRequests = DISABLE;
  hadc.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  if (HAL_ADC_Init(&hadc) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel to be converted.
  */
  sConfig.Channel = ADC_CHANNEL_4;
  sConfig.Rank = ADC_RANK_CHANNEL_NUMBER;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  if (HAL_ADC_ConfigChannel(&hadc, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC_Init 2 */

  /* USER CODE END ADC_Init 2 */

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
  huart1.Init.BaudRate = 38400;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
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
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_3, GPIO_PIN_RESET);

  /*Configure GPIO pins : PB0 PB3 PB5 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PB6 PB7 */
  GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF1_I2C1;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
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
