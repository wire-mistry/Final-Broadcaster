#include "stm32f10x_usart.h"
#include "stm32f10x_rcc.h"
//All printf statements are for debug resons

#include "stm32f10x_gpio.h"
#include "misc.h"
#include "stdio.h"
#include "semihosting/semihosting.h"
#include <string.h>
#include "var.h"
ErrorStatus HSEStartUpStatus;//keep the startup error status

void NVIC_Configuration_ble(void);
void GPIO_Configuration_ble(void);
void USART_Configuration_ble(void);
void USART2_IRQHandler_ble(void);
void UARTSend_ble(const unsigned char *pucBuffer, unsigned long ulCount);
void start_Ble(void);
int check_Ok_ble(char *ptr1);


void NVIC_Configuration(void);
void GPIO_Configuration(void);
void USART_Configuration(void);
void USART1_IRQHandler(void);
void usart_init_ble(void);
void UARTSend_esp(const unsigned char *pucBuffer, unsigned long ulCount);
void start_Esp(void);
void collect_Esp(void);

int main(void){


	usart_init_esp();
	usart_init_ble();
	int trav;

	start_Esp();
	start_Ble();
	delay();
	collect_Esp();
			trav=478;

			for(int s=0;s<4;s++)
				becconstring[0][s]=name[trav++];

			printf("%s",becconstring);

			trav=492;

			for(int s=0;s<4;s++)
						becconstring[1][s]=name[trav++];

			printf("%s",becconstring[1]);



			set_Becon(becconstring);

			printf("%s",becconstring);
	while(1)
	{

		collect_Esp();
		trav=478;

		for(int s=0;s<4;s++)
			becconstring[0][s]=name[trav++];

		printf("%s",becconstring);

		trav=492;

		for(int s=0;s<4;s++)
					becconstring[1][s]=name[trav++];

		printf("%s",becconstring[1]);



		set_Becon(becconstring);

		printf("%s",becconstring);

		set_Becon(becconstring1);

		delay();
	}






}
