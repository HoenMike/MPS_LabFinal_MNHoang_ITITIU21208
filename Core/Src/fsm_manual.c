/*
 * fsm_manual.c
 *
 *  Created on: May 28, 2024
 *      Author: hoang
 */

#include "fsm_man.h"
#include "software_timer.h"
#include "display.h"
#include "button.h"

int counter = 0;
int tenSec = 0;

void wrapAroundCounter(int increment)
{
	counter += increment;
	if (counter > 9)
		counter = 0;
	else if (counter < 0)
		counter = 9;
}

void fsm_simple_buttons_run()
{
	if (timer0_flag == 1)
	{
		setTimer0(100); // Reset the timer
		HAL_GPIO_TogglePin(LED_Port, LED_Pin);

		if (++tenSec >= 10)
		{
			tenSec = 0;
			wrapAroundCounter(-1);
		}

		display7SEG(counter); // Display the current counter value
	}

	if (is_button_pressed(0) == 1 || is_long_button_flag(0) == 1)
	{
		counter = 0;
	}
	else if (is_button_pressed(1) == 1 || is_long_button_flag(1) == 1)
	{
		wrapAroundCounter(1);
	}
	else if (is_button_pressed(2) == 1 || is_long_button_flag(2) == 1)
	{
		wrapAroundCounter(-1);
	}
}