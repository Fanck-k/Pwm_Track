#include "stm32f10x.h"
#include "bsp_led.h"
#include "path.h"
#include "Avoid_Obstacles.h"
#include "breath.h"
#include "bsp_systick.h"
#include "bsp_exti.h"

__IO uint16_t key1 = 0;
__IO uint16_t key2 = 0;

int main(void)
{

	AVOID_GPIO_Config();
	WHEEL_GPIO_Config();
	TIM3_PWM_Init();
	EXTI_Key_Config();
	SysTick_Init();


	while (1)
	{
		Track();

	}
}


/*********************************************END OF FILE**********************/
