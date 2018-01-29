/*
 * UART.h
 *
 *  Created on: Jan 16, 2018
 *      Author: Khalid
 */

#ifndef UART_H_
#define UART_H_


void UART_Init(unsigned long BaudRate);
void UART_Send_Data(unsigned char Data);
void UART_send_string( char *ptr);
unsigned char UART_Receive_Data();
void UART_Flush( void );
void  UART_Recieve_string(char * ptr);

#endif /* UART_H_ */
