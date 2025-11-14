#include<stdbool.h>

//FUNCTION TIME
//this function outputs status of specific pin on GPIOB
bool isPinSet(reg32bit *port, uint32_t pin) {
	uint32_t pin_value = 0x01 << pin;
	uint32_t pin_status = port->data & pin_value;

	if (pin_status == pin_value) {
		return true;
	}
	return false;
}

//this function sets pin to 1
void pinSet(reg32bit *port, uint32_t pin) {
	uint32_t pin_value = 0x01 << pin;
	port->data |= pin_value;
}

//this function sets pin to 0

void pinClear(reg32bit *port, uint32_t pin) {
	uint32_t pin_value = 0x01 << pin;
	port->data &= ~pin_value;
}


//this function blinks the led

void ledBlink(reg32bit *port, uint32_t pin) {
	if (isPinSet(port, pin)) {
		pinClear(port, pin);
	}
	else {
		pinSet(port, pin);
	}
}
