#include "LCD.h"

LCD::LCD(const unsigned char index){
	this->index = index;
}

void LCD::Initialize(void){
	GLCD_Initialize();
}

void LCD::Show_Page_Main(void){
  GLCD_SetBackgroundColor (GLCD_COLOR_WHITE);
  GLCD_ClearScreen        ();
  GLCD_SetBackgroundColor (GLCD_COLOR_BLUE);
  GLCD_SetForegroundColor (GLCD_COLOR_WHITE);
  GLCD_SetFont            (&GLCD_Font_16x24);
  GLCD_DrawString         (0, 0*24, "       MCB4300      ");
  GLCD_DrawString         (0, 1*24, "    Demo Example    ");
  GLCD_SetBackgroundColor (GLCD_COLOR_WHITE);
  GLCD_SetForegroundColor (GLCD_COLOR_BLUE);
  GLCD_DrawString         (0, 2*24, "                    ");
  GLCD_DrawString         (0, 3*24, " Use WAKEUP btn to  ");
  GLCD_DrawString         (0, 4*24, "   switch example   ");
  GLCD_DrawString         (0, 5*24, "        mode        ");
  GLCD_DrawString         (0, 6*24, "                    ");
  GLCD_DrawString         (0, 7*24, "                    ");
  GLCD_DrawString         (0, 8*24, "  Press any key to  ");
  GLCD_DrawString         (0, 9*24, "      continue      ");		
}
