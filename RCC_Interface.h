/***********************************************************************************/
/************** 	Author : Usef Elbedwehy              		************************************/
/**************	 	Layer : MACL 						             ***********************************/
/**************	 	SWC : RCC    						            ***********************************/
/************** 	Version : V1         						   		**********************************/
/********************************************************************************/
#ifndef   RCC_INTERFACE_H_
#define   RCC_INTERFACE_H_
/*
	@fn RCC_VoidSetClkSts
	@Brief  the function Set the clock status 
	@param[in] Copy_ClkType		@ClockSrc_t
	@param[in] Copy_State 		@State_t
	@retval Local_u8ErrorState
	*/
uint8_t RCC_VoidSetClkSts(ClockSrc_t Copy_uint16ClkType,State_t Copy_uint16Status);
/*
	@fn RCC_VoidSetSysClk
	@Brief  the function Select the system clock 
	@param[in] Copy_ClkType		@ClockSrc_t
	@retval Local_u8ErrorState
	*/
uint8_t RCC_VoidSetSysClk(ClockSrc_t Copy_ClkType);

/*
	@fn RCC_VoidPLLConfig
	@Brief  the function select PLL source and PlLL multi factor 
	@param[in] PLLConfig_t			@PLLConfig_t
	@param[in] Copy_PLLSrc		@PLLSrcConfig_t
	@retval Local_u8ErrorState
	*/
uint8_t RCC_VoidPLLConfig(PLLConfig_t*  PLLConfig, PLLSrc_t Copy_PLLSrc);

/*
	@fn RCC_AHB1EnableClock
	@Brief  the function enables AHB1 Clock 
	@param[in] Copy_Peripheral			@AHBPeriperals_t
	@retval void
	*/
void RCC_AHB1EnableClock(AHB1Periperals_t Copy_Peripheral);
/*
	@fn RCC_AHB1DisableClock
	@Brief  the function disables AHB1 Clock 
	@param[in] Copy_Peripheral			@AHBPeriperals_t
	@retval void
	*/
void RCC_AHB1DisableClock(AHB1Periperals_t Copy_Peripheral);

/*
	@fn RCC_AHB1EnableClock
	@Brief  the function enables AHB2 Clock 
	@param[in] Copy_Peripheral			@AHB2Periperals_t
	@retval void
	*/
void RCC_AHB2EnableClock(AHB2Periperals_t Copy_Peripheral);
/*
	@fn RCC_AHB2DisableClock
	@Brief  the function disables AHB2 Clock 
	@param[in] Copy_Peripheral			@AHB2Periperals_t
	@retval void
	*/
void RCC_AHB2DisableClock(AHB2Periperals_t Copy_Peripheral);

/*
	@fn RCC_AHB3EnableClock
	@Brief  the function enables AHB3 Clock 
	@param[in] Copy_Peripheral			@AHB3Periperals_t
	@retval void
	*/
void RCC_AHB3EnableClock(AHB3Periperals_t Copy_Peripheral);
/*
	@fn RCC_AHB3DisableClock
	@Brief  the function disables AHB3 Clock 
	@param[in] Copy_Peripheral			@AHB3Periperals_t
	@retval void
	*/
void RCC_AHB3DisableClock(AHB3Periperals_t Copy_Peripheral);

/*
	@fn RCC_APB1EnableClock
	@Brief  the function enables APB1 Clock 
	@param[in] Copy_Peripheral			@APB1Peripherals_t
	@retval void
	*/
void RCC_APB1EnableClock(APB1Peripherals_t Copy_Peripheral);
/*
	@fn RCC_APB1DisableClock
	@Brief  the function disables APB1 Clock 
	@param[in] Copy_Peripheral			@APB1Peripherals_t
	@retval void
	*/
void RCC_APB1DisableClock(APB1Peripherals_t Copy_Peripheral);

/*
	@fn RCC_APB2EnableClock
	@Brief  the function enables APB2 Clock 
	@param[in] Copy_Peripheral			@APB2Peripherals_t
	@retval void
	*/
void RCC_APB2EnableClock(APB2Peripherals_t Copy_Peripheral);
/*
	@fn RCC_APB2DisableClock
	@Brief  the function disables APB2 Clock 
	@param[in] Copy_Peripheral			@APB2Peripherals_t
	@retval void
	*/
void RCC_APB2DisableClock(APB2Peripherals_t Copy_Peripheral);



#endif
