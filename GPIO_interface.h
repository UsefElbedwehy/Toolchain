#ifndef  GPIO_INTERFACE_H_
#define  GPIO_INTERFACE_H_

/* 
 * * * * * * * * * * * * * * * * *
			PORT NUMBERS 
 * * * * * * * * * * * * * * * * *
*/
typedef enum{
	PORTA=0,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF,
	PORTG,
	PORTH
}Port_t;
/* 
 * * * * * * * * * * * * * * * * *
			PIN NUMBERS 
 * * * * * * * * * * * * * * * * *
*/
typedef enum{
	PIN0=0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
}Pin_t;
/*
 * * * * * * * * * * * * * * * * *
		  MODE OPTIONS
 * * * * * * * * * * * * * * * * *
*/
typedef enum{
	INPUT=0,
	OUTPUT,
	ALTERNATIVE_FUNCTION,
	ANALOG
}Mode_t;
/*
 * * * * * * * * * * * * * * * * *
			SPEED TYPES
 * * * * * * * * * * * * * * * * *
*/
typedef enum{
	LOW_SPEED=0,
	MEDIUM_SPEED,
	FAST_SPEED,
	HIGH_SPEED
}OutputSpeed_t;
/*
 * * * * * * * * * * * * * * * * *
           OUTPUT TYPES
 * * * * * * * * * * * * * * * * *
*/
typedef enum{
	PUSH_PULL=0,
	OPEN_DRAIN
}OutputType_t;
/*
 * * * * * * * * * * * * * * * * *
           PUPD OPTIONS
 * * * * * * * * * * * * * * * * *
*/
typedef enum{
	NOPULL=0,
	PULLUP,
	PULLDOWN
}PullUpDown_t;
/* 
 * * * * * * * * * * * * * * * * *
	  ALTERNATE FUNCTION 
 * * * * * * * * * * * * * * * * *
*/
typedef enum{
	AF0=0,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15
}AltFunc_t;
/*
 * * * * * * * * * * * * * * * * *
          PIN VALUE OPTIONS
 * * * * * * * * * * * * * * * * *
*/
typedef enum{
	PIN_LOW=0,
	PIN_HIGH
}PinVal_t;
/*
 * * * * * * * * * * * * * * * * *
 * * * PIN CONFIGURATIONS * * 
 * * * * * * * * * * * * * * * * *
   TO PASS IT TO THE FUNCTION 
         AS AN ARGUMENT
* * * * * * * * * * * * * * * * *
*/
typedef struct{
	Port_t 		    Port;
	Pin_t			PinNum;
	Mode_t			Mode;
	OutputSpeed_t	Speed;
	OutputType_t	OutputType;
	PullUpDown_t	PullType;
	AltFunc_t 		AltFunc;
	
}PinConfig_t;
/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
							GPIO INITIALIZATION
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
uint8_t GPIO_u8PinInit(const PinConfig_t* PinConfig);
/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                            GPIO SET PIN VALUE
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
uint8_t GPIO_u8SetPinValue(Port_t  Port , Pin_t  PinNum , PinVal_t PinVal);
/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                            GPIO TOGGLE PIN VALUE
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
uint8_t GPIO_u8TogglePinValue(Port_t	Port , Pin_t	PinNum );
/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                            GPIO READ PIN VALUE
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
uint8_t GPIO_u8ReadPinValue(Port_t	Port , Pin_t	PinNum , PinVal_t*	PinVal);

#endif
