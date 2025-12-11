#include<stdint.h>

#define FLASH_BASE		((uint32_t)0x08000000U)
#define SRAM_BASE		((uint32_t)0x20000000U)
#define GPIOA_REGISTERS ((uint32_t)0x40020000U)
#define GPIOB_REGISTERS ((uint32_t)0x40020400U)
#define GPIOC_REGISTERS ((uint32_t)0x40020800U)
#define RCC_REGISTERS	((uint32_t)0x40023800U)

typedef union
{
	volatile uint32_t data;
	struct
	{
		volatile uint32_t bit0: 1;
		volatile uint32_t bit1: 1;
		volatile uint32_t bit2: 1;
		volatile uint32_t bit3: 1;
		volatile uint32_t bit4: 1;
		volatile uint32_t bit5: 1;
		volatile uint32_t bit6: 1;
		volatile uint32_t bit7: 1;
		volatile uint32_t bit8: 1;
		volatile uint32_t bit9: 1;
		volatile uint32_t bit10: 1;
		volatile uint32_t bit11: 1;
		volatile uint32_t bit12: 1;
		volatile uint32_t bit13: 1;
		volatile uint32_t bit14: 1;
		volatile uint32_t bit15: 1;
		volatile uint32_t bit16: 1;
		volatile uint32_t bit17: 1;
		volatile uint32_t bit18: 1;
		volatile uint32_t bit19: 1;
		volatile uint32_t bit20: 1;
		volatile uint32_t bit21: 1;
		volatile uint32_t bit22: 1;
		volatile uint32_t bit23: 1;
		volatile uint32_t bit24: 1;
		volatile uint32_t bit25: 1;
		volatile uint32_t bit26: 1;
		volatile uint32_t bit27: 1;
		volatile uint32_t bit28: 1;
		volatile uint32_t bit29: 1;
		volatile uint32_t bit30: 1;
		volatile uint32_t bit31: 1;
	};
} reg32bit;

typedef union
{
	volatile uint32_t data;
	struct
	{
		volatile uint32_t bit0: 1;
		volatile uint32_t bit1: 1;
		volatile uint32_t bit2: 1;
		volatile uint32_t bit3: 1;
		volatile uint32_t bit4: 1;
		volatile uint32_t bit5: 1;
		volatile uint32_t bit6: 1;
		volatile uint32_t bit7: 1;
		volatile uint32_t bit8: 1;
		volatile uint32_t bit9: 1;
		volatile uint32_t bit10: 1;
		volatile uint32_t bit11: 1;
		volatile uint32_t bit12: 1;
		volatile uint32_t bit13: 1;
		volatile uint32_t bit14: 1;
		volatile uint32_t bit15: 1;
	};
} reg16bit;

typedef union
{
	volatile uint32_t data;
	struct
	{
		volatile uint32_t pin0: 2;
		volatile uint32_t pin1: 2;
		volatile uint32_t pin2: 2;
		volatile uint32_t pin3: 2;
		volatile uint32_t pin4: 2;
		volatile uint32_t pin5: 2;
		volatile uint32_t pin6: 2;
		volatile uint32_t pin7: 2;
		volatile uint32_t pin8: 2;
		volatile uint32_t pin9: 2;
		volatile uint32_t pin10: 2;
		volatile uint32_t pin11: 2;
		volatile uint32_t pin12: 2;
		volatile uint32_t pin13: 2;
		volatile uint32_t pin14: 2;
		volatile uint32_t pin15: 2;
	};
} reg32bit2;

typedef struct
{
	reg32bit CR;
	reg32bit PLLCFGR;
	reg32bit CFGR;
	reg32bit CIR;
	reg32bit AHB1RSTR;
	reg32bit AHB2RSTR;
	reg32bit AHB3RSTR;
	reg32bit RESERVED1;
	reg32bit APB1RSTR; //0x020
	reg32bit APB2RSTR; //0x024
	reg32bit RESERVED2;
	reg32bit RESERVED3;
	reg32bit AHB1ENR;
	reg32bit AHB2ENR;
	reg32bit AHB3ENR;

} RCC_TypeDef;

typedef struct
{
	reg32bit2 MODER; //Mode register 0x00
	reg16bit OTYPER; //output type registers 0x04
	reg32bit2 OSPEEDR; //output speed register 0x08
	reg32bit2 PUPDR; //port pull-up/-down register 0x0C
	reg32bit IDR; //port input data register 0x10
	reg32bit ODR; //port output data register
	reg32bit BSRR; //port bit set/reset register
	reg32bit LCKR; //port config lock register
	reg32bit AFRL; //alternate function register, low
	reg32bit AFRH; //alternate function register, high

} GPIO_TypeDef;



#define RCC	(( RCC_TypeDef * )RCC_REGISTERS )
#define GPIOA (( GPIO_TypeDef * )GPIOA_REGISTERS )
#define GPIOB (( GPIO_TypeDef *)GPIOB_REGISTERS )
#define GPIOC (( GPIO_TypeDef *)GPIOC_REGISTERS )

//GPIOB->AHB4ENR |= RCC_AHB4ENR_GPIOBEN; set the first bit to 1

//GPIOB->AHB4ENR &= ~RCC_AHB4ENR_GPIOBEN; set the first bit to 0
