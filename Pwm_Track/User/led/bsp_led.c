/**
  ******************************************************************************
  * @file    bsp_led.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   ledӦ�ú����ӿ�
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� F103-ָ���� STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "bsp_led.h"   
#include "bsp_SysTick.h"
#include "breath.h"
 /**
  * @brief  ��ʼ������LED��IO
  * @param  ��
  * @retval ��
  */
	extern u16 speed_left;//����ٶȳ�ֵ
extern u16 speed_right;//�Ҳ��ٶȳ�ֵ



void WHEEL_GPIO_Config(void)
{		
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*����GPIO����ʱ��*/
		RCC_APB2PeriphClockCmd( WHEEL0_GPIO_CLK | WHEEL1_GPIO_CLK | WHEEL2_GPIO_CLK|WHEEL3_GPIO_CLK, ENABLE);
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = WHEEL0_GPIO_PIN;	

		/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(WHEEL0_GPIO_PORT, &GPIO_InitStructure);	
	
	
	
		
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = WHEEL1_GPIO_PIN;

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(WHEEL1_GPIO_PORT, &GPIO_InitStructure);
		
		
		
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = WHEEL2_GPIO_PIN;

		/*���ÿ⺯������ʼ��GPIOF*/
		GPIO_Init(WHEEL2_GPIO_PORT, &GPIO_InitStructure);
		
				
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = WHEEL3_GPIO_PIN;

		/*���ÿ⺯������ʼ��GPIOF*/
		GPIO_Init(WHEEL3_GPIO_PORT, &GPIO_InitStructure);
		
		

		/* ������ֹͣ	*/
		GPIO_ResetBits(WHEEL0_GPIO_PORT, WHEEL0_GPIO_PIN);
		GPIO_ResetBits(WHEEL1_GPIO_PORT, WHEEL1_GPIO_PIN);	 
		GPIO_ResetBits(WHEEL2_GPIO_PORT, WHEEL2_GPIO_PIN);
		GPIO_ResetBits(WHEEL3_GPIO_PORT, WHEEL3_GPIO_PIN);
}




void Go(void)
{
	Set_Left_Speed(500);
	Set_Right_Speed(560);
	WHEEL0_ON;
	WHEEL1_OFF;
	WHEEL2_ON;
	WHEEL3_OFF;
}

//void Back(void)
//{
//	Set_Left_Speed(500);
//	Set_Right_Speed(541.5);
//	WHEEL0_OFF;
//	WHEEL1_ON;
//	WHEEL2_OFF;
//	WHEEL3_ON;
//}

void Turn_Right_Slow(void)
{
	Set_Left_Speed(300);
	Set_Right_Speed(300);
	WHEEL0_ON;
	WHEEL1_OFF;
	WHEEL2_OFF;
	WHEEL3_ON;
	
}

void Turn_Left_Slow(void)
{
	Set_Left_Speed(300);
	Set_Right_Speed(300);
	WHEEL0_OFF;
	WHEEL1_ON;
	WHEEL2_ON;
	WHEEL3_OFF;
	
}

void Turn_Right_Correct(void)
{
	Set_Left_Speed(560);
	Set_Right_Speed(700);
	WHEEL0_ON;
	WHEEL1_OFF;
	WHEEL2_ON;
	WHEEL3_OFF;
}

void Turn_Left_Correct(void)
{
	Set_Left_Speed(700);
	Set_Right_Speed(560);
	WHEEL0_ON;
	WHEEL1_OFF;
	WHEEL2_ON;
	WHEEL3_OFF;
}

//void Turn_Right_Fast(void)
//{
//	WHEEL0_ON;
//	WHEEL1_OFF;
//	WHEEL2_OFF;
//	WHEEL3_ON;
//	
//}


//void Turn_Left_Fast(void)
//{
//	WHEEL0_OFF;
//	WHEEL1_ON;
//	WHEEL2_ON;
//	WHEEL3_OFF;
//	
//}

void Stop(void)
{
	WHEEL0_OFF;
	WHEEL1_OFF;
	WHEEL2_OFF;
	WHEEL3_OFF;
}

/*********************************************END OF FILE**********************/
