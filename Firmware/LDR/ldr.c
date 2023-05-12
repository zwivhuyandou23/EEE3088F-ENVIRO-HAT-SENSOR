/**
 * @file ldr.c
 * @brief LDR Library Source
 * @author Travimadox Webb
 * @position Embedded Software Engineer
 * @company Imperium LLC
 * @date 6th of May 2023
 */

#include "ldr.h"

// Calibration constants
static float m;
static float c;

/**
 * @brief Initialize the LDR with calibration constants
 */
void LDR_Init(void) {
    m = 2.675f;
    c = -66.88f;
}

/**
 * @brief Read ADC value from the LDR
 * @param hadc Pointer to an ADC_HandleTypeDef structure that contains the configuration information for the specified ADC
 * @return 32-bit unsigned integer ADC value
 */
uint32_t LDR_ReadADC(ADC_HandleTypeDef *hadc) {
    uint32_t adc_value;

    // Start ADC conversion
    HAL_ADC_Start(hadc);

    // Poll for conversion completion
    if (HAL_ADC_PollForConversion(hadc, 10) == HAL_OK) {
        // Read ADC value
        adc_value = HAL_ADC_GetValue(hadc);
    }

    // Stop ADC conversion
    HAL_ADC_Stop(hadc);

    return adc_value;
}

/**
 * @brief Read analog light intensity using the LDR
 * @param hadc Pointer to an ADC_HandleTypeDef structure that contains the configuration information for the specified ADC
 * @return Floating-point light intensity value
 */
float LDR_ReadAnalogLightIntensity(ADC_HandleTypeDef *hadc) {
    uint32_t adc_value = LDR_ReadADC(hadc);
    return m * adc_value + c;
}
