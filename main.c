/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "Stm32F446xx.h"
#include "ErrType.h"

#include "RCC_Private.h"
#include "RCC_Interface.h"

#include "GPIO_prv.h"
#include "GPIO_interface.h"
 
int main(void)
{
	
	
	RCC_AHB1EnableClock(PORTA);
	PinConfig_t LedPin={
			.Port=PORTA,
			.PinNum=PIN5,
			.Mode= OUTPUT,
			.OutputType= PUSH_PULL,
			.Speed= LOW_SPEED,
			.PullType= NOPULL,
			.AltFunc= AF0
	};

	GPIO_u8PinInit(&LedPin);
	//__asm volatile("msr msp,r3");
	GPIO_u8SetPinValue(PORTA, PIN5, PIN_HIGH);


    /* Loop forever */
	for(;;);
}

