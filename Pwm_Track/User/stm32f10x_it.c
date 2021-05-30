/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTI
  
  AL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
#include "Avoid_Obstacles.h"
#include "path.h"
#include "bsp_led.h"
#include "breath.h"
#include "bsp_systick.h"
#include "path.h"

/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 

//extern uint16_t indexWave[];
//extern uint16_t off[];

///* �������жϷ����� */
//void BRE_TIMx_IRQHandler(void)
//{ 
//	//�������
//	static uint16_t pwm_index = 0;   //����PWM���
//	static uint16_t period_cnt = 0;  //���ڼ���������
//	
//	//ҹ�����
//	static uint16_t pwm_index1 = 0;   //����PWM���
//	static uint16_t period_cnt1 = 0;  //���ڼ���������
// 
// if (TIM_GetITStatus(BRE_TIMx, TIM_IT_Update) != RESET) //TIM_IT_Update
//  {  
//		//����Ч��
//  if(GPIO_ReadInputDataBit(AVOID2_GPIO_PORT,AVOID2_GPIO_PIN)==1 &&GPIO_ReadInputDataBit(AVOID0_GPIO_PORT,AVOID0_GPIO_PIN)==0&&GPIO_ReadInputDataBit(AVOID1_GPIO_PORT,AVOID1_GPIO_PIN)==0&&GPIO_ReadInputDataBit(AVOID3_GPIO_PORT,AVOID3_GPIO_PIN)==0&&GPIO_ReadInputDataBit(AVOID4_GPIO_PORT,AVOID4_GPIO_PIN)==0)
//  {   
//   if( pwm_index <  POINT_NUM)   
//    { 
//     period_cnt++;
//     BRE_TIMx->BRE_CCRx = indexWave[pwm_index]; //����PWM���޸Ķ�ʱ���ıȽϼĴ���ֵ

//     //ÿ��PWM���е�ÿ��Ԫ��ʹ��period_class��
//     if(period_cnt > period_class)         
//     {    
//      pwm_index++;            //��־PWM��ָ����һ��Ԫ��
//      //��PWM���ѵ����β������ָ���ͷ
//      period_cnt=0; 
//			 //�������ڼ�����־
//			pwm_index1 = 0;		
//     } 
//    }
//   }
//	

//	if(GPIO_ReadInputDataBit(AVOID2_GPIO_PORT,AVOID2_GPIO_PIN)==1 &&GPIO_ReadInputDataBit(AVOID0_GPIO_PORT,AVOID0_GPIO_PIN)==0&&GPIO_ReadInputDataBit(AVOID1_GPIO_PORT,AVOID1_GPIO_PIN)==0&&GPIO_ReadInputDataBit(AVOID3_GPIO_PORT,AVOID3_GPIO_PIN)==1&&GPIO_ReadInputDataBit(AVOID4_GPIO_PORT,AVOID4_GPIO_PIN)==0)
//			{   
//			if( pwm_index1 <  POINT_NUM1)   
//				{ 
//					period_cnt1++;
//					BRE_TIMx->BRE_CCRx =off[pwm_index1]; //����PWM���޸Ķ�ʱ���ıȽϼĴ���ֵ
//					//ÿ��PWM���е�ÿ��Ԫ��ʹ��period_class��
//					if(period_cnt1 > period_class)         
//						{    
//							pwm_index1++;            //��־PWM��ָ����һ��Ԫ��
//							//��PWM���ѵ����β������ָ���ͷ
//							period_cnt1=0;           //�������ڼ�����־
//							pwm_index = 0;
//						} 
//				}
//			}

//  TIM_ClearITPendingBit (BRE_TIMx, TIM_IT_Update); //����Ҫ����жϱ�־λ
// }
//}



extern __IO uint16_t Go_Scan;

void EXTI0_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line0) != RESET)
	{
		EXTI0();	
	}
	EXTI_ClearITPendingBit(EXTI_Line0);
}




void EXTI15_10_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line13) != RESET)
	{
		EXTI13();
	}
	EXTI_ClearITPendingBit(EXTI_Line13);
}



 


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
