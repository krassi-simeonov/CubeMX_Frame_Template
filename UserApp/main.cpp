/*Main Include*/
#include "user_config.h"
/*Drivers*/
#include "main.h"
#include "usart.h"
#include "tim.h"
#include "cmsis_os.h" /*for FreeRTOS*/

/*Library*/
#include "libs/support/uart/serial_cpp.h"

/*App*/
#include "app/include/button.h"
#include "app/include/lv_app.h"
/*-------NOTE-------s

1.FreeRTOS Task configuration
osThreadId_t taskDefaultHandle;
const osThreadAttr_t taskDefault_attributes = {
	.name = "TaskDefault",
	.stack_size = 128 * 4,
	.priority = (osPriority_t) osPriorityNormal,
};
2.FreeRTOS load Task
taskDefaultHandle = osThreadNew(StartDefaultTask, NULL, &taskDefault_attributes);
3.FreeRTOS Task implement
void StartDefaultTask(void *argument) {
  for(;;) {
    osDelay(1);
  }
}
  -------END--------*/
/*FreeRTOS task function*/
void StartScreenUpdateTask(void *argument);

void Main(){
	
//	osThreadId_t taskDefaultHandle;
//	const osThreadAttr_t taskDefault_attributes = {
//		.name = "TaskDefault",
//		.stack_size = 128,
//		.priority = (osPriority_t) osPriorityNormal,
//	};
//	taskDefaultHandle = osThreadNew(StartScreenUpdateTask, NULL, &taskDefault_attributes);


	// HAL_TIM_Base_Start_IT(&htim7);
	
	/*If FreeRTOS is used, the code block below should be removed*/
	for(;;){
		/* do something ... */
	}
}


/* stm32XXxx_it.c		extern void TimxCallback1kHz(); 	*/
/* TIMx_IRQHandler()	TimxCallback1kHz();return;			*/
/* main.cpp				HAL_TIM_Base_Start_IT(&htimx);		*/
extern "C" void Tim7Callback1kHz(){

	static unsigned int freq_1Hz = 0;
	
	__HAL_TIM_CLEAR_IT(&htim7, TIM_IT_UPDATE);

	if(freq_1Hz++ >= 1000){
		freq_1Hz = 0;
		// do something ...
	}

}

void StartScreenUpdateTask(void *argument){
	for(;;){
		osDelay(1000);
		HAL_GPIO_TogglePin(LCD_BL_GPIO_Port,LCD_BL_Pin);
	}
}











