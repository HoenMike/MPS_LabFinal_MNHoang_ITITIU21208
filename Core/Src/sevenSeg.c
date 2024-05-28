/*
 * SevenSeg.c
 *
 *  Created on: May 28, 2024
 *      Author: hoang
 */

#include "sevenSeg.h"
#include "main.h"

void init7SEG()
{
  display7SEG(0);
}

void display7SEG(int displayNumber)
{
  switch (displayNumber)
  {
  case 1:
    HAL_GPIO_WritePin(GPIOB, B_Pin | C_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, A_Pin | D_Pin | E_Pin | F_Pin | G_Pin, GPIO_PIN_SET);
    break;
  case 2:
    HAL_GPIO_WritePin(GPIOB, A_Pin | B_Pin | G_Pin | E_Pin | D_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, C_Pin | F_Pin, GPIO_PIN_SET);
    break;
  case 3:
    HAL_GPIO_WritePin(GPIOB, A_Pin | B_Pin | G_Pin | C_Pin | D_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, E_Pin | F_Pin, GPIO_PIN_SET);
    break;
  case 4:
    HAL_GPIO_WritePin(GPIOB, F_Pin | G_Pin | B_Pin | C_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, A_Pin | D_Pin | E_Pin, GPIO_PIN_SET);
    break;
  case 5:
    HAL_GPIO_WritePin(GPIOB, A_Pin | F_Pin | G_Pin | C_Pin | D_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, B_Pin | E_Pin, GPIO_PIN_SET);
    break;
  case 6:
    HAL_GPIO_WritePin(GPIOB, A_Pin | F_Pin | G_Pin | C_Pin | D_Pin | E_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, B_Pin, GPIO_PIN_SET);
    break;
  case 7:
    HAL_GPIO_WritePin(GPIOB, A_Pin | B_Pin | C_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, D_Pin | E_Pin | F_Pin | G_Pin, GPIO_PIN_SET);
    break;
  case 8:
    HAL_GPIO_WritePin(GPIOB, A_Pin | B_Pin | C_Pin | D_Pin | E_Pin | F_Pin | G_Pin, GPIO_PIN_RESET);
    break;
  case 9:
    HAL_GPIO_WritePin(GPIOB, A_Pin | B_Pin | C_Pin | D_Pin | F_Pin | G_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, E_Pin, GPIO_PIN_SET);
    break;
  case 0:
    HAL_GPIO_WritePin(GPIOB, A_Pin | B_Pin | C_Pin | D_Pin | E_Pin | F_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, G_Pin, GPIO_PIN_SET);
    break;

  default:
    break;
  }
  return;
}