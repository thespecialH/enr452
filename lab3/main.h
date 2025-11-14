#include<stdbool.h>

//FUNCTION TIME
//this function outputs status of specific pin on GPIOB
bool isPinSet(GPIO_TypeDef *port, uint32_t pin) {
	uint32_t pin_value = 0x01 << pin;
	uint32_t pin_status = port->IDR & pin_value;

	if (pin_status == pin_value) {
		return true;
	}
	return false;
}

//this function sets pin to 1 on GPIOB
void pinSet(GPIO_TypeDef *port, uint32_t pin) {
	uint32_t pin_value = 0x01 << pin;
	port->ODR |= pin_value;
}

//this function sets pin to 0 on GPIOB

void pinClear(GPIO_TypeDef *port, uint32_t pin) {
	uint32_t pin_value = 0x01 << pin;
	port->ODR &= ~pin_value;
}

//this function blinks the led

void ledBlink(GPIO_TypeDef *port, uint32_t pin) {
	if (isPinSet(port, pin)) {
		pinClear(port, pin);
	}
	else {
		pinSet(port, pin);
	}
}

