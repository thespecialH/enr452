//AMDG
#include "stm32f446re.h"
#include "cortex-m4.h"
#include "main.h"

//#define DELAY 700000
#define DELAY 70000
#define DEBOUNCE_LENGTH 100

uint32_t ONBOARD_LED_PIN = 5; //port a
uint32_t OFFBOARD_LED_PIN = 4; //port b
uint32_t BUTTON_PIN = 7; //port c

int debounce_delay = 0;

int main(void) {

	
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

	//port c pin 13 input
	GPIOC->MODER.pin7 = 0;
	GPIOC->OTYPER.bit7 = 0;
	GPIOC->OSPEEDR.pin7 = 0;
	GPIOC->PUPDR.pin7 = 2;

	//set up the interrupt
	SYSCFG->EXTICR2.group3 = 0x02;
	
	//interrupt registers
	EXTI->IMR.bit7 = 1;

	EXTI->RTSR.bit7 = 1;

	NVIC->ISER0.bit23 = 1;



	bool read_reset = true;

	//the infinite loop of the program
	while (1) {

		/*
		int delay = DELAY;

		while(delay--){

			if (read_reset == false)
			{
				if (!readPin(GPIOC, BUTTON_PIN) )
					read_reset = true;
			}

			else if (read_reset == true)
			{

				if (debounce_delay == 0)
				{
					if (readPin(GPIOC, BUTTON_PIN) )
					{
						debounce_delay++;
					}
					else
					{
						debounce_delay = 0;
					}
				}
				else if (debounce_delay > 0 && debounce_delay < DEBOUNCE_LENGTH)
				{
					debounce_delay++;
				}
				else
				{
					if (readPin(GPIOC, BUTTON_PIN) )
					{
						ledBlink(GPIOB, OFFBOARD_LED_PIN);
						debounce_delay = 0;
						read_reset = false;
					}
					else
					{
						debounce_delay = 0;
					}
				}
			}
		}

		ledBlink(GPIOA, ONBOARD_LED_PIN);

		*/
	}
}

