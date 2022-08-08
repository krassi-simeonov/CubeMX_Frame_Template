#include "user_include.h"
#include "button.h"


/*-------*NOTE*-------*/
//  若使用FreeRTOS,将Main();放在/*USER CODE BEGIN 2*/区域并将无限循环删之
//osThreadId_t TaskHandleScreenUpdate;
//void ThreadScreenUpdate(void* argument){
//    UNUSED(argument);
//    for(;;){
//        lv_task_handler();
//    }
//}

void Main(){
	
	// init

	//    const osThreadAttr_t ThreadAttrScreenUpdate = {
	//            .name = "TaskScreenUpdate",
	//            .stack_size = 500,
	//            .priority = (osPriority_t) osPriorityNormal
	//    };
	//    TaskHandleScreenUpdate = osThreadNew(ThreadScreenUpdate, nullptr,&ThreadAttrScreenUpdate);


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












