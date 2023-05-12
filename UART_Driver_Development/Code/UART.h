//This file combines UART.c and Main.c

#ifndef  __UART_H //Checks if whether a macro is not defined
#define  __UART_H //Init the start of our header file 


#include "stm32f4xx.h" //Fetch and include library "stm32f4xx.h"                
#include <stdio.h> // Includes Standard I/O for C

void USART2_Init(void); //Calls and references to the declaration from our UART-function
void test_setup(void); //Calls and references to our test function from UART.c


#endif // Ends our header file