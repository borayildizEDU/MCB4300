#include "GPIO.h"

GPIO::GPIO(const unsigned char index, uint32_t port, uint32_t pin, uint32_t direction){
	this->index = index;
	this->port = port;
	this->pin = pin;
	this->direction = direction;
	
	GPIO_PortClock(1);
	GPIO_SetDir (port, pin, direction);
}

void GPIO::Set(uint32_t value){
	this->value = value;
	GPIO_PinWrite(port, pin, value);
}

uint32_t GPIO::Get(void){
	value = GPIO_PinRead (port, pin);
	return value;
}