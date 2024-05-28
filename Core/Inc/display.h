/*
 * display.h
 *
 *  Created on: May 28, 2024
 *      Author: hoang
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

#include "global.h"

void red_green();
void red_yellow();
void green_red();
void yellow_red();
void green_green();
void red_red();
void yellow_yellow();

void update7SEG();
void update7SEG_2();
void display7SEG(int index);

#endif /* INC_DISPLAY_H_ */
