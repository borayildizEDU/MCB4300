#pragma once
#include "Board_GLCD.h"
#include "GLCD_Config.h"

extern GLCD_FONT GLCD_Font_6x8;
extern GLCD_FONT GLCD_Font_16x24;

class LCD{
	uint8_t  index;
		
	public:
		LCD(const unsigned char index);
		void Show_Page_Main(void);
		
		static void Initialize();
	

};
