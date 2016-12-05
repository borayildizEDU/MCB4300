#include "LED.h"


LED::LED(const unsigned char index){
	this->index = index;
}

void LED::On(void){
	LED_On(this->index);
}

void LED::Off(void){
	LED_Off(this->index);	
}

uint32_t LED::Get_Count(void){
	return LED_GetCount();
}

void LED::Initialize(void){
	LED_Initialize();
}

void LED::Uninitialize(void){
	LED_Uninitialize();
}
