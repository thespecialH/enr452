//AMDG
#include "stm32h755.h"
#include "main.h"

#define DELAY 700000

uint32_t ONBOARD_LED1_PIN = 0; //port b
uint32_t ONBOARD_LED2_PIN = 1; //port e
uint32_t ONBOARD_LED3_PIN = 14;//port b
uint32_t OFFBOARD_LED_PIN = 11; //port d



int main(void) {

	RCC->AHB4ENR |= RCC_AHB4ENR_GPIOBEN;
	RCC->AHB4ENR |= RCC_AHB4ENR_GPIODEN;
	RCC->AHB4ENR |= RCC_AHB4ENR_GPIOEEN;
	

	//Set the proper values for PB0 and PB14
	GPIOB->MODER &= 0xCFFFFFFC; 
	GPIOB->MODER |= 0x10000001; 
	GPIOB->OTYPER &= 0xBFFFFFFE; 
	GPIOB->OSPEEDR &= 0xCFFFFFFC; 
	GPIOB->OSPEEDR |= 0x20000002; 
	GPIOB->PUPDR &= 0xCFFFFFFC; 
	GPIOB->PUPDR |= 0x20000002;


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


	//the infinite loop of the program
	while (1) {

		int delay = DELAY;

		while(delay--) {

			if (delay % (DELAY/3) == 0) {
				ledBlink(GPIOD, OFFBOARD_LED_PIN);
			}
		}

		ledBlink(GPIOB, ONBOARD_LED1_PIN);
		ledBlink(GPIOE, ONBOARD_LED2_PIN);
		ledBlink(GPIOB, ONBOARD_LED3_PIN);


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
