/*
 * fsm_man.h
 *
 *  Created on: May 28, 2024
 *      Author: hoang
 */

#ifndef INC_FSM_MAN_H_
#define INC_FSM_MAN_H_

#include "stm32f1xx_hal.h"

#define LED_Port GPIOA
#define LED_Pin GPIO_PIN_5

void wrapAroundCounter();
void fsm_man_run();

#endif /* INC_FSM_MAN_H_ */
