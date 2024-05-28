/*
 * fms_man.c
 *
 *  Created on: May 28, 2024
 *      Author: hoang
 */

#ifndef SRC_FSM_AUTOMATIC_C_
#define SRC_FSM_AUTOMATIC_C_

#include "fsm_auto.h"
#include "software_timer.h"
#include "global.h"
#include "button.h"
#include "sevenSeg.h"

void fsm_auto_run()
{
	display7SEG(LED_status);
}

#endif /* SRC_FSM_AUTOMATIC_C_ */
