#ifndef __LED_H
#define	__LED_H


#include "stm32f10x.h"


// 左前
#define WHEEL0_GPIO_PORT    	GPIOB			              /* GPIO端口 */
#define WHEEL0_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO端口时钟 */
#define WHEEL0_GPIO_PIN				GPIO_Pin_14			        /* 连接到SCL时钟线的GPIO */

// 左后
#define WHEEL1_GPIO_PORT    	GPIOB			              /* GPIO端口 */
#define WHEEL1_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO端口时钟 */
#define WHEEL1_GPIO_PIN				GPIO_Pin_15			        /* 连接到SCL时钟线的GPIO */

// 右前
#define WHEEL2_GPIO_PORT    	GPIOB			              /* GPIO端口 */
#define WHEEL2_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO端口时钟 */
#define WHEEL2_GPIO_PIN				GPIO_Pin_13		        /* 连接到SCL时钟线的GPIO */

// 右后
#define WHEEL3_GPIO_PORT    	GPIOB			              /* GPIO端口 */
#define WHEEL3_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO端口时钟 */
#define WHEEL3_GPIO_PIN				GPIO_Pin_12		        /* 连接到SCL时钟线的GPIO */



/** the macro definition to trigger the led on or off 
  * 1 - off
  *0 - on
  */
#define ON  0
#define OFF 1

/* 使用标准的固件库控制IO*/
#define WHEEL0(a)	if (a)	\
					GPIO_SetBits(WHEEL0_GPIO_PORT,WHEEL0_GPIO_PIN);\
					else		\
					GPIO_ResetBits(WHEEL0_GPIO_PORT,WHEEL0_GPIO_PIN)

#define WHEEL1(a)	if (a)	\
					GPIO_SetBits(WHEEL1_GPIO_PORT,WHEEL1_GPIO_PIN);\
					else		\
					GPIO_ResetBits(WHEEL1_GPIO_PORT,WHEEL1_GPIO_PIN)

#define WHEEL2(a)	if (a)	\
					GPIO_SetBits(WHEEL2_GPIO_PORT,WHEEL2_GPIO_PIN);\
					else		\
					GPIO_ResetBits(WHEEL2_GPIO_PORT,WHEEL2_GPIO_PIN)
					

#define WHEEL3(a)	if (a)	\
					GPIO_SetBits(WHEEL3_GPIO_PORT,WHEEL3_GPIO_PIN);\
					else		\
					GPIO_ResetBits(WHEEL3_GPIO_PORT,WHEEL3_GPIO_PIN)



/* 直接操作寄存器的方法控制IO */
#define	digitalHi(p,i)		 {p->BSRR=i;}	 //输出为高电平		
#define digitalLo(p,i)		 {p->BRR=i;}	 //输出低电平
#define digitalToggle(p,i) {p->ODR ^=i;} //输出反转状态


/* 定义控制IO的宏 */
#define WHEEL0_ON		       digitalHi(WHEEL0_GPIO_PORT,WHEEL0_GPIO_PIN)
#define WHEEL0_OFF			   digitalLo(WHEEL0_GPIO_PORT,WHEEL0_GPIO_PIN)

#define WHEEL1_ON		       digitalHi(WHEEL1_GPIO_PORT,WHEEL1_GPIO_PIN)
#define WHEEL1_OFF			   digitalLo(WHEEL1_GPIO_PORT,WHEEL1_GPIO_PIN)


#define WHEEL2_ON		       digitalHi(WHEEL2_GPIO_PORT,WHEEL2_GPIO_PIN)
#define WHEEL2_OFF			   digitalLo(WHEEL2_GPIO_PORT,WHEEL2_GPIO_PIN)


#define WHEEL3_ON	    	   digitalHi(WHEEL3_GPIO_PORT,WHEEL3_GPIO_PIN)
#define WHEEL3_OFF			   digitalLo(WHEEL3_GPIO_PORT,WHEEL3_GPIO_PIN)





void WHEEL_GPIO_Config(void);
void Go(void);
//void Back(void);
void Turn_Right_Slow(void);
void Turn_Left_Slow(void);
//void Turn_Right_Fast(void);
//void Turn_Left_Fast(void);
void Stop(void);

#endif /* __LED_H */
