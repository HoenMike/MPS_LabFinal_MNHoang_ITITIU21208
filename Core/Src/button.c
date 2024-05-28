/*
 * button.c
 *
 *  Created on: May 28, 2024
 *      Author: hoang
 */

#include "button.h"

int keyReg0[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg1[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg2[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg3[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int timeForPress[3] = {200, 200, 200};
int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

int button1_flagRelease = 0;
int button2_flagRelease = 0;
int button3_flagRelease = 0;

GPIO_TypeDef *button_GPIO_Port[] = {RESET_BUTTON_GPIO_Port,
                                    INC_BUTTON_GPIO_Port,
                                    DEC_BUTTON_GPIO_Port};
uint16_t button_Pin[] = {RESET_BUTTON_Pin,
                         INC_BUTTON_Pin,
                         DEC_BUTTON_Pin};

void getKeyInput()
{
    for (int i = 0; i < 3; i++)
    {
        keyReg0[i] = keyReg1[i];
        keyReg1[i] = keyReg2[i];
        keyReg2[i] = HAL_GPIO_ReadPin(button_GPIO_Port[i], button_Pin[i]);

        if ((keyReg0[i] == keyReg1[i]) && (keyReg2[i] == keyReg1[i])) // stable state
        {
            if (keyReg3[i] != keyReg2[i]) // stable state change
            {
                keyReg3[i] = keyReg2[i];
                if (keyReg2[i] == PRESSED_STATE)
                {
                    if (i == 0)
                    {
                        button1_flag = 1;
                    }
                    if (i == 1)
                    {
                        button2_flag = 1;
                    }
                    if (i == 2)
                    {
                        button3_flag = 1;
                    }
                    timeForPress[i] = 200;
                }
            }
            else
            {
                timeForPress[i]--;
                if (timeForPress[i] == 0)
                {
                    keyReg3[i] = NORMAL_STATE;
                }
            }
        }
    }
}
