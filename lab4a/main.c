//AMDG
#include "stm32f446re.h"
#include "main.h"

#define DELAY 700000


uint32_t ONBOARD_LED_PIN = 5; //port a
uint32_t OFFBOARD_LED_PIN = 5; //port b



int main(void) {

	
	RCC->AHB1ENR.bit0 = 1;
	RCC->AHB1ENR.bit1 = 1;

	
	//Set the proper values for PB0 and PB14
	/*GPIOA->MODER &= 0xCFFFFFFC; 
	GPIOA->MODER |= 0x10000001; 
	GPIOA->OTYPER &= 0xBFFFFFFE; 
	GPIOA->OSPEEDR &= 0xCFFFFFFC; 
	GPIOA->OSPEEDR |= 0x20000002; 
	GPIOA->PUPDR &= 0xCFFFFFFC; 
	GPIOA->PUPDR |= 0x20000002;*/


	/*
	//Set the proper values for PE1
	GPIOD->MODER &= 0xFF3FFFFF;
	GPIOD->MODER |= 0x00400000;
	GPIOD->OTYPER &= 0xFFFFF7FF;
	GPIOD->OSPEEDR &= 0xFF3FFFFF;
	GPIOD->OSPEEDR |= 0x00800000;
	GPIOD->PUPDR &= 0xFF3FFFFF;
	GPIOD->PUPDR |= 0x00800000;


	//Set the proper values for PD11 (the external LED is connected here)
	GPIOE->MODER &= 0xFFFFFFF3;
	GPIOE->MODER |= 0x00000004;
	GPIOE->OTYPER &= 0xFFFFFFFD;
	GPIOE->OSPEEDR &= 0xFFFFFFF3;
	GPIOE->OSPEEDR |= 0x00000008;
	GPIOE->PUPDR &= 0xFFFFFFF3;
	GPIOE->PUPDR |= 0x00000008;
	*/

	//port a
	GPIOA->MODER.bit11 = 0;
	GPIOA->MODER.bit10 = 1;

	GPIOA->OTYPER.bit5 = 0;

	GPIOA->OSPEEDR.bit11 = 0;
	GPIOA->OSPEEDR.bit10 = 0;

	GPIOA->PUPDR.bit11 = 0;
	GPIOA->PUPDR.bit10 = 0;

	//port b
	GPIOB->MODER.bit11 = 0;
	GPIOB->MODER.bit10 = 1;

	GPIOB->OTYPER.bit5 = 0;

	GPIOB->OSPEEDR.bit11 = 0;
	GPIOB->OSPEEDR.bit10 = 0;

	GPIOB->PUPDR.bit11 = 0;
	GPIOB->PUPDR.bit10 = 0;

	reg32bit *porta;
	reg32bit *portb;


	//the infinite loop of the program
	while (1) {

		int delay = DELAY;

		porta = &GPIOA->ODR;
		portb = &GPIOB->ODR;

		while(delay--){
			if (delay % (DELAY/3) == 0) {
				ledBlink(portb, OFFBOARD_LED_PIN);
			}
		}

		ledBlink(porta, ONBOARD_LED_PIN);

	}
}



/*check the bit from reading all bits

result = GPIOB->IDR;

if ((result & 0x00000001) == 0x00000001) {
	//LED is on
} else {
	//LED is off
}
*/
