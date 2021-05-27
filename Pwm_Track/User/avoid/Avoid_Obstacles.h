#ifndef __AVOID_OBSTACLES_H
#define	__AVOID_OBSTACLES_H

#include "stm32f10x.h"

// ��1
#define AVOID1_GPIO_PORT    	GPIOC			              /* GPIO�˿� */
#define AVOID1_GPIO_CLK 	    RCC_APB2Periph_GPIOC		/* GPIO�˿�ʱ�� */
#define AVOID1_GPIO_PIN				GPIO_Pin_6			        /* ���ӵ�SCLʱ���ߵ�GPIO */

//��2
#define AVOID2_GPIO_PORT    	GPIOC			              /* GPIO�˿� */
#define AVOID2_GPIO_CLK 	    RCC_APB2Periph_GPIOC		/* GPIO�˿�ʱ�� */
#define AVOID2_GPIO_PIN				GPIO_Pin_7			        /* ���ӵ�SCLʱ���ߵ�GPIO */

//��3
#define AVOID3_GPIO_PORT    	GPIOC			              /* GPIO�˿� */
#define AVOID3_GPIO_CLK 	    RCC_APB2Periph_GPIOC		/* GPIO�˿�ʱ�� */
#define AVOID3_GPIO_PIN				GPIO_Pin_8			        /* ���ӵ�SCLʱ���ߵ�GPIO */

//��4
#define AVOID4_GPIO_PORT    	GPIOC			              /* GPIO�˿� */
#define AVOID4_GPIO_CLK 	    RCC_APB2Periph_GPIOC		/* GPIO�˿�ʱ�� */
#define AVOID4_GPIO_PIN				GPIO_Pin_9			        /* ���ӵ�SCLʱ���ߵ�GPIO */

//��5
#define AVOID5_GPIO_PORT    	GPIOC			              /* GPIO�˿� */
#define AVOID5_GPIO_CLK 	    RCC_APB2Periph_GPIOC		/* GPIO�˿�ʱ�� */
#define AVOID5_GPIO_PIN				GPIO_Pin_10			        /* ���ӵ�SCLʱ���ߵ�GPIO */


//��6
#define AVOID6_GPIO_PORT    	GPIOC			              /* GPIO�˿� */
#define AVOID6_GPIO_CLK 	    RCC_APB2Periph_GPIOC		/* GPIO�˿�ʱ�� */
#define AVOID6_GPIO_PIN				GPIO_Pin_11			        /* ���ӵ�SCLʱ���ߵ�GPIO */


//��7
#define AVOID7_GPIO_PORT    	GPIOC			              /* GPIO�˿� */
#define AVOID7_GPIO_CLK 	    RCC_APB2Periph_GPIOC		/* GPIO�˿�ʱ�� */
#define AVOID7_GPIO_PIN				GPIO_Pin_12			        /* ���ӵ�SCLʱ���ߵ�GPIO */








void AVOID_GPIO_Config(void);


#endif /*__AVOID_OBSTACLES_H */
