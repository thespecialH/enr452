#include "stm32f446re.h"

void pinSet(GPIO_TypeDef *port, uint32_t pin);

void test_handler(void) {
	for (int i = 0; i < 120000; i++)
	{
		pinSet(GPIOA, 5);
	}
	EXTI->PR.bit7 = 1;
}
