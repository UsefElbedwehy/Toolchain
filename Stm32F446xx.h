#ifndef  STM32F446XX_H_
#define  STM32F446XX_H_ 
/**************Core peripherals Base Addresses***************/
#define	SYSTICK_BASE_ADDRESS		0xE000E010UL
#define NVIC_BASE_ADDRESS 			0xE000E100UL			/*NESTED VECTOR INTERRUPT CONTROL BASE ADDRESS*/
#define SCB_BASE_ADDRESS			0xE000E008UL			/*SYSTEM CONTROL BLOCK BASE ADDRESS*/

/**************Various Memory Base Addresses***************/
#define SRAM_BASE_ADRRESS  					0x20000000UL
#define FLASH_BASE_ADRRESS 					0x08000000UL
#define SYSTEM_MEMORY_BASE_ADRRESS 	  		0x1FFF0000UL

/***************APB1 Peripherals Base Addresses****************/

/***************APB2 Peripherals Base Addresses****************/
#define EXTI_BASE_ADDRESS					0x40013C00UL			/*EXTERNAL INTERRUPT BASE ADDRESS*/
#define SYSCFG_BASE_ADDRESS					0x40013800UL

/***************APB3 Peripherals Base Addresses****************/

/***************AHB1 Peripherals Base Addresses****************/
#define GPIOA_BASE_ADDRESS					0x40020000UL      /*GENERAL PURPOSE INPUT OUTPOT (PORTA) BASE ADDRESS*/
#define GPIOB_BASE_ADDRESS					0x40020400UL      /*GENERAL PURPOSE INPUT OUTPOT (PORTB) BASE ADDRESS*/
#define GPIOC_BASE_ADDRESS					0x40020800UL      /*GENERAL PURPOSE INPUT OUTPOT (PORTC) BASE ADDRESS*/
#define GPIOD_BASE_ADDRESS					0x40020C00UL      /*GENERAL PURPOSE INPUT OUTPOT (PORTD) BASE ADDRESS*/
#define GPIOE_BASE_ADDRESS		    		0x40021000UL      /*GENERAL PURPOSE INPUT OUTPOT (PORTE) BASE ADDRESS*/
#define GPIOF_BASE_ADDRESS		    		0x40021400UL      /*GENERAL PURPOSE INPUT OUTPOT (PORTF) BASE ADDRESS*/
#define GPIOG_BASE_ADDRESS					0x40021800UL      /*GENERAL PURPOSE INPUT OUTPOT (PORTG) BASE ADDRESS*/
#define GPIOH_BASE_ADDRESS					0x40021C00UL      /*GENERAL PURPOSE INPUT OUTPOT (PORTH) BASE ADDRESS*/

#define RCC_BASE_ADDRESS          			0x40023800UL      /*RESET AND CLOCK CONTROL BASE ADDRESS*/

#define USB_OTG_HS_BASE_ADDRESS				0x40040000UL

#define DMA2_BASE_ADDRESS					0x40026400UL		/*DIRECT MEMORY ACCESS 2 BASE ADDRESS*/
#define DMA1_BASE_ADDRESS					0x40026000UL		/*DIRECT MEMORY ACCESS 1 BASE ADDRESS*/

#define BKPSRAM_BASE_ADDRESS				0x40024000UL
#define FLASH_I_R_BASE_ADDRESS				0x40023C00UL      /*FLASH INTERFACE REGISTER BASE ADDRESS*/
#define CRC_BASE_ADDRESS					0x40023000UL	   /*CYCLIC REDUNDANCY CHECH BASE ADDRESS*/


/***************AHB2 Peripherals Base Addresses****************/

/***************AHB3 Peripherals Base Addresses****************/

/***************RCC Register Definition Structure****************/
typedef struct{
	volatile uint32_t RCC_CR;
	volatile uint32_t RCC_PLLCFGR;
	volatile uint32_t RCC_CFGR;
	volatile uint32_t RCC_CIR;
	volatile uint32_t RCC_AHB1RSTR;
	volatile uint32_t RCC_AHB2RSTR;
	volatile uint32_t RCC_AHB3RSTR;
	volatile uint32_t RCC_Reserved1;
	volatile uint32_t RCC_APB1RSTR;
	volatile uint32_t RCC_APB2RSTR;
	volatile uint32_t RCC_Reserved2;
	volatile uint32_t RCC_Reserved3;
	volatile uint32_t RCC_AHB1ENR;
	volatile uint32_t RCC_AHB2ENR;
	volatile uint32_t RCC_AHB3ENR;
	volatile uint32_t RCC_Reserved4;
	volatile uint32_t RCC_APB1ENR;
	volatile uint32_t RCC_APB2ENR;
	volatile uint32_t Reserved5;
	volatile uint32_t Reserved6;
	volatile uint32_t RCC_AHB1LPENR;
	volatile uint32_t RCC_AHB2LPENR;
	volatile uint32_t RCC_AHB3LENR;
	volatile uint32_t RCC_Reserved7;
	volatile uint32_t RCC_APB1LPENR;
	volatile uint32_t RCC_APB2LPENR;
	volatile uint32_t Reserved8;
	volatile uint32_t Reserved9;
	volatile uint32_t RCC_BDCR;
	volatile uint32_t RCC_CSR;
	volatile uint32_t Reserved10;
	volatile uint32_t Reserved11 ;
	volatile uint32_t RCC_SSCGR;
	volatile uint32_t RCC_PLLI2SCFGR;
	volatile uint32_t RCC_PLLSAICFGR;
	volatile uint32_t RCC_DCKCFGR;
	volatile uint32_t RCC_CKGATENR;
	volatile uint32_t RCC_DCKCFGR2;

}RCC_RegDef_t;

