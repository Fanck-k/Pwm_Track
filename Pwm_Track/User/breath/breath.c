
#include "breath.h"

uint16_t speed_left;//����ٶȳ�ֵ
uint16_t speed_right;//�Ҳ��ٶȳ�ֵ

                                          

                                     


                                          
/**************************************TIM3��ʱ������************************************************/
										
/*
 * ��������TIM3_GPIO_Config
 * ����  ������TIM3�����PWM�źŵ�ͨ��
 * ����  ����
 * ���  ����
 * ����  ���ڲ�����
 */



static void TIM3_GPIO_Config(void) 
{
      GPIO_InitTypeDef GPIO_InitStructure;
      RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); 
      RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); 
      /*****************************��� ENA  PA0     ENB   PA1*************************/
      GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_7;
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		    // �����������
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
      GPIO_Init(GPIOA, &GPIO_InitStructure);
}

/*
 * ��������TIM3_Mode_Config
 * ����  ������TIM3�����PWM�źŵ�ģʽ�������ڡ����ԡ�ռ�ձ�
 * ����  ����
 * ���  ����
 * ����  ���ڲ�����
 */

static void TIM3_Mode_Config(void)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  TIM_OCInitTypeDef  TIM_OCInitStructure;	 
  TIM_TimeBaseStructure.TIM_Period = (1000-1);       //����ʱ����0������999����Ϊ1000�Σ�Ϊһ����ʱ����
  TIM_TimeBaseStructure.TIM_Prescaler = (72-1);	    //����Ԥ��Ƶ����Ԥ��Ƶ����Ϊ36MHz
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;	//����ʱ�ӷ�Ƶϵ��������Ƶ
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //���ϼ���ģʽ
  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

  /* PWM1 Mode configuration: Channel1 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //����ΪPWMģʽ1
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	
  TIM_OCInitStructure.TIM_Pulse = (speed_left-1);	   //��������ֵ�������������������ֵʱ����ƽ��������
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //����ʱ������ֵС��CCR1_ValʱΪ�ߵ�ƽ
  TIM_OC1Init(TIM3, &TIM_OCInitStructure);	 //ʹ��ͨ��1
  TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);

  /* PWM1 Mode configuration: Channel2 */
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = (speed_right-1);	  //����ͨ��2�ĵ�ƽ����ֵ���������һ��ռ�ձȵ�PWM
  TIM_OC2Init(TIM3, &TIM_OCInitStructure);	  //ʹ��ͨ��2
  TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
  TIM_Cmd(TIM3, ENABLE);                   //ʹ�ܶ�ʱ��5	
}

/*
 * ��������TIM3_PWM_Init
 * ����  ��TIM3 ��ʼ��
 * ����  ����
 * ���  ����
 * ����  ���ⲿ����
 */
 void TIM3_PWM_Init(void)
{
	TIM3_GPIO_Config();
	TIM3_Mode_Config();
}

                                         
/**************************************TIM4��ʱ������*************************************************/

                                         

                                            
/*****************************************�������**************************************************/
											
/*
 * ��������PWM_MOTOR_LEFT,PWM_MOTOR_RIGHT
 * ����  ������ٶȵ���
 * ����  ��PWM_1,PWM_2
 * ���  ����
 * ����  ���ⲿ����
 */
 
/****************���ʹ��A pwm����*********************/
void Set_Left_Speed(uint16_t Speed_Left)
{
  TIM_OCInitTypeDef  TIM_OCInitStructure; 
	
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //����ΪPWMģʽ1
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = Speed_Left-1;	  //����ͨ��2�ĵ�ƽ����ֵ���������һ��ռ�ձȵ�PWM
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //����ʱ������ֵС��CCR1_ValʱΪ�ߵ�ƽ
  TIM_OC1Init(TIM3, &TIM_OCInitStructure);	 //ʹ��ͨ��1
	
  TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
}

/****************���ʹ��B pwm����*********************/
void Set_Right_Speed(uint16_t Speed_Right)
{
  TIM_OCInitTypeDef  TIM_OCInitStructure; 
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //����ΪPWMģʽ1
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = Speed_Right-1;	  //����ͨ��2�ĵ�ƽ����ֵ���������һ��ռ�ձȵ�PWM
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //����ʱ������ֵС��CCR1_ValʱΪ�ߵ�ƽ
  TIM_OC2Init(TIM3, &TIM_OCInitStructure);	 //ʹ��ͨ��1
  TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
}
/*********************************************END OF FILE**********************/











///*********************************************END OF FILE**********************/














