#include "UART.h" //Fetch and includes our header file.

//Defines function to initialize the USART protocol and it's constituents. This function is a driver.
void USART2_Init(void){ //Declare a function and init from uart.h

//Configure the system clock (RCC) for the microcontroller
//APB1ENR is a register within RCC, which is used for activating and deactivating the clock
 RCC->APB1ENR  |=  0x20000; //Enable the clock for USART2 by setting bit 17 of RCC->APB1ENR to 1.
 RCC->AHB1ENR   |=0x01; //Enable GPIO, set bit 0 in AHB1ENR to 1.
 
GPIOA->MODER &=~0x00F0; //Clears bits 4-7 to prepare pins PA2 and PA3
GPIOA->MODER |= 0x00A0; //Enables bites 5-7 to 1, to prepare and activate alternative function on pins PA2 and PA3.
GPIOA->AFR[0] &= ~0xFF00; // Clears bits 8-15 to prepare pins PA2 and PA3
GPIOA->AFR[0] |= 0x7700; //Choose type of alternative for pins. Sets bits 8-11 and 12-15 format 0111

//Configuaration of UART
USART2->BRR  =  0x0683; //We set the default baud rate using hexadecimal. 0x0683 (9600bps)
USART2->CR1  =  0x000C; //Put tx and rx to work in 8-bit data.(8-bit data, 1 stop bt, no parity.)
USART2->CR2  =  0x000; //Leave USART2->CR2 at its default value.
USART2->CR3  =  0x000; //Leave USART2->CR3 at its default value.
USART2->CR1  |=  0x2000; //Resets bit 13 (the UART-enable) to 1

}
//UART Read and Write rules
int USART2_write(int ch){ //Declare the write function(transfer of data to the terminal).
	
	//Loop, send byte by byte.
	while(!(USART2->SR & 0x0080)){} //Sets a requirement that checks the status of the transfer is empty and can receive the next character.(Byte)
	USART2->DR = (ch & 0xFF); //Sets the transfer of the byte to the data registers.
	
  return ch; //Return character that was written
}

int USART2_read(void){ //Create void with new variable (the reception of new information)Declares read function
  while(!(USART2->SR & 0x0020)){} //While-function with requirement that checks if there is more data to retrieve
	return USART2->DR; //Return UART2 to Data register. Sets the transfer of bytes to data registers
}
//Interface for standard I/O in C
//A redirect to output data in the terminal
struct __FILE { int handle; }; //Structuring our main transmission currents
FILE __stdin  = {0}; 
FILE __stdout = {1}; 
FILE __stderr = {2};


int fgetc(FILE *f) { //fget retrieves a byte from the standard stream and processes character returns
    int c; //Create variable

    c = USART2_read(); 

    if (c == '\r') {
        USART2_write(c);
        c = '\n'; 
    }

    USART2_write(c);     

    return c; //Return c
}

int fputc(int c, FILE *f) { //fput writes a byte to the standard stream
    return USART2_write(c); 
}


int n; //Declare variable, a byte for use in the test function.
char str[80]; //Declare char array and sets a limitation in the transfer of characters.
		
void test_setup(void){ //Init function from uart.h that will test our read- and write function.
	
	printf("please enter a number: "); //print function, ask user to enter a number.
	scanf("%d", &n); //Scan function and retrieve number.
	printf("the number entered is: %d\r\n", n); //Print function, show input from user(number)
	printf("please type a character string: "); //Print function, ask user for a string.
	gets(str); //Gets function(string)
	printf("the character string entered is: "); //Print function, shows input from user(string)
	puts(str); //Print the string from user.
	printf("\r\n"); //Prints new line
	
}