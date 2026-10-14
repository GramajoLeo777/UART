#ifndef uart_h
#define uart_h
#include "stm32f103xb.h"

        typedef struct{
            USART_TypeDef * USARTx; //UART1, UART2, UART3
            
        }USART_TypeDef_t;    



        void usart_init(USART_TypeDef * USARTx, uint32_t baudrate);
        void usart_send_char(USART_TypeDef * USARTx, uint8_t data);
        void usart_send_string(USART_TypeDef* USARTx, char*texto);
        uint8_t usart_receive_char(USART_TypeDef * USARTx);

#endif 