#include "stm32f10x_usart.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "misc.h"
#include "stdio.h"
#include "semihosting/semihosting.h"
#include <string.h>
#define B_NUM 64
extern int jb,ib;
extern char commandset_BLE[15][25];
extern char checkset_BLE[15][25];
extern char nameBLE[B_NUM+1];

 void NVIC_Configuration_ble(void);
 void GPIO_Configuration_ble(void);
 void USART_Configuration_ble(void);
 void USART2_IRQHandler_ble(void);
 void UARTSend_ble(const unsigned char *pucBuffer, unsigned long ulCount);
 void start_Ble(void);
 int check_Ok_ble(char *ptr1);

void USART2_IRQHandler(void)
 {
     if ((USART2->SR & USART_FLAG_RXNE) != (u16)RESET)
 	{
 			ib = USART_ReceiveData(USART2);
 			if(jb == B_NUM)
 			{
                 nameBLE[jb] = ib;
 			    jb = 0;
 			}
 			else
 			{
                 nameBLE[jb++] = ib;
 			}
 			nameBLE[jb] = '\0';
 	}
 }

 void usart_init_ble(void)
 {
 	    const unsigned char menu[] = " Welcome to CDAC THE WAKEUP CALL AND THIS IS BATMAN NANANANANANANANANA THIS IS IRON MAN AND HE IS SMART BUT BATMAN IS DETECTIVE I LIKE DETECTIVES!\r\n";

 	    /* Enable USART2 and GPIOA clock */
 	    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
 	    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

 	    /* NVIC Configuration */
 	    NVIC_Configuration_ble();


 	    /* Configure the GPIOs */
 	    GPIO_Configuration_ble();

 	    /* Configure the USART2 */
 	    USART_Configuration_ble();

 	    /* Enable the USART2 Receive interrupt: this interrupt is generated when the
 	         USART2 receive data register is not empty */
 	    USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);

 	    /* print welcome information */

 	    for(int wak=0;wak<10;wak++)
 	    UARTSend_ble(menu, sizeof(menu));

 	    memset(nameBLE,0,sizeof(nameBLE));

 }

 void GPIO_Configuration_ble(void)
 {
   GPIO_InitTypeDef GPIO_InitStructure_2;

   /* Configure USART2 Tx (PA.02) as alternate function push-pull */
   GPIO_InitStructure_2.GPIO_Pin = GPIO_Pin_2;
   GPIO_InitStructure_2.GPIO_Mode = GPIO_Mode_AF_PP;
   GPIO_InitStructure_2.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_Init(GPIOA, &GPIO_InitStructure_2);

   /* Configure USART2 Rx (PA.3) as input floating */
   GPIO_InitStructure_2.GPIO_Pin = GPIO_Pin_3;
   GPIO_InitStructure_2.GPIO_Mode = GPIO_Mode_IN_FLOATING;
   GPIO_Init(GPIOA, &GPIO_InitStructure_2);
 }

 void USART_Configuration_ble(void)
 {
   USART_InitTypeDef USART_InitStructure_2;

 /* USART2 configuration ------------------------------------------------------*/
   /* USART2 configured as follow:
         - BaudRate = 115200 baud
         - Word Length = 8 Bits
         - One Stop Bit
         - No parity
         - Hardware flow control disabled (RTS and CTS signals)
         - Receive and transmit enabled
         - USART Clock disabled
         - USART CPOL: Clock is active low
         - USART CPHA: Data is captured on the middle
         - USART LastBit: The clock pulse of the last data bit is not output to
                          the SCLK pin
   */
   USART_InitStructure_2.USART_BaudRate = 9600;
   USART_InitStructure_2.USART_WordLength = USART_WordLength_8b;
   USART_InitStructure_2.USART_StopBits = USART_StopBits_1;
   USART_InitStructure_2.USART_Parity = USART_Parity_No;
   USART_InitStructure_2.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
   USART_InitStructure_2.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

   USART_Init(USART2, &USART_InitStructure_2);

   /* Enable USART2 */
   USART_Cmd(USART2, ENABLE);
 }




 void NVIC_Configuration_ble(void)
 {
   NVIC_InitTypeDef NVIC_InitStructure_2;

   /* Enable the USARTx Interrupt */
   NVIC_InitStructure_2.NVIC_IRQChannel = USART2_IRQn;
   NVIC_InitStructure_2.NVIC_IRQChannelPreemptionPriority = 0;
   NVIC_InitStructure_2.NVIC_IRQChannelSubPriority = 0;
   NVIC_InitStructure_2.NVIC_IRQChannelCmd = ENABLE;
   NVIC_Init(&NVIC_InitStructure_2);
 }

 void UARTSend_ble(const unsigned char *pucBuffer, unsigned long ulCount)
 {
     //
     // Loop while there are more characters to send.
     //
     while(ulCount--)
     {
         USART_SendData(USART2, *pucBuffer++);// Last Version USART_SendData(USART2,(uint16_t) *pucBuffer++);
         /* Loop until the end of transmission */
         while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET)
         {
         }
     }
 }
