#include "Avoid_Obstacles.h"

void AVOID_GPIO_Config(void)
{		
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*����GPIO����ʱ��*/
		RCC_APB2PeriphClockCmd( AVOID1_GPIO_CLK | AVOID2_GPIO_CLK | AVOID3_GPIO_CLK|AVOID4_GPIO_CLK|AVOID5_GPIO_CLK|AVOID6_GPIO_CLK|AVOID7_GPIO_CLK, ENABLE);
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = AVOID1_GPIO_PIN;	

		/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   

		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(AVOID1_GPIO_PORT, &GPIO_InitStructure);	
	
	
	
		
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = AVOID2_GPIO_PIN;

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(AVOID2_GPIO_PORT, &GPIO_InitStructure);
		
		
		
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = AVOID3_GPIO_PIN;

		/*���ÿ⺯������ʼ��GPIOF*/
		GPIO_Init(AVOID3_GPIO_PORT, &GPIO_InitStructure);
		
				
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = AVOID4_GPIO_PIN;

		/*���ÿ⺯������ʼ��GPIOF*/
		GPIO_Init(AVOID4_GPIO_PORT, &GPIO_InitStructure);
		
	
	
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = AVOID5_GPIO_PIN;

		/*���ÿ⺯������ʼ��GPIOF*/
		GPIO_Init(AVOID5_GPIO_PORT, &GPIO_InitStructure);


		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = AVOID6_GPIO_PIN;

		/*���ÿ⺯������ʼ��GPIOF*/
		GPIO_Init(AVOID6_GPIO_PORT, &GPIO_InitStructure);


		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = AVOID7_GPIO_PIN;

		/*���ÿ⺯������ʼ��GPIOF*/
		GPIO_Init(AVOID7_GPIO_PORT, &GPIO_InitStructure);


}

