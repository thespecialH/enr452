#include<stdint.h>

#define FLASH_BASE		((uint32_t)0x08000000U)
#define SRAM_BASE		((uint32_t)0x30000000U)
#define GPIOB_REGISTERS	((uint32_t)0x58020400U)
#define GPIOD_REGISTERS ((uint32_t)0x58020C00U)
#define GPIOE_REGISTERS ((uint32_t)0x58021000U)
#define RCC_REGISTERS	((uint32_t)0x58024400U)

typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t HSICFGR;
	volatile uint32_t CRRCR;
	volatile uint32_t CSICFGR;
	volatile uint32_t CFGR;
	volatile uint32_t RESERVED1;
	volatile uint32_t D1CFGR;
	volatile uint32_t D2CFGR;
	volatile uint32_t D3CFGR; //0x020

	volatile uint32_t RESERVED_ARRAY1[47]; //0x024 to 0x0DC

	volatile uint32_t AHB4ENR; //0x0E0

	volatile uint32_t RESERVED_ARRAY2[23];

	volatile uint32_t C1_AHB4ENR; //0x140

	volatile uint32_t RESERVED_ARRAY3[23];

	volatile uint32_t C2_AHB4ENR; //0x1A0

	//more needed here?


} RCC_TypeDef;

typedef struct
{
	volatile uint32_t MODER; //Mode register 0x00
	volatile uint32_t OTYPER; //output type registers 0x04
	volatile uint32_t OSPEEDR; //output speed register 0x08
	volatile uint32_t PUPDR; //port pull-up/-down register 0x0C
	volatile uint32_t IDR; //port input data register 0x10
	volatile uint32_t ODR; //port output data register
	volatile uint32_t BSRR; //port bit set/reset register
	volatile uint32_t LCKR; //port config lock register
	volatile uint32_t AFRL; //alternate function register, low
	volatile uint32_t AFRH; //alternate function register, high

} GPIO_TypeDef;



#define RCC	(( RCC_TypeDef * )RCC_REGISTERS )
#define GPIOB (( GPIO_TypeDef * )GPIOB_REGISTERS )
#define GPIOD (( GPIO_TypeDef * )GPIOD_REGISTERS )
#define GPIOE (( GPIO_TypeDef * )GPIOE_REGISTERS )

#define RCC_AHB4ENR_GPIOBEN		0x00000002	//GPIO B is Bit 1 of the AHB4ENR Register
#define RCC_AHB4ENR_GPIODEN		0x00000008	//GPIO D is Bit 3 of the AHB4ENR Register
#define RCC_AHB4ENR_GPIOEEN		0x00000010	//GPIO E is Bit 4 of the AHB4ENR Register
	
//GPIOB->AHB4ENR |= RCC_AHB4ENR_GPIOBEN; set the first bit to 1

//GPIOB->AHB4ENR &= ~RCC_AHB4ENR_GPIOBEN; set the first bit to 0