/***************RCC Register Definition ****************/
#define RCC 		 ((RCC_RegDef_t*)RCC_BASE_ADDRESS)

/***************GPIO Register Definition Structure****************/
typedef struct{
	volatile uint32_t GPIO_MODER;			  /*GPIO PORT Mode Register*/
	volatile uint32_t GPIO_OTYPE;             /*GPIO PORT Output Type Register*/
	volatile uint32_t GPIO_OSPEEDER;      /*GPIO PORT Output Speed Register*/
	volatile uint32_t GPIO_PUPDR;            /*GPIO PORT Pull Up/Down Register*/
	volatile uint32_t GPIO_IDR;                /*GPIO PORT Input Data Register*/
	volatile uint32_t GPIO_ODR;               /*GPIO PORT Output Data Register*/
	volatile uint32_t GPIO_BSRR;             /*GPIO PORT Bit Set/Reset Register*/
	volatile uint32_t GPIO_LCKR;             /*GPIO PORT Lock Register*/
	volatile uint32_t GPIO_AFR[2];          /*GPIO PORT Alternative Function Register*/

}GPIO_RegDef_t;

/***************GPIO Register Definition ****************/
#define GPIOA	   ((GPIO_RegDef_t*)GPIOA_BASE_ADDRESS)
#define GPIOB      ((GPIO_RegDef_t*)GPIOB_BASE_ADDRESS)
#define GPIOC      ((GPIO_RegDef_t*)GPIOC_BASE_ADDRESS)
#define GPIOD      ((GPIO_RegDef_t*)GPIOD_BASE_ADDRESS)
#define GPIOE      ((GPIO_RegDef_t*)GPIOE_BASE_ADDRESS)
#define GPIOF      ((GPIO_RegDef_t*)GPIOF_BASE_ADDRESS)
#define GPIOG      ((GPIO_RegDef_t*)GPIOG_BASE_ADDRESS)
#define GPIOH      ((GPIO_RegDef_t*)GPIOH_BASE_ADDRESS)

/***************SYSTICK Register Definition Structure****************/
typedef struct{
	volatile uint32_t SYSTICK_CSR;   /*SysTick Control and Status Register-RW*/
	volatile uint32_t SYSTICK_RVR;   /*SysTick Reload Value Register-RW*/
	volatile uint32_t SYSTICK_CVR;   /*SysTick Current Value Register-RW*/
	volatile uint32_t SYSTICK_CALIB; /*SysTick Calibration Value Register-RO*/

}SYSTICK_Reg_t;
/***************SYSTICK Register Definition ****************/
#define SYSTICK 		((SYSTICK_Reg_t*)SYSTICK_BASE_ADDRESS)

/***************NVIC Register Definition Structure****************/
typedef struct{
	volatile uint32_t NVIC_ISER[8];
	volatile uint32_t RESERVED1[24];
	volatile uint32_t NVIC_ICER[8];
	volatile uint32_t RESERVED2[24];
	volatile uint32_t NVIC_ISPR[8];
	volatile uint32_t RESERVED3[24];
	volatile uint32_t NVIC_ICPR[8];
	volatile uint32_t RESERVED4[24];
	volatile uint32_t NVIC_IABR[8];
	volatile uint32_t RESERVED5[56];
	volatile uint8_t NVIC_IPR[240];
	volatile uint32_t RESERVED6[643];
	volatile uint32_t NVIC_STIR;

}NVIC_RegDef_t;
/***************NVIC Register Definition ****************/
#define NVIC 		((NVIC_RegDef_t*)NVIC_BASE_ADDRESS)

