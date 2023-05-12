/**
 * @file ldr.h
 * @brief LDR Library Header
 * @author Travimadox Webb
 * @position Embedded Software Engineer
 * @company Imperium LLC
 * @date 6th of May 2023
 */

#ifndef LDR_H
#define LDR_H

#include "stm32f0xx_hal.h"

/**
 * @brief Initialize the LDR
 */
void LDR_Init(void);

/**
 * @brief Read ADC value from the LDR
 * @param hadc Pointer to an ADC_HandleTypeDef structure that contains the configuration information for the specified ADC
 * @return 32-bit unsigned integer ADC value
 */
uint32_t LDR_ReadADC(ADC_HandleTypeDef *hadc);

/**
 * @brief Read analog light intensity using the LDR
 * @param hadc Pointer to an ADC_HandleTypeDef structure that contains the configuration information for the specified ADC
 * @return Floating-point light intensity value
 */
float LDR_ReadAnalogLightIntensity(ADC_HandleTypeDef *hadc);

#endif // LDR_H
