/***********************************************************************************/
/************** 	Author : Usef Elbedwehy              		************************************/
/**************	 	Layer : MACL 						             ***********************************/
/**************	 	SWC : RCC    						            ***********************************/
/************** 	Version : V1         						   		**********************************/
/********************************************************************************/

#include <stdint.h>
#include "ErrType.h"
#include "Stm32F446xx.h"
#include "RCC_Private.h"
#include "RCC_Interface.h"


/*
	@fn RCC_VoidSetClkSts
	@Brief  the function Set the clock status 
	@param[in] Copy_ClkType		@ClockSrc_t
	@param[in] Copy_State 		@State_t
	@retval Local_u8ErrorState
 */
uint8_t RCC_VoidSetClkSts(ClockSrc_t    Copy_ClkType, State_t    Copy_State)
{
	uint8_t 		Local_u8ErrorState=OK;
	uint16_t  	Local_TimeOut=INIT_VALUE;
	switch(Copy_ClkType)
	{
	/* * * * * * * * HSI * * * * * * *
	 * * * HIGH SPEED INTERNAL * * *
	 * * * * * * * * * * * * * * * * */
	case HSI:
		if(Copy_State == ON)
		{
			/*Internal high-speed clock enable*/
			(RCC->RCC_CR) |= (ONE<<HSION);
			/*Checking HSI ready flag*/
			while( ((((RCC->RCC_CR)>>HSIRDY)&ONE)!=READY)  &&  (Local_TimeOut<TIMEOUT) )
			{
				/*Waiting but with timeout*/
				Local_TimeOut++;
			}
		}
		else if(Copy_State == OFF)
		{
			/*Internal high-speed clock disable*/
			(RCC->RCC_CR) &=~ (ONE<<HSION);
		}
		else{
			Local_u8ErrorState=NOK;
		}
		break;
		/* * * * * * * * HSE * * * * * * * 
		 * * * HIGH SPEED EXTERNAL * * *
		 * * * * * * * * * * * * * * * * */
	case HSE:
		if(Copy_State == ON)
		{
			/*External high-speed clock enable*/
			(RCC->RCC_CR) |= (ONE<<HSEON);
			/*Checking HSE ready flag*/
			while( ((((RCC->RCC_CR)>>HSERDY)&ONE)!=READY)  &&  (Local_TimeOut<TIMEOUT) )
			{
				/*Waiting but with timeout*/
				Local_TimeOut++;
			}
		}
		else if(Copy_State == OFF)
		{
			/*External high-speed clock disable*/
			(RCC->RCC_CR) &=~ (ONE<<HSEON);
		}
		else{
			Local_u8ErrorState=NOK;
		}
		break;
		/* * * * * * * * PLL * * * * * * * 
		 * * * PHASE LOCKED LOOP * * *
		 * * * * * * * * * * * * * * * * */
	case PLL:
		if(Copy_State == ON)
		{
			/*main PLL clock enable*/
			(RCC->RCC_CR) |= (ONE<<PLLON);
			/*Checking main PLL ready flag*/
			while( ((((RCC->RCC_CR)>>PLLRDY)&ONE)!=READY)  &&  (Local_TimeOut<TIMEOUT) )
			{
				/*Waiting but with timeout*/
				Local_TimeOut++;
			}
		}
		else if(Copy_State == OFF)
		{
			/*main PPL clock disable*/
			(RCC->RCC_CR) &=~ (ONE<<PLLON);
		}
		else{
			Local_u8ErrorState=NOK;
		}
		break;
		/* * * * * * * * PLLI2S * * * * * * * 
		 * * * PHASE LOCKED LOOP * * *
		 * * * * * * * * * * * * * * * * */
	case PLLI2S:
		if(Copy_State == ON)
		{
			/*main PLL clock enable*/
			(RCC->RCC_CR) |= (ONE<<PLLI2SON);
			/*Checking main PLL ready flag*/
			while( ((((RCC->RCC_CR)>>PLLI2SRDY)&ONE)!=READY)  &&  (Local_TimeOut<TIMEOUT) )
			{
				/*Waiting but with timeout*/
				Local_TimeOut++;
			}
		}
		else if(Copy_State == OFF)
		{
			/*main PPL clock disable*/
			(RCC->RCC_CR) &=~ (ONE<<PLLI2SON);
		}
		else{
			Local_u8ErrorState=NOK;
		}
		break;

		/* * * * * * * * PLLSAI * * * * * * * 
		 * * * PHASE LOCKED LOOP * * *
		 * * * * * * * * * * * * * * * * */
	case PLLSAI:
		if(Copy_State == ON)
		{
			/*main PLL clock enable*/
			(RCC->RCC_CR) |= (ONE<<PLLSAION);
			/*Checking main PLL ready flag*/
			while( ((((RCC->RCC_CR)>>PLLSAIRDY)&ONE)!=READY)  &&  (Local_TimeOut<TIMEOUT) )
			{
				/*Waiting but with timeout*/
				Local_TimeOut++;
			}
		}
		else if(Copy_State == OFF)
		{
			/*main PPL clock disable*/
			(RCC->RCC_CR) &=~ (ONE<<PLLSAION);
		}
		else{
			Local_u8ErrorState=NOK;
		}
		break;
	default: Local_u8ErrorState=NOK; break;
	}

	return Local_u8ErrorState;
}
/*
	@fn RCC_VoidSetSysClk
	@Brief  the function Select the system clock 
	@param[in] Copy_ClkType		@ClockSrc_t
	@retval Local_u8ErrorState
 */
