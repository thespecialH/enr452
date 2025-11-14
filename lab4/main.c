//AMDG
#include "stm32f446re.h"
#include "main.h"

#define DELAY 700000


uint32_t ONBOARD_LED_PIN = 5; //port a
uint32_t OFFBOARD_LED_PIN = 4; //port b



int main(void) {

	
	RCC->AHB1ENR.bit0 = 1;
	RCC->AHB1ENR.bit1 = 1;

	
	//port a
	GPIOA->MODER.pin5 = 1;
	GPIOA->OTYPER.bit5 = 0;
	GPIOA->OSPEEDR.pin5 = 0;
	GPIOA->PUPDR.pin5 = 0;

	//port b
	GPIOB->MODER.pin4 = 1;
	GPIOB->OTYPER.bit4 = 0;
	GPIOB->OSPEEDR.pin4 = 0;
	GPIOB->PUPDR.pin4 = 0;


	//the infinite loop of the program
	while (1) {

		int delay = DELAY;

		while(delay--){
			if (delay % (DELAY/3) == 0) {
				ledBlink(GPIOB, OFFBOARD_LED_PIN);
			}
		}

		ledBlink(GPIOA, ONBOARD_LED_PIN);

	}
}
