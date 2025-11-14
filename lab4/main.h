#include<stdbool.h>

//FUNCTION TIME
//this function outputs status of specific pin

bool isPinSet(GPIO_TypeDef *port, uint32_t pin) {
	uint32_t pin_status;

	switch (pin) {
		case 0:
			pin_status = port->ODR.bit0;
			break;
		case 1:
			pin_status = port->ODR.bit1;
			break;
		case 2:
			pin_status = port->ODR.bit2;
			break;
		case 3:
			pin_status = port->ODR.bit3;
			break;
		case 4:
			pin_status = port->ODR.bit4;
			break;
		case 5:
			pin_status = port->ODR.bit5;
			break;
		case 6:
			pin_status = port->ODR.bit6;
			break;
		case 7:
			pin_status = port->ODR.bit7;
			break;
		case 8:
			pin_status = port->ODR.bit8;
			break;
		case 9:
			pin_status = port->ODR.bit9;
			break;
		case 10:
			pin_status = port->ODR.bit10;
			break;
		case 11:
			pin_status = port->ODR.bit11;
			break;
		case 12:
			pin_status = port->ODR.bit12;
			break;
		case 13:
			pin_status = port->ODR.bit13;
			break;
		case 14:
			pin_status = port->ODR.bit14;
			break;
		case 15:
			pin_status = port->ODR.bit15;
			break;
	}

	if (pin_status == 1) {
		return true;
	}
	return false;
}

//this function sets pin to 1
void pinSet(GPIO_TypeDef *port, uint32_t pin) {

	switch (pin) {
		case 0:
			port->ODR.bit0 = 1;
			break;
		case 1:
			port->ODR.bit1 = 1;
			break;
		case 2:
			port->ODR.bit2 = 1;
			break;
		case 3:
			port->ODR.bit3 = 1;
			break;
		case 4:
			port->ODR.bit4 = 1;
			break;
		case 5:
			port->ODR.bit5 = 1;
			break;
		case 6:
			port->ODR.bit6 = 1;
			break;
		case 7:
			port->ODR.bit7 = 1;
			break;
		case 8:
			port->ODR.bit8 = 1;
			break;
		case 9:
			port->ODR.bit9 = 1;
			break;
		case 10:
			port->ODR.bit10 = 1;
			break;
		case 11:
			port->ODR.bit11 = 1;
			break;
		case 12:
			port->ODR.bit12 = 1;
			break;
		case 13:
			port->ODR.bit13 = 1;
			break;
		case 14:
			port->ODR.bit14 = 1;
			break;
		case 15:
			port->ODR.bit15 = 1;
			break;
	}
	
}

//this function resets pin to 0
void pinClear(GPIO_TypeDef *port, uint32_t pin) {

	switch (pin) {
		case 0:
			port->ODR.bit0 = 0;
			break;
		case 1:
			port->ODR.bit1 = 0;
			break;
		case 2:
			port->ODR.bit2 = 0;
			break;
		case 3:
			port->ODR.bit3 = 0;
			break;
		case 4:
			port->ODR.bit4 = 0;
			break;
		case 5:
			port->ODR.bit5 = 0;
			break;
		case 6:
			port->ODR.bit6 = 0;
			break;
		case 7:
			port->ODR.bit7 = 0;
			break;
		case 8:
			port->ODR.bit8 = 0;
			break;
		case 9:
			port->ODR.bit9 = 0;
			break;
		case 10:
			port->ODR.bit10 = 0;
			break;
		case 11:
			port->ODR.bit11 = 0;
			break;
		case 12:
			port->ODR.bit12 = 0;
			break;
		case 13:
			port->ODR.bit13 = 0;
			break;
		case 14:
			port->ODR.bit14 = 0;
			break;
		case 15:
			port->ODR.bit15 = 0;
			break;
	}
	
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