uint8_t RCC_VoidSetSysClk(ClockSrc_t  Copy_ClkType)
{
	uint8_t 		Local_u8ErrorState=OK;

	switch(Copy_ClkType)
	{
	case SW_HSI:
		/*HSI oscillator selected as system clock*/
		(RCC->RCC_CFGR) &=~ (ONE<<SW0); 
		(RCC->RCC_CFGR) &=~ (ONE<<SW1); 	
		break;
	case SW_HSE:
		/*HSE oscillator selected as system clock*/
		(RCC->RCC_CFGR) |= (ONE<<SW0); 
		(RCC->RCC_CFGR) &=~ (ONE<<SW1); 	
		break;
	case SW_PLL_P:
		/*PLL_P selected as system clock*/
		(RCC->RCC_CFGR) &=~ (ONE<<SW0); 
		(RCC->RCC_CFGR) |= (ONE<<SW1); 	
		break;
	case SW_PLL_R:
		/*PLL_R selected as system clock*/
		(RCC->RCC_CFGR) |= (ONE<<SW0); 
		(RCC->RCC_CFGR) |= (ONE<<SW1); 	
		break;
	default: Local_u8ErrorState=NOK; break;
	}

	return Local_u8ErrorState;
}
/*
	@fn RCC_VoidPLLConfig
	@Brief  the function select PLL source and PlLL multi factor 
	@param[in] PLLConfig_t			@PLLConfig_t
	@param[in] Copy_PLLSrc		@PLLSrcConfig_t
	@retval Local_u8ErrorState
 */
uint8_t RCC_VoidPLLConfig(PLLConfig_t*  PLLConfig, PLLSrc_t Copy_PLLSrc)
{
	uint8_t 	Local_u8ErrorState=OK;
	/*PLL SOURCE*/
	switch(Copy_PLLSrc)
	{
	case PLLSrc_HSI:
		/*HSI clock selected as PLL and PLLI2S clock entry*/
		(RCC->RCC_PLLCFGR) &=~ (ONE << PLLSRC) ;		
		break;
		/*HSE oscillator clock selected as PLL and PLLI2S clock entry*/
	case PLLSrc_HSE:
		(RCC->RCC_PLLCFGR) |=  (ONE << PLLSRC) ;		
		break;
	default: Local_u8ErrorState=NOK; break;
	}	 	
	/*PLLM
	from 2 to63
	 */
	(RCC->RCC_PLLCFGR) &=~  (PLLM_MASK << PLLM) ;
	(RCC->RCC_PLLCFGR) |=  ((PLLConfig->PLL_M) << PLLM) ;
	/*PLLN
	from 50 to 432
	 */
	(RCC->RCC_PLLCFGR) &=~  (PLLN_MASK << PLLN) ;
	(RCC->RCC_PLLCFGR) |=  ((PLLConfig->PLL_N) << PLLN) ;
	/*PLLP
	2 , 4 ,6 ,8
	 */
	(RCC->RCC_PLLCFGR) &=~  (PLLP_MASK << PLLP) ;
	(RCC->RCC_PLLCFGR) |=  ((PLLConfig->PLL_P) << PLLM) ;
	/*PLLQ
	from 2 to 15
	 */
	(RCC->RCC_PLLCFGR) &=~  (PLLQ_MASK << PLLQ) ;
	(RCC->RCC_PLLCFGR) |=  ((PLLConfig->PLL_Q) << PLLQ) ;	
	/*PLLR
	from 2 to 7
	 */
	(RCC->RCC_PLLCFGR) &=~  (PLLR_MASK << PLLR) ;
	(RCC->RCC_PLLCFGR) |=  ((PLLConfig->PLL_R) << PLLR) ;	



	return Local_u8ErrorState;
}
/*
	@fn RCC_AHB1EnableClock
	@Brief  the function enables AHB1 Clock 
	@param[in] Copy_Peripheral			@AHB1Periperals_t
	@retval void
 */
