#ifndef __LED_H
#define	__LED_H


#include "stm32f10x.h"


// ��ǰ
#define WHEEL0_GPIO_PORT    	GPIOB			              /* GPIO�˿� */
#define WHEEL0_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO�˿�ʱ�� */
#define WHEEL0_GPIO_PIN				GPIO_Pin_14			        /* ���ӵ�SCLʱ���ߵ�GPIO */

// ���
#define WHEEL1_GPIO_PORT    	GPIOB			              /* GPIO�˿� */
#define WHEEL1_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO�˿�ʱ�� */
#define WHEEL1_GPIO_PIN				GPIO_Pin_15			        /* ���ӵ�SCLʱ���ߵ�GPIO */

// ��ǰ
#define WHEEL2_GPIO_PORT    	GPIOB			              /* GPIO�˿� */
#define WHEEL2_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO�˿�ʱ�� */
#define WHEEL2_GPIO_PIN				GPIO_Pin_13		        /* ���ӵ�SCLʱ���ߵ�GPIO */

// �Һ�
#define WHEEL3_GPIO_PORT    	GPIOB			              /* GPIO�˿� */
#define WHEEL3_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO�˿�ʱ�� */
#define WHEEL3_GPIO_PIN				GPIO_Pin_12		        /* ���ӵ�SCLʱ���ߵ�GPIO */



/** the macro definition to trigger the led on or off 
  * 1 - off
  *0 - on
  */
#define ON  0
#define OFF 1

/* ʹ�ñ�׼�Ĺ̼������IO*/
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



/* ֱ�Ӳ����Ĵ����ķ�������IO */
#define	digitalHi(p,i)		 {p->BSRR=i;}	 //���Ϊ�ߵ�ƽ		
#define digitalLo(p,i)		 {p->BRR=i;}	 //����͵�ƽ
#define digitalToggle(p,i) {p->ODR ^=i;} //�����ת״̬


/* �������IO�ĺ� */
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
