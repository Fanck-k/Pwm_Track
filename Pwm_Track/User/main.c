#include "stm32f10x.h"
#include "bsp_led.h"
#include "path.h"
#include "Avoid_Obstacles.h"
#include "breath.h"
#include "bsp_systick.h"
#include "bsp_exti.h"

__IO uint16_t Left_Scan=1;
__IO uint16_t Go_Scan=1;

int main(void)
{
	AVOID_GPIO_Config();
	WHEEL_GPIO_Config();
	TIM3_PWM_Init();
	EXTI_Key_Config();


	while (1)
	{
		Track();

	}
}


/*********************************************END OF FILE**********************/
