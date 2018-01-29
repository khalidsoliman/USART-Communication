/*
 * UART.c
 *
 *  Created on: Jan 16, 2018
 *      Author: Khalid
 */

#include "UART.h"
#include <avr/io.h>
#include <util/delay.h>

#define set_bit(reg,pin) reg|=(1<<pin)
#define clear_bit(reg,pin) reg&=~(1<<pin)

void UART_Init(unsigned long BaudRate)
{
	// UBRR for BaudRate Register contains (UBRRH , UBRRL)
	unsigned int UBRR;
	// UBRR Equation operations in Normal Mode
	UBRR = ((F_CPU/(16*BaudRate)) - 1 );
	// UBRRH (must to be first)
	UBRRH = (unsigned char) (UBRR>>8);
	// UBRRL
	UBRRL = (unsigned char) UBRR;

	// Select UCSRC Register
	// Character Size
	UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);

	// Transmit & Receive Enable
	UCSRB=(1<<RXEN)|(1<<TXEN);
}

void UART_Send_Data(unsigned char Data)
{
	while(!(UCSRA)&(1<<UDRE)); // Check if the Register is Empty and ready to receive the data
	UDR=Data;
}
void UART_send_string( char *ptr)
 {
	int i=0;

		while(ptr[i] != '\0')
		 {
			UART_Send_Data(ptr[i]);
			i++;
		 }
		UART_Send_Data(ptr[i]);
 }


void UART_Flush( void )
{
	unsigned char dummy;
	while ( UCSRA & (1<<RXC) ) dummy = UDR;
}
unsigned char UART_Receive_Data()
{
	UART_Flush();
	while((UCSRA&(1<<RXC))==0);
	return UDR;
}


void  UART_Recieve_string(char * ptr)
{
	int i=0;
	ptr[i]=UART_Receive_Data();
	while(ptr[i] !='\r')
	{
		i++;
		ptr[i]=UART_Receive_Data();

	}
	ptr[i]='\0';
}
