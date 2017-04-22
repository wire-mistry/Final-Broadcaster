
#include "stm32f10x_usart.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "misc.h"
#include "stdio.h"
#include "semihosting/semihosting.h"
#include <string.h>

void UARTSend_esp(const unsigned char *pucBuffer, unsigned long ulCount);
void NVIC_Configuration(void);
void GPIO_Configuration(void);
void USART_Configuration(void);
void USART1_IRQHandler(void);
extern char **name;
extern int i,j,k;
#define NUM 512
void usart_init_esp(void)
{
	    char msg[] = "This is test Message from user\n";
	    /* Enable USART1 and GPIOA clock */
	    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);

	    /* NVIC Configuration */
	    NVIC_Configuration_esp();

        printf("one\r");
	    /* Configure the GPIOs */
	    GPIO_Configuration_esp();
	    printf("two\r");
	    /* Configure the USART1 */
	    USART_Configuration_esp();
	    printf("three\r");
	    /* Enable the USART1 Receive interrupt: this interrupt is generated when the
	         USART1 receive data register is not empty */
	    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	    printf(" four\r");
	    /* print welcome information */
	    UARTSend_esp("\r\n",2);
	    memset(name,0,sizeof(name));
	    //required to avoid transaction error
	    printf("five\r");
}


/***** USART1 IRQ Handler *****/

 void USART1_IRQHandler(void)
{
    if ((USART1->SR & USART_FLAG_RXNE) != (u16)RESET)
	{
			k =USART_ReceiveData(USART1);
			if(j == NUM)
			{

                name[j] = k;
			    j = 0;

			}
			else
			{


                name[j++] = k;


			}
			name[j] = '\0';

	}

}
/***************************************/

/***** USART1 IRQ Handler *****/





 /***************************************/



 void GPIO_Configuration_esp(void)
 {
   GPIO_InitTypeDef GPIO_InitStructure;

   /* Configure USART1 Tx (PA.09) as alternate function push-pull */
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_Init(GPIOA, &GPIO_InitStructure);

   /* Configure USART1 Rx (PA.10) as input floating */
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
   GPIO_Init(GPIOA, &GPIO_InitStructure);
 }

 void UARTSend_esp(const unsigned char *pucBuffer, unsigned long ulCount)
 {
     //
     // Loop while there are more characters to send.
     //
     while(ulCount--)
     {
         USART_SendData(USART1, *pucBuffer++);// Last Version USART_SendData(USART1,(uint16_t) *pucBuffer++);
         /* Loop until the end of transmission */
         while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
         {
         }
     }
 }

 void NVIC_Configuration_esp(void)
 {
   NVIC_InitTypeDef NVIC_InitStructure;

   /* Enable the USARTx Interrupt */
   NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
   NVIC_Init(&NVIC_InitStructure);
 }

 void USART_Configuration_esp(void)
 {
   USART_InitTypeDef USART_InitStructure;

 /* USART1 configuration ------------------------------------------------------*/
   /* USART1 configured as follow:
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
   USART_InitStructure.USART_BaudRate = 115200;
   USART_InitStructure.USART_WordLength = USART_WordLength_8b;
   USART_InitStructure.USART_StopBits = USART_StopBits_1;
   USART_InitStructure.USART_Parity = USART_Parity_No;
   USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
   USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

   USART_Init(USART1, &USART_InitStructure);

   /* Enable USART1 */
   USART_Cmd(USART1, ENABLE);
 }
