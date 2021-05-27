#ifndef __PWM_BREATHING_H
#define	__PWM_BREATHING_H

#include "stm32f10x.h"



#define MOTOR_A_EN_High              GPIO_SetBits(GPIOA,GPIO_Pin_4);     //���ʹ�ܶ�A����Ϊ�� PA0
#define MOTOR_A_EN_Low               GPIO_ResetBits(GPIOA,GPIO_Pin_4);   //���ʹ�ܶ�A����Ϊ�� PA0`
#define MOTOR_B_EN_High              GPIO_SetBits(GPIOA,GPIO_Pin_5);     //���ʹ�ܶ�B����Ϊ�� PA1
#define MOTOR_B_EN_Low               GPIO_ResetBits(GPIOA,GPIO_Pin_5);   //���ʹ�ܶ�B����Ϊ�� PA1



void TIM3_PWM_Init(void);
void Set_Left_Speed(uint16_t Speed_Left);
void Set_Right_Speed(uint16_t Speed_Right);






///*PWM���еĵ���*/
//extern uint16_t  POINT_NUM	;

///*PWM���еĵ���*/
//extern uint16_t  POINT_NUM1	;
////����������ε�Ƶ��
//extern __IO uint16_t period_class ;


//#define RED_LIGHT 		1
//#define GREEN_LIGHT 	2
//#define BLUE_LIGHT		3

///*Ҫʹ��ʲô��ɫ�ĺ����ƣ���ѡRED_LIGHT��GREEN_LIGHT��BLUE_LIGHT*/
//#define LIGHT_COLOR 	RED_LIGHT

///********************��ʱ��ͨ��**************************/

///************���***************/
//	#define   BRE_TIMx                      TIM3

//	#define   BRE_TIM_APBxClock_FUN        RCC_APB1PeriphClockCmd
//	#define   BRE_TIM_CLK                   RCC_APB1Periph_TIM3
//	#define   BRE_TIM_GPIO_APBxClock_FUN   RCC_APB2PeriphClockCmd
//	#define   BRE_TIM_GPIO_CLK              (RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO)

//	//��Ƶ�������Ҫ��ӳ��
//	#define   BRE_GPIO_REMAP_FUN()						GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE); 				

//	#define  BRE_TIM_LED_PORT               GPIOA
//	#define  BRE_TIM_LED_PIN                GPIO_Pin_4

//	#define  BRE_TIM_OCxInit                TIM_OC2Init            //ͨ��ѡ��1~4
//	#define  BRE_TIM_OCxPreloadConfig       TIM_OC2PreloadConfig 
//	#define  BRE_CCRx                       CCR2

//	#define   BRE_TIMx_IRQn                TIM3_IRQn              //�ж�
//	#define   BRE_TIMx_IRQHandler          TIM3_IRQHandler






//void      TIMx_Breathing_Init          (void);













#endif /* __PWM_BREATHING_H */
