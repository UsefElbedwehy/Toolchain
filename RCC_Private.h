/***********************************************************************************/
/************** 	Author : Usef Elbedwehy              		************************************/
/**************	 	Layer : MACL 						             ***********************************/
/**************	 	SWC : RCC    						            ***********************************/
/************** 	Version : V1         						   		**********************************/
/********************************************************************************/
#ifndef   RCC_PRIVATE_H_
#define   RCC_PRIVATE_H_

#define INIT_VALUE     0
#define TIMEOUT     4000

#define READY         1
#define ONE             0x01

#define PLLM_MASK    0b111111
#define PLLN_MASK    0b111111111
#define PLLP_MASK    0b11
#define PLLQ_MASK    0b1111
#define PLLR_MASK    0b111

/* * * @ClockSrc_t * * */
typedef enum{
	PLLSAI=0,
	PLLI2S,
	PLL,
	HSE,
	HSI
}ClockSrc_t;
/* * * @State_t * * */
typedef enum{
	ON=0,
	OFF
}State_t;

/* * * @CR_t * * */
typedef enum{
	HSION=0,
	HSIRDY,
	HSEON=16,
	HSERDY,
	HSEBYP,
	CSSON,
	PLLON=24,
	PLLRDY,
	PLLI2SON,
	PLLI2SRDY,
	PLLSAION,
	PLLSAIRDY,
	
}CR_t;

/* * * @SW_t * * */
typedef enum{
	SW_HSI=0,
	SW_HSE,
	SW_PLL_P,
	SW_PLL_R

}SW_t;
/* * * @CFGR_t * * */
typedef enum{
	SW0=0,
	SW1

}CFGR_t;
/* * * @PLLSrc_t * * */
typedef enum{
	PLLSrc_HSI=0,
	PLLSrc_HSE

}PLLSrc_t;

/* * * @PPLCFGR_t * * */
typedef enum{
	PLLM=0,
	PLLN=6,
	PLLP=16,
	PLLQ=24,
	PLLR=28,
	PLLSRC=22,

}PPLCFGR_t;
/*@PLLP_t*/
typedef enum{
	PLLP2=0,
	PLLP4,
	PLLP6,
	PLLP8	
	
}PLLP_t;
/*@PLLR_t*/
typedef enum{
	PLLR2=2,
	PLLR3,
	PLLR4,
	PLLR5,
	PLLR6,
	PLLR7	
	
}PLLR_t;
/*@PLLQ_t*/
typedef enum{
	PLLQ2=2,
	PLLQ3,
	PLLQ4,
	PLLQ5,
	PLLQ6,
	PLLQ7,	
	PLLQ8,
	PLLQ9,	
	PLLQ10,	
	PLLQ11,	
	PLLQ12,	
	PLLQ13,	
	PLLQ14,	
	PLLQ15	
	
}PLLQ_t;
/**/
typedef struct{
	uint16_t PLL_M;
	uint16_t PLL_N;
	PLLP_t   PLL_P;
	PLLQ_t  PLL_Q;
	PLLR_t   PLL_R;

}PLLConfig_t;


/*@AHB1Periperals_t*/
typedef enum{
	GPIOAEN=0,
	GPIOBEN,
	GPIOCEN,
	GPIODEN,
	GPIOEEN,
	GPIOFEN,
	GPIOGEN,
	GPIOHEN,
	CRCEN=12,
	BKPSRAMEN=18,
	DMA1EN=21,
	DMA2EN,
	OTGHSEN=29,
	OTGHSULPIEN
	
}AHB1Periperals_t;
/*@AHB2Periperals_t*/
typedef enum{
	DCMIEN=0,
	OTGFSEN=7,

}AHB2Periperals_t;
/*@AHB3Periperals_t*/
typedef enum{
	FMCEN=0,
	QSPIEN=1,

}AHB3Periperals_t;
/*@APB1Peripherals_t*/
typedef enum{
	TIM2EN=0,
	TIM3EN,
	TIM4EN,
	TIM5EN,
	TIM6EN,
	TIM7EN,
	TIM12EN,
	TIM13EN,
	TIM14EN,
	WWDGEN=11,
	SPI2EN=14,
	SPI3EN,
	SPDIFRXEN,
	USART2EN,
	USART3EN,
	UART4EN,
	UART5EN,
	I2C1EN,
	I2C2EN,
	I2C3EN,
	FMPI2C1EN,
	CAN1EN,
	CAN2EN,
	CECEN,
	PWREN,
	DAC
}APB1Peripherals_t;

/*@APB2Peripherals_t*/
typedef enum{
	TIM1EN=0,
	TIM8EN,
	USART1EN=4,
	USART6EN,
	ADC1EN=8,
	ADC2EN,
	ADC3EN,
	SDIOEN,
	SPI1EN,
	SPI4EN,
	SYSCFGEN,
	TIM9EN,
	TIM10EN,
	TIM11EN,
	SAI1EN=22,
	SAI2EN
	
}APB2Peripherals_t;
#endif
