#include "uart.h"

        void usart_init(USART_TypeDef * USARTx, uint32_t baudrate)
        {
            switch(USART_TypeDef * USARTx){
                case 1: //UART1: APB2 (72MHz) - PA9 PA10}
                RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;
                break;
                case 2: //ART2: APB1 (36MHz) - PA2 PA3
                RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;
                break;
                case 3: //UART3: APB1 (36MHz) PB10 PB11
                RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN;
                break;

            }
 
        }
        void usart_send_char(USART_TypeDef * USARTx, uint8_t data)
        {

        }
        void usart_send_string(USART_TypeDef*, char*)
        {

        }
        uint8_t usart_receive_char(USART_TypeDef * USARTx)
        {

        }