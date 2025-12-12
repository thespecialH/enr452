//AMDG
#include "stm32f446re.h"
#include "cortex-m4.h"
#include "main.h"

#define DELAY 700000
//#define DEBOUNCE_LENGTH 100

uint32_t ONBOARD_LED_PIN = 5; //port a
uint32_t OFFBOARD_LED_PIN = 4; //port b
uint32_t BUTTON1_PIN = 7; //port c
uint32_t BUTTON2_PIN = 3; //port b
uint32_t BUTTON0_PIN = 13; //port c



int button = 0;

int main(void) {

	
	//enable the ports
	RCC->AHB1ENR.bit0 = 1;
	RCC->AHB1ENR.bit1 = 1;
	RCC->AHB1ENR.bit2 = 1;

	//enable SYSCFG
	RCC->APB2ENR.bit14 = 1;

	
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

	//port c pin 7 input
	GPIOC->MODER.pin7 = 0;
	GPIOC->OTYPER.bit7 = 0;
	GPIOC->OSPEEDR.pin7 = 0;
	GPIOC->PUPDR.pin7 = 2;


	//button 2 port b pin 3
	GPIOB->MODER.pin3 = 0;
	GPIOB->OTYPER.bit3 = 0;
	GPIOB->OSPEEDR.pin3 = 0;
	GPIOB->PUPDR.pin3 = 2;

	//button 0 port c pin 13
	GPIOC->MODER.pin13 = 0;
	GPIOC->OTYPER.bit13 = 0;
	GPIOC->OSPEEDR.pin13 = 0;
	GPIOC->PUPDR.pin13 = 2;

	//set up the interrupt
	//button 1
	SYSCFG->EXTICR2.group3 = 0x02;
	//button 2
	SYSCFG->EXTICR1.group3 = 0x01;
	//button 0
	SYSCFG->EXTICR4.group1 = 0x02;
	
	//interrupt registers - button 1
	EXTI->IMR.bit7 = 1;
	EXTI->RTSR.bit7 = 1;
	NVIC->ISER0.bit23 = 1;

	//button 2
	EXTI->IMR.bit3 = 1;
	EXTI->RTSR.bit3 = 1;
	NVIC->ISER0.bit9 = 1;

	//button 0
	EXTI->IMR.bit13 = 1;
	EXTI->RTSR.bit13 = 1;
	NVIC->ISER1.bit8 = 1;


	//the infinite loop of the program
	while (1) {

		
		int delay = DELAY;

		while(delay--){

			if (button == 2 && delay == DELAY/2)
			{
				ledBlink(GPIOB, OFFBOARD_LED_PIN);
			}

		}

		if (button == 1 || button == 2)
		{
			ledBlink(GPIOB, OFFBOARD_LED_PIN);
		}
		if (button == 0)
		{
			pinClear(GPIOB, OFFBOARD_LED_PIN);
		}

		ledBlink(GPIOA, ONBOARD_LED_PIN);

	}
}

void button0_handler(void) {
	button = 0;
	EXTI->PR.bit13 = 1;
}

void button1_handler(void) {
	button = 1;
	EXTI->PR.bit7 = 1;
}

void button2_handler(void) {
	button = 2;
	EXTI->PR.bit3 = 1;
}
