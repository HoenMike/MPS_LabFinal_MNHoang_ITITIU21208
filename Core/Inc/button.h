/*
 * button.h
 *
 *  Created on: May 28, 2024
 *      Author: hoang
 */

#include "main.h"
#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NORMAL GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

extern int button1_flag;
extern int button2_flag;
extern int button3_flag;

extern int button1_flagRelease;
extern int button2_flagRelease;
extern int button3_flagRelease;
void getKeyInput();

#endif /* INC_BUTTON_H_ */

