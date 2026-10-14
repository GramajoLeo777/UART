#include "uart.h"

#define PA9 9 // TX USART1
#define PA10 10
#define PA2 2
#define PA3 3
#define PB10 10
#define PB11 11
        void usart_init(USART_TypeDef * USARTx, uint32_t baudrate) //Prende todas las funciones 
        {
            int pclk=0;
            if (USARTx==USART1){
                RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;
                RCC -> APB2ENR |= RCC_APB2ENR_USART1EN;
                GPIOA -> CRH &~(0xF << PA9);
                GPIOA -> CRH |=(0xB << PA9);
                GPIOA -> CRH &~(0xF << PA10);
                GPIOA -> CRH |=(0x4 << PA10);
                pclk=72000000;
                
            }
            if (USARTx==USART2){
                RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;
                RCC -> APB1ENR |= RCC_APB1ENR_USART2EN;
                GPIOA -> CRL &~(0xF << PA2);
                GPIOA -> CRL |=(0xB << PA2);
                GPIOA -> CRL &~(0xF << PA3);
                GPIOA -> CRL |=(0x4 << PA3);
                pclk=36000000;
                
            }
            if (USARTx==USART3){
                RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;
                RCC -> APB2ENR |= RCC_APB1ENR_USART3EN;
                GPIOA -> CRL &~(0xF << PB10);
                GPIOA -> CRL |=(0xB << PB10);
                GPIOA -> CRL &~(0xF << PB11);
                GPIOA -> CRL |=(0x4 << PB11);
                pclk=36000000;
            }
            float div = ((16*baudrate)/72000000);
            int matissa = div; //solo parte entera de div
            int fraction  = (div-matissa)*100; //la parte de coma  
            USARTx  ->  BRR   = (matissa << 4)|fraction;
            USARTx  ->  CR1   |= USART_CR1_UE; //8 bits
            USARTx->CR1 |=USART_CR1_TE|USART_CR1_RE;
        }
        
        void usart_send_char(USART_TypeDef * USARTx, uint8_t data) //DEBO ENVIAR DATOS, DR
        {
            USARTx->DR=data;
            while(!(USARTx -> SR & USART_SR_TXE)); // :O omg
        }

        void usart_send_string(USART_TypeDef* USARTx, char*texto) //enviar cadenas de carecteres
        {
            while(*texto){
                usart_send_char(USARTx, *texto);
                texto++;
            }
        }
        
        uint8_t usart_receive_char(USART_TypeDef * USARTx) //lectura SR
        {
             while(!(USARTx -> SR & USART_SR_TXE));
             return USARTx->DR;//flama
    }
