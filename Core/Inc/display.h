/*
 * display.h
 *
 *  Created on: May 28, 2024
 *      Author: hoang
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

#include "stm32f1xx_hal.h" // Include the HAL header

// Define the GPIO pins
#define SEG0_Pin GPIO_PIN_0
#define SEG1_Pin GPIO_PIN_1
#define SEG2_Pin GPIO_PIN_2
#define SEG3_Pin GPIO_PIN_3
#define SEG4_Pin GPIO_PIN_4
#define SEG5_Pin GPIO_PIN_5
#define SEG6_Pin GPIO_PIN_6
#define SEG_GPIO_Port GPIOB

void display7SEG(int status);

#endif /* INC_DISPLAY_H_ */
