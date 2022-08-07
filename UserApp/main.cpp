#include "include/user_include.h"




void Main(){
	
	// init
	
	for(;;){
		// loop
	}
}


// stm32XXxx_it.c	extern void TimxCallback1kHz();return;
// user_include.h	void TimxCallback1kHz();
// main.cpp			HAL_TIM_Base_Start_IT(&htim7);	
void TimxCallback1kHz(){
	
	__HAL_TIM_CLEAR_IT(&htim7, TIM_IT_UPDATE);
	
	// do something ...
}












