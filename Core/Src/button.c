/*
 * button.c
 *
 *  Created on: May 28, 2024
 *      Author: hoang
 */

#include "button.h"
#define TIME_FOR_LONG_KEY 25
#define TIME_FOR_PRESS_KEY 200
#define NUM_BUTTONS 3

int KeyReg0[NUM_BUTTONS] = {SET};
int KeyReg1[NUM_BUTTONS] = {SET};
int KeyReg2[NUM_BUTTONS] = {SET};
int KeyReg3[NUM_BUTTONS] = {SET};

int TimeOutForKeyPress = TIME_FOR_PRESS_KEY;
int TimeOutForLongKeyPress = TIME_FOR_LONG_KEY;

int button_flag[NUM_BUTTONS] = {RESET};
int button_flag_1s[NUM_BUTTONS] = {RESET};

int long_button_flag[NUM_BUTTONS] = {RESET};

int is_button_pressed(int index)
{
    if (button_flag[index] == 1)
    {
        button_flag[index] = 0;
        return 1;
    }
    return 0;
}

void subKeyProcess(int index) // index = 0, 1, 2
{
    button_flag[index] = 1; // set flag for button (1 = pressed)
}

int is_long_button_flag(int index) // index = 0, 1, 2
{
    if (long_button_flag[index] == 1) // if long_button_flag is set
    {
        long_button_flag[index] = 0; // reset long_button_flag
        return 1;
    }
    return 0;
}

void getKeyInput() // get input from button
{
    for (int i = 0; i < 3; i++)
    {
        KeyReg2[i] = KeyReg1[i];
        KeyReg1[i] = KeyReg0[i];
        switch (i)
        {
        case 0:
            KeyReg0[i] = HAL_GPIO_ReadPin(RESET_BUTTON_GPIO_Port, RESET_BUTTON_Pin);
            break;
        case 1:
            KeyReg0[i] = HAL_GPIO_ReadPin(INC_BUTTON_GPIO_Port, INC_BUTTON_Pin);
            break;
        case 2:
            KeyReg0[i] = HAL_GPIO_ReadPin(DEC_BUTTON_GPIO_Port, DEC_BUTTON_Pin);
            break;
        default:
            break;
        }

        if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i]))
        {
            if (KeyReg2[i] != KeyReg3[i])
            {
                KeyReg3[i] = KeyReg2[i];

                if (KeyReg3[i] == PRESSED_STATE)
                {
                    subKeyProcess(i);
                }
            }
            else
            {
                TimeOutForKeyPress--;

                if (TimeOutForKeyPress == 0)
                {
                    if (KeyReg2[i] == PRESSED_STATE)
                    {
                        TimeOutForKeyPress = TIME_FOR_PRESS_KEY;
                        button_flag_1s[i] = 1;
                    }
                }
                if ((button_flag_1s[i] == 1))
                {
                    TimeOutForLongKeyPress--;

                    if (TimeOutForLongKeyPress == 0)
                    {
                        long_button_flag[i] = 1;
                        TimeOutForLongKeyPress = TIME_FOR_LONG_KEY;
                    }
                }
            }
        }
        else
        {
            button_flag_1s[i] = 0;
            TimeOutForKeyPress = TIME_FOR_PRESS_KEY;
        }
    }
}
