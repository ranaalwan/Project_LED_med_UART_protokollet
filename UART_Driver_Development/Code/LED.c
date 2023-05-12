#include "LED.h" //Includes the LED.h header file, which includes the different LED terms and functions.

//Constructor: A function that establishes parameters for LED application
void Led_ctor(Led_Type * const me, LedColor_Type _color, LedState_Type _state){
  
	me->color  = _color;
	me->state  = _state; 
	 	
	 /*Hardware Init*///Enable the clock for LED port(GPIOB)
	RCC->AHB1ENR |= LED_PORT_CLOCK;  
	
	//Configure the LED pins based on their color and status
	switch(_color){
		 
		case RED: //Set the port mode of the LED configuration to output
			LED_PORT->MODER |=LED_RED_MODE_BIT;
		  if(me->state  == ON){ //Turn ON the LED
			   LED_PORT->ODR |= LED_RED_PIN;
			  printf("The RED Led is set ON \n\r");
			}
			else{ //Turn the led OFF
			  LED_PORT->ODR &= ~LED_RED_PIN;
				printf("The RED Led is set OFF \n\r");
			}
		break;
		
		case YELLOW: //Set the port mode of the LED configuration to output
			LED_PORT->MODER |=LED_YELLOW_MODE_BIT;
		  if(me->state  == ON){ //Turn ON the LED
			   LED_PORT->ODR |= LED_YELLOW_PIN;
			  printf("The YELLOW Led is set ON \n\r");
			}
			else{ //Turn the led OFF
			  LED_PORT->ODR &= ~LED_YELLOW_PIN;
				printf("The YELLOW Led is set OFF \n\r");

			}
		break;
		
		case BLUE: //Set the port mode of the LED configuration to output
			LED_PORT->MODER |=LED_BLUE_MODE_BIT;
		  if(me->state  == ON){ //Turn ON the LED
			   LED_PORT->ODR |= LED_BLUE_PIN;
			  printf("The BLUE Led is set ON \n\r");
			}
			else{ //Turn the led OFF
			  LED_PORT->ODR &= ~LED_BLUE_PIN;
				printf("The BLUE Led is set OFF \n\r");

			}
		break;
		
		case GREEN: //Set the port mode of the LED configuration to output
			LED_PORT->MODER |=LED_GREEN_MODE_BIT;
		  if(me->state  == ON){ //Turn ON the LED
			   LED_PORT->ODR |= LED_GREEN_PIN;
			  printf("The GREEN Led is set ON \n\r");
			}
			else{ //Turn the led OFF
			  LED_PORT->ODR &= ~LED_GREEN_PIN;
				printf("The GREEN Led is set OFF \n\r");

			}
		break;
	
	}
}


void Led_setState(Led_Type * const me,LedState_Type _state){
//Set the status of the LED
	 me->state =  _state;

	 
	//Check the color of the LED to know that the correct LED is being manipulated
	switch(me->color){
		 //If Led is RED
		case RED:
			//Set pin to output mode
			LED_PORT->MODER |=LED_RED_MODE_BIT;
			//If the desired status is ON
		  if(me->state  == ON){
			  //Defines pin output to Active
			   LED_PORT->ODR |= LED_RED_PIN;
			  printf("The RED Led is set ON \n\r");
			}
			else{
			//Defines pin output to inactive
			  LED_PORT->ODR &= ~LED_RED_PIN;
				printf("The RED Led is set OFF \n\r");

			}
		break;
		//If Led is YELLOW
		case YELLOW:
			//Set pin to output mode
			LED_PORT->MODER |=LED_YELLOW_MODE_BIT;
		  //If the desired status is ON
		  if(me->state  == ON){
			  //Defines pin output to Active
			   LED_PORT->ODR |= LED_YELLOW_PIN;
			  printf("The YELLOW Led is set ON \n\r");
			}
			else{
			//Defines pin output to inactive
			  LED_PORT->ODR &= ~LED_YELLOW_PIN;
			printf("The YELLOW Led is set OFF \n\r");

			}
		break;
		//If Led is BLUE
		case BLUE:
			//Set pin to output mode
			LED_PORT->MODER |=LED_BLUE_MODE_BIT;
		  if(me->state  == ON){
			  //Defines pin output to Active
			   LED_PORT->ODR |= LED_BLUE_PIN;
				printf("The BLUE Led is set ON \n\r");
			}
			else{
			//Defines pin output to inactive
			  LED_PORT->ODR &= ~LED_BLUE_PIN;
        printf("The BLUE Led is set OFF \n\r");

			}
		break;
		//If Led is GREEN
		case GREEN:
			//Set pin to output mode
			LED_PORT->MODER |=LED_GREEN_MODE_BIT;
		  if(me->state  == ON){
			  //Defines pin output to Active
			   LED_PORT->ODR |= LED_GREEN_PIN;
				printf("The GREEN Led is set ON \n\r");
			}
			else{
			//Defines pin output to inactive
			  LED_PORT->ODR &= ~LED_GREEN_PIN;
        printf("The GREEN Led is set OFF \n\r");

			}
		break;
	
	}
}

//Check the color of the requested LED, then print the status.
LedState_Type Led_getState(Led_Type * const me){

	switch(me->color){
		
		case RED:
			   printf("The RED Led is cureently %d \n\r",me->state);
				 break;
		
	  case GREEN:
			   printf("The GREEN Led is cureently %d \n\r",me->state);
				 break;
		case BLUE:
			   printf("The BLUE Led is cureently %d\n\r",me->state);
				 break;
		case YELLOW:
			   printf("The YELLOW Led is cureently  %d \n\r",me->state);
				 break;
		
		
	 }
  
	return me->state; //Returns the LED status of the selected color
}