/***************SCB Register Definition Structure****************/
typedef struct{
	volatile uint32_t  SCB_ACTLR;    /* CPUID Base Register-RO*/
	uint32_t  REVERSED0[829];
	volatile uint32_t  SCB_CPUID;    /* CPUID Base Register-RO*/
	volatile uint32_t  SCB_ICSR;     /* Interrupt Control and State Register-RW*/
	volatile uint32_t  SCB_VTOR;     /* Vector Table Offset Register-RW*/
	volatile uint32_t  SCB_AIRCR;    /* Application Interrupt and Reset Control Register-RW*/
	volatile uint32_t  SCB_SCR;      /* System Control Register-RW*/
	volatile uint32_t  SCB_CCR;      /* Configuration and Control Register-RW*/
	volatile uint32_t  SCB_SHPR1;    /* System Handler Priority Register 1-RW*/
	volatile uint32_t  SCB_SHPR2;    /* System Handler Priority Register 2-RW*/
	volatile uint32_t  SCB_SHPR3;    /* System Handler Priority Register 3-RW*/
	volatile uint32_t  SCB_SHCRS;    /* System Handler Control and State Register-RW*/
	volatile uint8_t  SCB_MMSR;     /* MemManage Fault Status Register-RW*/
	volatile uint8_t  SCB_BFSR;     /* BusFault Status Register-RW*/
	volatile uint16_t  SCB_UFSR;     /* UsageFault Status Register-RW-RW*/
	volatile uint32_t  SCB_HFSR;     /* HardFault Status Register-RW*/
	uint32_t REVERSED1;
	volatile uint32_t  SCB_MMAR;     /* MemManage Fault Address Register-RW*/
	volatile uint32_t  SCB_BFAR;     /* BusFault Address Register-RW*/
	volatile uint32_t  SCB_AFSR;     /* Auxiliary Fault Status Register-RW*/

}SCB_RegDef_t;
/***************SCB Register Definition ****************/
#define SCB 		((SCB_RegDef_t*)SCB_BASE_ADDRESS)

/***************SYSCFG Register Definition Structure****************/
typedef struct{
	volatile uint32_t SYSCFG_MEMRMP;
	volatile uint32_t SYSCFG_PMC;
	volatile uint32_t SYSCFG_EXTICR[4];
	volatile uint32_t SYSCFG_CMPCR;
	volatile uint32_t SYSCFG_CFGR;

}SYSCFG_RegDef_t;
/***************SCB Register Definition ****************/
#define SYSCFG ((SYSCFG_RegDef_t*)SYSCFG_BASE_ADDRESS)

/***************EXTI Register Definition Structure****************/
typedef struct{
	volatile uint32_t EXTI_IMR;
	volatile uint32_t EXTI_EMR;
	volatile uint32_t EXTI_RTSR;
	volatile uint32_t EXTI_FTSR;
	volatile uint32_t EXTI_SWIER;
	volatile uint32_t EXTI_PR;

}EXTI_Reg_t;
/***************EXTI Register Definition ****************/
#define EXTI		((EXTI_Reg_t*)EXTI_BASE_ADDRESS)
/***************DMA Register Definition Structure****************/
typedef struct{
	volatile uint32_t DMA_LISR;
	volatile uint32_t DMA_HISR;
	volatile uint32_t DMA_LIFCR;
	volatile uint32_t DMA_HIFCR;
	volatile uint32_t DMA_S0CR;
	volatile uint32_t DMA_S0NDTR;
	volatile uint32_t DMA_S0PAR;
	volatile uint32_t DMA_S0M0AR;
	volatile uint32_t DMA_S0M1AR;
	volatile uint32_t DMA_S0FCR;
	volatile uint32_t DMA_S1CR;
	volatile uint32_t DMA_S1NDTR;
	volatile uint32_t DMA_S1PAR;
	
	volatile uint32_t DMA_S1M0AR;
	volatile uint32_t DMA_S1M1AR;
	volatile uint32_t DMA_S1FCR;
	volatile uint32_t DMA_S2CR;
	volatile uint32_t DMA_S2NDTR;
	volatile uint32_t DMA_S2PAR;
	volatile uint32_t DMA_S2M0AR;
	volatile uint32_t DMA_S2M1AR;
	volatile uint32_t DMA_S2FCR;
	volatile uint32_t DMA_S3CR;
	volatile uint32_t DMA_S3NDTR;
	volatile uint32_t DMA_S3PAR;
	volatile uint32_t DMA_S3M0AR;
	volatile uint32_t DMA_S3M1AR;
	
	volatile uint32_t DMA_S3FCR;
	volatile uint32_t DMA_S4CR;
	volatile uint32_t DMA_S4NDTR;
	volatile uint32_t DMA_S4PAR;
	volatile uint32_t DMA_S4M0AR;
	volatile uint32_t DMA_S4M1AR;
	volatile uint32_t DMA_S4FCR;
	volatile uint32_t DMA_S5CR;
	volatile uint32_t DMA_S5NDTR;
	volatile uint32_t DMA_S5PAR;
	volatile uint32_t DMA_S5M0AR;
	volatile uint32_t DMA_S5M1AR;
	volatile uint32_t DMA_S5FCR;
	
	volatile uint32_t DMA_S6CR;
	volatile uint32_t DMA_S6NDTR;
	volatile uint32_t DMA_S6PAR;
	volatile uint32_t DMA_S6M0AR;
	volatile uint32_t DMA_S6M1AR;
	volatile uint32_t DMA_S6FCR;
	volatile uint32_t DMA_S7CR;
	volatile uint32_t DMA_S7NDTR;
	volatile uint32_t DMA_S7PAR;
	volatile uint32_t DMA_S7M0AR;
	volatile uint32_t DMA_S7M1AR;
	volatile uint32_t DMA_S7FCR;
	
}DMA_Reg_t;
/***************DMA Register Definition ****************/
#define	 DMA2	((DMA_Reg_t*)DMA2_BASE_ADDRESS)
#define	 DMA1	((DMA_Reg_t*)DMA1_BASE_ADDRESS)

#endif
