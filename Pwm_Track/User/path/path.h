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

#define L							((L1==1 && L2==1 && L3==1 && L4==1 && L5==0 && L6==0 && L7==0) || (L1==0 && L2==1 && L3==1 && L4==1 && L5==0 && L6==0 && L7==0) || (L1==1 && L2==1 && L3==0 && L4==1 && L5==0 && L6==0 && L7==0) || (L1==0 && L2==1 && L3==0 && L4==1 && L5==0 && L6==0 && L7==0) || (L1==1 && L2==1 && L3==1 && L4==0 && L5==0 && L6==0 && L7==0))
#define R							((L1==0 && L2==0 && L3==0 && L4==1 && L5==1 && L6==1 && L7==1) || (L1==0 && L2==0 && L3==0 && L4==1 && L5==1 && L6==1 && L7==0) || (L1==0 && L2==0 && L3==0 && L4==1 && L5==0 && L6==1 && L7==1) || (L1==0 && L2==0 && L3==0 && L4==1 && L5==0 && L6==1 && L7==0) || (L1==0 && L2==0 && L3==0 && L4==0 && L5==1 && L6==1 && L7==1)) 
#define LCorrect			((L1==0 && L2==0 && L3==1 && L4==1 && L5==0 && L6==0 && L7==0) || (L1==0 && L2==0 && L3==1 && L4==0 && L5==0 && L6==0 && L7==0) || (L1==0 && L2==1 && L3==0 && L4==0 && L5==0 && L6==0 && L7==0) || (L1==1 && L2==0 && L3==1 && L4==0 && L5==0 && L6==0 && L7==0) || (L1==1 && L2==1 && L3==0 && L4==0 && L5==0 && L6==0 && L7==0))
#define RCorrect			((L1==0 && L2==0 && L3==0 && L4==1 && L5==1 && L6==0 && L7==0) || (L1==0 && L2==0 && L3==0 && L4==0 && L5==1 && L6==0 && L7==0) || (L1==0 && L2==0 && L3==0 && L4==0 && L5==0 && L6==1 && L7==0) || (L1==0 && L2==0 && L3==0 && L4==0 && L5==1 && L6==0 && L7==1) || (L1==0 && L2==0 && L3==0 && L4==0 && L5==0 && L6==1 && L7==1))
#define D							(L1==0 && L2==0 && L3==0 && L4==1 && L5==0 && L6==0 && L7==0)
#define P							(L1==1 && L2==0 && L3==0 && L4==1 && L5==0 && L6==0 && L7==1)





void Track(void);
static void delay(uint16_t i);


#endif /*__PATH_H*/
