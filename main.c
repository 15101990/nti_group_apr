/*
 * GccApplication1.c
 *
 * Created: 03/04/2022 10:07:52 ص
 * Author : dell
 */ 
#include "BIT_MATH.h"
#include "REG.h"
#include "STD.h"

#include "DC_MOTOR.h"
#include "WDT.h"
#include "SERVO.h"
#include "UART.h"
#include "SPI.h"
#include "AT24C16A.h"
void EXT_INT_EXC(void);
void TIMER_0_EXC(void);

#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
	_delay_ms(1000);
	H_LcdInit();
	H_LedInit(B_LED);
	H_Eeprom16kInit();
	u8 counter = H_Eeprom16kRead(1,20);
	while(1)
	{
		H_Eeprom16kWrite(1,20,counter);
		H_LcdWriteNumber(counter);
		counter++;
		_delay_ms(500);
		H_LcdClear();
	}
}



void EXT_INT_EXC(void)
{
	H_LedOn(R_LED);
}
void TIMER_0_EXC(void)
{
	H_LedTog(R_LED);
}