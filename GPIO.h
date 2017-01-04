#pragma once
#include "GPIO_LPC43xx.h"

class GPIO{
	uint8_t  index;
	uint32_t port, pin, direction, value;
	public:
		GPIO(const unsigned char index, uint32_t port, uint32_t pin, uint32_t direction);
		void Set(uint32_t value);
		uint32_t Get(void);	
};
