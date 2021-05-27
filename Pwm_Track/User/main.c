#include "stm32f10x.h"
#include "bsp_led.h"
#include "path.h"
#include "Avoid_Obstacles.h"
#include "breath.h"
#include "bsp_systick.h"


__IO uint16_t Left_Scan=1;
__IO uint16_t Go_Scan=1;

int main(void)
{
	AVOID_GPIO_Config();
	WHEEL_GPIO_Config();
	TIM3_PWM_Init();



	while (1)
	{
		//Track();
		Turn_Right_Slow();
		SysTick_Delay_Ms(1850);
		Stop();
		SysTick_Delay_Ms(5000);

	}
}


/*********************************************END OF FILE**********************/
