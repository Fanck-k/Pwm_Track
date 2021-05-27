#ifndef __PWM_BREATHING_H
#define	__PWM_BREATHING_H

#include "stm32f10x.h"



#define MOTOR_A_EN_High              GPIO_SetBits(GPIOA,GPIO_Pin_4);     //电机使能端A设置为高 PA0
#define MOTOR_A_EN_Low               GPIO_ResetBits(GPIOA,GPIO_Pin_4);   //电机使能端A设置为低 PA0`
#define MOTOR_B_EN_High              GPIO_SetBits(GPIOA,GPIO_Pin_5);     //电机使能端B设置为高 PA1
#define MOTOR_B_EN_Low               GPIO_ResetBits(GPIOA,GPIO_Pin_5);   //电机使能端B设置为低 PA1



void TIM3_PWM_Init(void);
void Set_Left_Speed(uint16_t Speed_Left);
void Set_Right_Speed(uint16_t Speed_Right);






///*PWM表中的点数*/
//extern uint16_t  POINT_NUM	;

///*PWM表中的点数*/
//extern uint16_t  POINT_NUM1	;
////控制输出波形的频率
//extern __IO uint16_t period_class ;


//#define RED_LIGHT 		1
//#define GREEN_LIGHT 	2
//#define BLUE_LIGHT		3

///*要使用什么颜色的呼吸灯，可选RED_LIGHT、GREEN_LIGHT、BLUE_LIGHT*/
//#define LIGHT_COLOR 	RED_LIGHT

///********************定时器通道**************************/

///************红灯***************/
//	#define   BRE_TIMx                      TIM3

//	#define   BRE_TIM_APBxClock_FUN        RCC_APB1PeriphClockCmd
//	#define   BRE_TIM_CLK                   RCC_APB1Periph_TIM3
//	#define   BRE_TIM_GPIO_APBxClock_FUN   RCC_APB2PeriphClockCmd
//	#define   BRE_TIM_GPIO_CLK              (RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO)

//	//红灯的引脚需要重映射
//	#define   BRE_GPIO_REMAP_FUN()						GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE); 				

//	#define  BRE_TIM_LED_PORT               GPIOA
//	#define  BRE_TIM_LED_PIN                GPIO_Pin_4

//	#define  BRE_TIM_OCxInit                TIM_OC2Init            //通道选择，1~4
//	#define  BRE_TIM_OCxPreloadConfig       TIM_OC2PreloadConfig 
//	#define  BRE_CCRx                       CCR2

//	#define   BRE_TIMx_IRQn                TIM3_IRQn              //中断
//	#define   BRE_TIMx_IRQHandler          TIM3_IRQHandler






//void      TIMx_Breathing_Init          (void);













#endif /* __PWM_BREATHING_H */
