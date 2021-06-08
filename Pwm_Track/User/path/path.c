#include "path.h"
#include "bsp_led.h"
#include "Avoid_Obstacles.h"
#include "bsp_systick.h"


extern __IO uint16_t key1;
extern __IO uint16_t key2;




void Track(void)
{
	
	
	//��������
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
	
	
	//ֱ��
	if(D)
	{
		Delay_ms(1);
		Go();
		//Delay_ms(700);
	}
	
	
	
	//��ת
	else if(L)
	{
		Delay_ms(1);
		Turn_Left_Slow();
		
	}
	
	//��ת
	else if(R)
	{
		Delay_ms(1);
		Turn_Right_Slow();
		
	}
	
	//�����
	else if(LCorrect)
	{
		Delay_ms(1);
		Turn_Left_Correct();
	}
	
	//�Ҿ���
	else if(RCorrect)
	{
		Delay_ms(1);
		Turn_Right_Correct();		
	}
	
//	else if(S)
//	{
//		Delay_ms(1);
//		Go();
//	}
	
	
	else if(S)
	{
		Delay_ms(1);
		Stop();
	}
	else
	{
		Delay_ms(1);
		Go();
	}



}
