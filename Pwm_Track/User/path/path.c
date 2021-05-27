#include "path.h"
#include "bsp_led.h"
#include "Avoid_Obstacles.h"
#include "bsp_systick.h"


extern __IO uint16_t Left_Scan;
extern __IO uint16_t Go_Scan;
	
void Track(void)
{
	//直行 L4
	//只有中间检测到黑线，直行
	if(L1==0 && L2==0 && L3==0 && L4==1 && L5==0 && L6==0 && L7==0)
	{
			SysTick_Delay_Ms(1);
			Go();
	}


	
	
	//转弯
	//左转第一次或者第三次，左转
	else if((L1==1 && L2==1 && L3==1 && L4==1 && L5==0 && L6==0 && L7==0 && Left_Scan==1) || (L1==1 && L2==1 && L3==1 && L4==1 && L5==0 && L6==0 && L7==0 && Left_Scan==3))	
	{
		do{
			SysTick_Delay_Ms(1);
			Turn_Left_Slow();
		}while(L1==0 && L2==0 && L3==0 && L4==1 && L5==0 && L6==0 && L7==0);
		Left_Scan += 1;
	}

	
	//左转第二次、第四次、第五次，直行
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
	
	
	//右转
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
	
	
	
	
	
	//位置纠正
	//左纠正
	else if((L1==0 && L2==1 && L3==1 && L4==1 && L5==0 && L6==0 && L7==0) || (L1==0 && L2==0 && L3==1 && L4==1 && L5==0 && L6==0 && L7==0) || (L1==0 && L2==0 && L3==1 && L4==0 && L5==0 && L6==0 && L7==0) || (L1==0 && L2==1 && L3==1 && L4==0 && L5==0 && L6==0 && L7==0))
	{
		SysTick_Delay_Ms(1);
		Turn_Left_Slow();
	}
	
	//右纠正
	else if((L1==0 && L2==0 && L3==0 && L4==1 && L5==1 && L6==1 && L7==0) || (L1==0 && L2==0 && L3==0 && L4==1 && L5==1 && L6==0 && L7==0) || (L1==0 && L2==0 && L3==0 && L4==0 && L5==1 && L6==0 && L7==0) || (L1==0 && L2==0 && L3==0 && L4==0 && L5==1 && L6==1 && L7==0))
	{
		SysTick_Delay_Ms(1);
		Turn_Right_Slow();
	}
	
	
	
	//其他判断
	//停止如果第一次碰到，直行
	else if(L1==1 && L2==1 && L3==1 && L4==1 && L5==1 && L6==1 && L7==1 && Go_Scan==1)
	{
		SysTick_Delay_Ms(1);
		Go();
		Go_Scan += 1;
	}
	
	
	//停止如果第二次、第三次、第四次碰到，停止
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
	
	
	//扫描不到任何物体检测
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
