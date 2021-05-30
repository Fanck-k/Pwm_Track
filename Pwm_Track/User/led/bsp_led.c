/**
  ******************************************************************************
  * @file    bsp_led.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   led应用函数接口
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 F103-指南者 STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "bsp_led.h"   
#include "bsp_SysTick.h"
#include "breath.h"
 /**
  * @brief  初始化控制LED的IO
  * @param  无
  * @retval 无
  */
	extern u16 speed_left;//左侧速度初值
extern u16 speed_right;//右侧速度初值



void WHEEL_GPIO_Config(void)
{		
		/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*开启GPIO外设时钟*/
		RCC_APB2PeriphClockCmd( WHEEL0_GPIO_CLK | WHEEL1_GPIO_CLK | WHEEL2_GPIO_CLK|WHEEL3_GPIO_CLK, ENABLE);
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = WHEEL0_GPIO_PIN;	

		/*设置引脚模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*设置引脚速率为50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*调用库函数，初始化GPIO*/
		GPIO_Init(WHEEL0_GPIO_PORT, &GPIO_InitStructure);	
	
	
	
		
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = WHEEL1_GPIO_PIN;

		/*调用库函数，初始化GPIO*/
		GPIO_Init(WHEEL1_GPIO_PORT, &GPIO_InitStructure);
		
		
		
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = WHEEL2_GPIO_PIN;

		/*调用库函数，初始化GPIOF*/
		GPIO_Init(WHEEL2_GPIO_PORT, &GPIO_InitStructure);
		
				
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = WHEEL3_GPIO_PIN;

		/*调用库函数，初始化GPIOF*/
		GPIO_Init(WHEEL3_GPIO_PORT, &GPIO_InitStructure);
		
		

		/* 所有轮停止	*/
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
