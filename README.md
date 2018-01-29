# USART-Communication
Usart - Universal Synchronous and Asynchronous serial Receiver and Transmitter - / - Atmega32 -
Here i have used it as an Asynchronous Communication (UART)

## Full Duplex Operation
## Asynchronous
## One Master - One Slave 
## Customizable BaudRate
## 8 Data Bits 
## 1 Stop Bit

# APIs 

### void UART_Init(unsigned long BaudRate); // You can choose your onw boudrate

### void UART_Send_Data(unsigned char Data); // Send Data 'Char'
### void UART_send_string( char *ptr); // Send String 'Char * String'
### unsigned char UART_Receive_Data(); // Return UDR (Unsigned char)
### void UART_Flush( void ); // Flushing the buffer Register
### void  UART_Recieve_string(char * ptr); // Receive String takes a pointer 'Char * String'
