#ifndef __AVOID_OBSTACLES_H
#define	__AVOID_OBSTACLES_H

#include "stm32f10x.h"

// 左1
#define AVOID1_GPIO_PORT    	GPIOC			              /* GPIO端口 */
#define AVOID1_GPIO_CLK 	    RCC_APB2Periph_GPIOC		/* GPIO端口时钟 */
#define AVOID1_GPIO_PIN				GPIO_Pin_6			        /* 连接到SCL时钟线的GPIO */

//左2
#define AVOID2_GPIO_PORT    	GPIOC			              /* GPIO端口 */
#define AVOID2_GPIO_CLK 	    RCC_APB2Periph_GPIOC		/* GPIO端口时钟 */
#define AVOID2_GPIO_PIN				GPIO_Pin_7			        /* 连接到SCL时钟线的GPIO */

//左3
#define AVOID3_GPIO_PORT    	GPIOC			              /* GPIO端口 */
#define AVOID3_GPIO_CLK 	    RCC_APB2Periph_GPIOC		/* GPIO端口时钟 */
#define AVOID3_GPIO_PIN				GPIO_Pin_8			        /* 连接到SCL时钟线的GPIO */

//左4
#define AVOID4_GPIO_PORT    	GPIOC			              /* GPIO端口 */
#define AVOID4_GPIO_CLK 	    RCC_APB2Periph_GPIOC		/* GPIO端口时钟 */
#define AVOID4_GPIO_PIN				GPIO_Pin_9			        /* 连接到SCL时钟线的GPIO */

//左5
#define AVOID5_GPIO_PORT    	GPIOC			              /* GPIO端口 */
#define AVOID5_GPIO_CLK 	    RCC_APB2Periph_GPIOC		/* GPIO端口时钟 */
#define AVOID5_GPIO_PIN				GPIO_Pin_10			        /* 连接到SCL时钟线的GPIO */


//左6
#define AVOID6_GPIO_PORT    	GPIOC			              /* GPIO端口 */
#define AVOID6_GPIO_CLK 	    RCC_APB2Periph_GPIOC		/* GPIO端口时钟 */
#define AVOID6_GPIO_PIN				GPIO_Pin_11			        /* 连接到SCL时钟线的GPIO */


//左7
#define AVOID7_GPIO_PORT    	GPIOC			              /* GPIO端口 */
#define AVOID7_GPIO_CLK 	    RCC_APB2Periph_GPIOC		/* GPIO端口时钟 */
#define AVOID7_GPIO_PIN				GPIO_Pin_12			        /* 连接到SCL时钟线的GPIO */








void AVOID_GPIO_Config(void);


#endif /*__AVOID_OBSTACLES_H */