void RCC_AHB1EnableClock(AHB1Periperals_t     Copy_Peripheral)
{
	/*Enable the peripheraL*/
	RCC->RCC_AHB1ENR |= (ONE << Copy_Peripheral);
}
/*
	@fn RCC_AHB1DisableClock
	@Brief  the function disables AHB1 Clock 
	@param[in] Copy_Peripheral			@AHB1Periperals_t
	@retval void
 */
void RCC_AHB1DisableClock(AHB1Periperals_t Copy_Peripheral)
{
	/*Disable the peripheraL*/
	RCC->RCC_AHB1ENR &=~ (ONE << Copy_Peripheral);
}
/*
	@fn RCC_AHB1EnableClock
	@Brief  the function enables AHB2 Clock 
	@param[in] Copy_Peripheral			@AHB2Periperals_t
	@retval void
 */
void RCC_AHB2EnableClock(AHB2Periperals_t     Copy_Peripheral)
{
	/*Enable the peripheraL*/
	RCC->RCC_AHB2ENR |= (ONE << Copy_Peripheral);
}
/*
	@fn RCC_AHB2DisableClock
	@Brief  the function disables AHB2 Clock 
	@param[in] Copy_Peripheral			@AHB2Periperals_t
	@retval void
 */
void RCC_AHB2DisableClock(AHB2Periperals_t Copy_Peripheral)
{
	/*Disable the peripheraL*/
	RCC->RCC_AHB2ENR &=~ (ONE << Copy_Peripheral);
}
/*
	@fn RCC_AHB3EnableClock
	@Brief  the function enables AHB3 Clock 
	@param[in] Copy_Peripheral			@AHB3Periperals_t
	@retval void
 */
void RCC_AHB3EnableClock(AHB3Periperals_t Copy_Peripheral)
{
	/*Enable the peripheraL*/
	RCC->RCC_AHB3ENR |= (ONE << Copy_Peripheral);
}
/*
	@fn RCC_AHB3DisableClock
	@Brief  the function disables AHB3 Clock 
	@param[in] Copy_Peripheral			@AHB3Periperals_t
	@retval void
 */
void RCC_AHB3DisableClock(AHB3Periperals_t Copy_Peripheral)
{
	/*Disable the peripheraL*/
	RCC->RCC_AHB3ENR &=~ (ONE << Copy_Peripheral);
}
/*
	@fn RCC_APB1EnableClock
	@Brief  the function enables APB1 Clock 
	@param[in] Copy_Peripheral			@APB1Peripherals_t
	@retval void
 */
void RCC_APB1EnableClock(APB1Peripherals_t Copy_Peripheral)
{
	/*Enable the peripheraL*/
	RCC->RCC_APB1ENR |= (ONE << Copy_Peripheral);
}
/*
	@fn RCC_APB1DisableClock
	@Brief  the function disables APB1 Clock 
	@param[in] Copy_Peripheral			@APB1Peripherals_t
	@retval void
 */
void RCC_APB1DisableClock(APB1Peripherals_t Copy_Peripheral)
{
	/*Disable the peripheraL*/
	RCC->RCC_APB1ENR &=~ (ONE << Copy_Peripheral);
}

/*
	@fn RCC_APB2EnableClock
	@Brief  the function enables APB2 Clock 
	@param[in] Copy_Peripheral			@APB2Peripherals_t
	@retval void
 */
void RCC_APB2EnableClock(APB2Peripherals_t Copy_Peripheral)
{
	/*Enable the peripheraL*/
	RCC->RCC_APB2ENR |= (ONE << Copy_Peripheral);
}
/*
	@fn RCC_APB2DisableClock
	@Brief  the function disables APB2 Clock 
	@param[in] Copy_Peripheral			@APB2Peripherals_t
	@retval void
 */
void RCC_APB2DisableClock(APB2Peripherals_t Copy_Peripheral)
{
	/*Disable the peripheraL*/
	RCC->RCC_APB2ENR &=~ (ONE << Copy_Peripheral);
}

