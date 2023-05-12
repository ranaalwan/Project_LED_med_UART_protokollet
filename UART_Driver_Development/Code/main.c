#include "uart.h" //Fetch and include our header files, with functions and library.
#include "led.h" 

Led_Type led1;
Led_Type led2;

int main(void){ //Create main function, constructs and manages the LED-lights.
  
	USART2_Init(); //Init function
	Led_ctor(&led1,RED,OFF);
  	Led_ctor(&led2,BLUE,ON);
  
 	Led_getState(&led1);
  	Led_setState(&led2,OFF);

	while(1){}//While-function

}