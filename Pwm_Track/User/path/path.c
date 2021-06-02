#include "path.h"
#include "bsp_led.h"
#include "Avoid_Obstacles.h"
#include "bsp_systick.h"


extern __IO uint16_t key1;
extern __IO uint16_t key2;




void Track(void)
{
	
	
	//按键函数
	if(key1 == 100)
	{
		Delay_ms(1);
		Turn_Left_Slow();
		Delay_ms(1850);
		key1 = 0;
	}
	
	if(key2 == 100)
	{
		Delay_ms(1);
		Go();
		Delay_ms(1850);
				key2 = 0;
	}
	
	
	//直行 L4
	//只有中间检测到黑线，直行
	if(L1==0 && L2==0 && L3==0 && L4==1 && L5==0 && L6==0 && L7==0)
	{
			Delay_ms(1);
			Go();
			//Delay_ms(700);
	}
	
	
	else
	{
		Stop();
	}



}
