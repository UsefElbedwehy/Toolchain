#ifndef GPIO_PRV_H_
#define GPIO_PRV_H_


#define GPIO_PERIPHERAL_NUM 8U
/* * * MODER * * */
#define MODER_MASK           0b11
#define MODER_PIN_ACCESS     2U
/* * * PUPDR * * */
#define PUPDR_MASK           0b11
#define PUPDR_PIN_ACCESS     2U
/* * * PUPDR * * */
#define OTYPER_MASK          0b1
/* * * PUPDR * * */
#define OSPEEDR_MASK         0b11
#define OSPEEDR_PIN_ACCESS   2U
/* * * ALTERNATE FUNCTION * * */
#define AFR_MASK         	0b1111
#define AFR_PIN_ACCESS   	4U
#define AFR_PIN_SHIFTING 	8U

#endif
