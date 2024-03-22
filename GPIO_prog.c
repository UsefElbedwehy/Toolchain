/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @file GPIO_prog.c
 * @author Usef Elbedwehy
 * @brief The main GPIO main source file, including function's definitions
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
#include <stdint.h>
#include "Stm32F446xx.h"
#include "ErrType.h"
#include "GPIO_interface.h"
#include "GPIO_prv.h"

/*
 * * * * * * * * * * * * * * * * *
          GPIO ARRAY
 * * * * * * * * * * * * * * * * *
 */
static GPIO_RegDef_t* GPIOx[GPIO_PERIPHERAL_NUM]={	GPIOA,
		GPIOB,
		GPIOC,
		GPIOD,
		GPIOE,
		GPIOF,
		GPIOG,
		GPIOH};
/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
							GPIO INITIALIZATION
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @fn GPIO_u8PinInit
 * @brief the function initiatizes the GPIO pin according to
 *  the input parameters
 * @param[in] PinConfig: the initialization value of pins
 * @retval Local_u8ErrorState
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	 PinConfig:	Port,
				PinNum,
				Mode,
				Speed,
				OutputType,
				PullType,
				AltFunc
 */
uint8_t GPIO_u8PinInit(const PinConfig_t* PinConfig)
{
	uint8_t Local_u8ErrorState=OK;
	/*Check weather the pointer points to Null or Not*/
	if(PinConfig != NULL)
	{
		/* * * * * Select GPIO Mode: Input, Output, Analog, AltFunc * * * * */
		(GPIOx[PinConfig->Port]->GPIO_MODER) &=~(MODER_MASK<<(MODER_PIN_ACCESS* (PinConfig->PinNum)));
		(GPIOx[PinConfig->Port]->GPIO_MODER) |=((PinConfig->Mode)<<(MODER_PIN_ACCESS* (PinConfig->PinNum)));

		/* * * * * Select GPIO Pull State: PullUp ,PullDown ,NoPull * * * * */
		(GPIOx[PinConfig->Port]->GPIO_PUPDR) &=~(PUPDR_MASK<<(PUPDR_PIN_ACCESS* (PinConfig->PinNum)));
		(GPIOx[PinConfig->Port]->GPIO_PUPDR) |=((PinConfig->PullType)<<(PUPDR_PIN_ACCESS* (PinConfig->PinNum)));

		/*IF Condition: TO check weather it is OUTPUT or ALTERNATIVE_FUNCTION
		 *
		 * IF OUTPUT MODE: OutputType AND OutputSpeed (Setting)
		 *
		 * IF ALTERNATE FUNCTION: OutputType AND OutputSpeed AND ALTERNATIVE FUNCTION (Setting)
		 *
		 * */
		if( ( (PinConfig->Mode) ==OUTPUT) || ( (PinConfig->Mode) ==ALTERNATIVE_FUNCTION) )
		{
			/* * * * * Select the OutputType: PushPull ,Open Drain * * * * */
			(GPIOx[PinConfig->Port]->GPIO_OTYPE) &=~(OTYPER_MASK<<(PinConfig->PinNum));
			(GPIOx[PinConfig->Port]->GPIO_OTYPE) |=((PinConfig->OutputType)<<(PinConfig->PinNum));

			/* * * * * Select the OutputSpeed:Low, Medium, Fast, High * * * * */
			(GPIOx[PinConfig->Port]->GPIO_OSPEEDER) &=~(OSPEEDR_MASK<<(OSPEEDR_PIN_ACCESS*(PinConfig->PinNum)));
			(GPIOx[PinConfig->Port]->GPIO_OSPEEDER) |=((PinConfig->Speed)<<(OSPEEDR_PIN_ACCESS*(PinConfig->PinNum)));

			/* * * * * Select the Pin Alternate Function * * * * */
			if((PinConfig->Mode)==ALTERNATIVE_FUNCTION)
			{
				/* * * * * ALTERNATIVE FUNCTION * * * * */
				uint8_t Local_u8RegNum = (PinConfig->PinNum) / AFR_PIN_SHIFTING;
				uint8_t Local_u8BitNum = (PinConfig->PinNum) % AFR_PIN_SHIFTING;
				GPIOx[PinConfig->Port]->GPIO_AFR[Local_u8RegNum] &=~(AFR_MASK<<(AFR_PIN_ACCESS*(Local_u8BitNum)));
				GPIOx[PinConfig->Port]->GPIO_AFR[Local_u8RegNum] |=((PinConfig->AltFunc)<<(AFR_PIN_ACCESS*(Local_u8BitNum)));
			}

		}

	}
	else
	{
		/*Null pointer*/
		Local_u8ErrorState=NULL_POINTER;
	}
	return Local_u8ErrorState;
}
/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                            GPIO SET PIN VALUE
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @fn GPIO_u8SetPinValue
 * @brief the function Set the GPIO pin value
 * @param[in] Port ,PinNum ,PinVal
 * @retval Local_u8ErrorState
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
uint8_t GPIO_u8SetPinValue(Port_t	Port , Pin_t	PinNum , PinVal_t PinVal)
{
	uint8_t Local_u8ErrorState=OK;
	if((Port <= PORTH) && (PinNum <= PIN15))
	{
		if(PinVal==PIN_HIGH)
		{
			/*Set PIN*/
			GPIOx[Port]->GPIO_ODR |= (0x01<<(PinNum));
			/*GPIOx[Port]->GPIO_BSRR = (0x01<<(16+PinNum));*/
		}
		else if(PinVal==PIN_LOW)
		{
			/*Clear PIN*/
			GPIOx[Port]->GPIO_ODR &= ~(0x01<<(PinNum));
			/*GPIOx[Port]->GPIO_BSRR = (0x01<<(PinNum));*/
		}
		else
		{
			Local_u8ErrorState=NOK;
		}
	}
	else
	{
		Local_u8ErrorState=NOK;
	}

	return Local_u8ErrorState;
}
/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                            GPIO TOGGLE PIN VALUE
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @fn GPIO_u8TogglePinValue
 * @brief the function Toggle the GPIO pin value
 * @param[in] Port ,PinNum
 * @retval Local_u8ErrorState
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
uint8_t GPIO_u8TogglePinValue(Port_t	Port , Pin_t	PinNum )
{
	uint8_t Local_u8ErrorState=OK;
	if((Port <= PORTH) && (PinNum <= PIN15))
	{
		(GPIOx[Port]->GPIO_ODR) ^=(1<<PinNum);
	}
	else
	{
		Local_u8ErrorState=NOK;
	}

	return Local_u8ErrorState;
}
/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                            GPIO READ PIN VALUE
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @fn GPIO_u8ReadPinValue
 * @brief the function Read the GPIO pin value
 * @param[in] Port ,PinNum
 * @param[out] PinVal
 * @retval Local_u8ErrorState
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
uint8_t GPIO_u8ReadPinValue(Port_t	Port , Pin_t	PinNum , PinVal_t*	PinVal)
{
	uint8_t Local_u8ErrorState=OK;
	if((Port <= PORTH) && (PinNum <= PIN15))
	{
		*PinVal = ((GPIOx[Port]->GPIO_IDR)>>PinNum&0x01);
	}
	else
	{
		Local_u8ErrorState=NOK;
	}

	return Local_u8ErrorState;
}
