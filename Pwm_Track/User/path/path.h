#ifndef __PATH_H
#define __PATH_H

#include "stm32f10x.h"


#define L1			GPIO_ReadInputDataBit(AVOID1_GPIO_PORT,AVOID1_GPIO_PIN)
#define L2			GPIO_ReadInputDataBit(AVOID2_GPIO_PORT,AVOID2_GPIO_PIN)
#define L3			GPIO_ReadInputDataBit(AVOID3_GPIO_PORT,AVOID3_GPIO_PIN)
#define L4			GPIO_ReadInputDataBit(AVOID4_GPIO_PORT,AVOID4_GPIO_PIN)
#define L5			GPIO_ReadInputDataBit(AVOID5_GPIO_PORT,AVOID5_GPIO_PIN)
#define L6			GPIO_ReadInputDataBit(AVOID6_GPIO_PORT,AVOID6_GPIO_PIN)
#define L7			GPIO_ReadInputDataBit(AVOID7_GPIO_PORT,AVOID7_GPIO_PIN)


void Track(void);
static void delay(uint16_t i);


#endif /*__PATH_H*/
