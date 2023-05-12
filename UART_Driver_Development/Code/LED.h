#ifndef LED_H
#define LED_H //Defines that the header is denoted by LED.h and shall be included when called

#include <stdint.h> //Includes a standard library that will give us exact-width integer types regardless of underlying hardware(int8_t, uint8_t, int16_t..)
#include "UART.h" //Includes our UART.h Header
#include "stm32f4xx.h" //Device header for device-specific information about the hardware.

//Defines which GPIO shall be responsible for the LED function
#define	LED_PORT GPIOB

//Defines the clock signal for the port
#define	LED_PORT_CLOCK (1U<<1)

//Defines the different pins for the different LED colors
#define LED_RED_PIN (1U<<14)
#define LED_GREEN_PIN (1U<<12)
#define	LED_BLUE_PIN (1U<<15)
#define LED_YELLOW_PIN (1U<<13)

//Defines mode bits for each LED color
#define LED_RED_MODE_BIT  (1U<<28)
#define LED_GREEN_MODE_BIT (1U<<24)
#define LED_YELLOW_MODE_BIT (1U<<26)
#define LED_BLUE_MODE_BIT (1U<<30)

typedef enum { //Builds a function that enumerates the different colors that can be assumed by the LED
  RED = 0,
  GREEN,
  YELLOW,
  BLUE
}LedColor_Type;

typedef enum { //Builds a function that enumerates the different states the LED can be in
  OFF = 0,
  ON = 1,
}LedState_Type;

//Defines the attributes that the LED consists of
typedef struct{
  LedColor_Type color;
  LedState_Type state;
}Led_Type;

//Declares the functions for the LED construction and the status check
void Led_ctor(Led_Type * const me, LedColor_Type _color, LedState_Type _state);
void Led_setState(Led_Type * const me, LedState_Type _state);
LedState_Type Led_getState(Led_Type * const me);

#endif //Clarifies the end of our header file