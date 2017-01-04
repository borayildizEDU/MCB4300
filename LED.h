#pragma once
#include "Board_LED.h"

class LED{
  uint8_t  index;
		
	public:
		LED(const unsigned char index);
		void On(void);
		void Off(void);
	
		static uint32_t Get_Count(void);
		static void Initialize(void);
		static void Uninitialize(void);		

};

