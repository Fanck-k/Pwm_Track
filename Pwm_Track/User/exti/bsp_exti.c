#include "bsp_exti.h"


static void EXTI_NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);
	NVIC_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_Init(&NVIC_InitStruct);
}


void EXTI_Key_Config(void)
{
	GPIO_InitTypeDef GPIO_EXTI; //�����ṹ��
	EXTI_InitTypeDef EXTI_InitStruct;
	
	
	//�����ж����ȼ�
	EXTI_NVIC_Config();
	
	//��ʼ��GPIO
	RCC_APB2PeriphClockCmd(KEY1_INT_LED_GPIO_CLK|KEY2_INT_LED_GPIO_CLK, ENABLE); //��CLK ʱ��
	
	GPIO_EXTI.GPIO_Mode = GPIO_Mode_IN_FLOATING; //���������ʽ
	GPIO_EXTI.GPIO_Pin = KEY1_INT_LED_GPIO_PIN|KEY2_INT_LED_GPIO_PIN;//����������ſ�
	
	GPIO_Init(KEY1_INT_LED_GPIO_PORT,&GPIO_EXTI);
	GPIO_Init(KEY2_INT_LED_GPIO_PORT,&GPIO_EXTI);
	
	
	//��ʼ��EXTI ѡ��������
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource13);
	
	EXTI_InitStruct.EXTI_Line = EXTI_Line0|EXTI_Line13;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	
	EXTI_Init(&EXTI_InitStruct);
	


}

