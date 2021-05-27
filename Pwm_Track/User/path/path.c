#include "path.h"
#include "bsp_led.h"
#include "Avoid_Obstacles.h"
#include "bsp_systick.h"


extern __IO uint16_t Left_Scan;
extern __IO uint16_t Go_Scan;
	
void Track(void)
{
	//ֱ�� L4
	//ֻ���м��⵽���ߣ�ֱ��
	if(L1==0 && L2==0 && L3==0 && L4==1 && L5==0 && L6==0 && L7==0)
	{
			SysTick_Delay_Ms(1);
			Go();
	}


	
	
	//ת��
	//��ת��һ�λ��ߵ����Σ���ת
	else if((L1==1 && L2==1 && L3==1 && L4==1 && L5==0 && L6==0 && L7==0 && Left_Scan==1) || (L1==1 && L2==1 && L3==1 && L4==1 && L5==0 && L6==0 && L7==0 && Left_Scan==3))	
	{
		do{
			SysTick_Delay_Ms(1);
			Turn_Left_Slow();
		}while(L1==0 && L2==0 && L3==0 && L4==1 && L5==0 && L6==0 && L7==0);
		Left_Scan += 1;
	}

	
	//��ת�ڶ��Ρ����ĴΡ�����Σ�ֱ��
	else if(L1==1 && L2==1 && L3==1 && L4==1 && L5==0 && L6==0 && L7==0 && Left_Scan!=1 && Left_Scan!=3)
	{
		SysTick_Delay_Ms(1);
		Go();
		if(Left_Scan==5)
		{
			Left_Scan = 1;
		}
		else
		{
			Left_Scan += 1;
		}
	}
	
	
	//��ת
	else if(L1==0 && L2==0 && L3==0 && L4==1 && L5==1 && L6==1 && L7==1)
	{
		uint16_t i=0;
		while(i<=1)
		{
			do{
				SysTick_Delay_Ms(1);
				Turn_Right_Slow();
			}while(L4==1);
			i++;
			SysTick_Delay_Ms(700);
		}
	}
	
	
	
	
	
	//λ�þ���
	//�����
	else if((L1==0 && L2==1 && L3==1 && L4==1 && L5==0 && L6==0 && L7==0) || (L1==0 && L2==0 && L3==1 && L4==1 && L5==0 && L6==0 && L7==0) || (L1==0 && L2==0 && L3==1 && L4==0 && L5==0 && L6==0 && L7==0) || (L1==0 && L2==1 && L3==1 && L4==0 && L5==0 && L6==0 && L7==0))
	{
		SysTick_Delay_Ms(1);
		Turn_Left_Slow();
	}
	
	//�Ҿ���
	else if((L1==0 && L2==0 && L3==0 && L4==1 && L5==1 && L6==1 && L7==0) || (L1==0 && L2==0 && L3==0 && L4==1 && L5==1 && L6==0 && L7==0) || (L1==0 && L2==0 && L3==0 && L4==0 && L5==1 && L6==0 && L7==0) || (L1==0 && L2==0 && L3==0 && L4==0 && L5==1 && L6==1 && L7==0))
	{
		SysTick_Delay_Ms(1);
		Turn_Right_Slow();
	}
	
	
	
	//�����ж�
	//ֹͣ�����һ��������ֱ��
	else if(L1==1 && L2==1 && L3==1 && L4==1 && L5==1 && L6==1 && L7==1 && Go_Scan==1)
	{
		SysTick_Delay_Ms(1);
		Go();
		Go_Scan += 1;
	}
	
	
	//ֹͣ����ڶ��Ρ������Ρ����Ĵ�������ֹͣ
	else if(L1==1 && L2==1 && L3==1 && L4==1 && L5==1 && L6==1 && L7==1 && Go_Scan!=1)
	{
		SysTick_Delay_Ms(1);
		Stop();
		if(Go_Scan==4)
		{
			Go_Scan = 1;
		}
		else
		{
			Go_Scan += 1;
		}
	}
	
	
	//ɨ�費���κ�������
	else if(L1==0 && L2==0 && L3==0 && L4==0 && L5==0 && L6==0 && L7==0)
	{
		SysTick_Delay_Ms(1);
		Turn_Left_Slow();
	
		if(L1==0 && L2==0 && L3==0 && L4==0 && L5==0 && L6==0 && L7==0)
		{
			SysTick_Delay_Ms(1);
			Stop();
		}
	}
	
	else
	{
		Stop();
	}

}
