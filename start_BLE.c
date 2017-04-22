#include <stdio.h>
#define B_NUM 64

extern int jb,ib;
extern char commandset_BLE[15][25];
extern char checkset_BLE[15][25];
extern char nameBLE[B_NUM+1];

void start_Ble(void){

 	int loop=0;
 	memset(nameBLE,0,sizeof(nameBLE));
 	    printf("Starting Ble inside\r");
 		//while(loop!=1)

 				while(loop!=1)
 				{
 					//"AT+RENEW",




 					UARTSend_ble(commandset_BLE[0],strlen(commandset_BLE[0]));
 					for(ib=0;ib<0x100000;ib++);
 					printf("%s",nameBLE);
 					if(check_Ok_ble(checkset_BLE[0]))
 						loop=1;

 				}


 				loop=0;
 				memset(nameBLE,0,sizeof(nameBLE));
 				jb=0;

 				while(loop!=1)
 				{
 					//""AT+RESET",


 					UARTSend_ble(commandset_BLE[1], strlen(commandset_BLE[1]));
 					for(ib=0;ib<0x100000;ib++);
 					if(check_Ok_ble(checkset_BLE[1]))
 						loop=1;
 				}

 				loop=0;
 				memset(nameBLE,0,sizeof(nameBLE));
 				jb=0;


 				while(loop!=1)
 				{
 					//"AT+MARJ0x1234",


 					UARTSend_ble(commandset_BLE[2], strlen(commandset_BLE[2]));
 					for(ib=0;ib<0x100000;ib++);
 					if(check_Ok_ble(checkset_BLE[2]))
 						loop=1;
 				}

 				loop=0;
 				memset(nameBLE,0,sizeof(nameBLE));
 				jb=0;

 				//
 				while(loop!=1)
 				{
 					//""AT+MINO0xFA01",


 					UARTSend_ble(commandset_BLE[3], strlen(commandset_BLE[3]));
 					for(ib=0;ib<0x100000;ib++);
 					if(check_Ok_ble(checkset_BLE[3]))
 						loop=1;
 				}

 				loop=0;
 				memset(nameBLE,0,sizeof(nameBLE));
 				jb=0;


 				while(loop!=1)
 				{
 					//""AT+ADVI5",


 					UARTSend_ble(commandset_BLE[4], strlen(commandset_BLE[4]));
 					for(ib=0;ib<0x100000;ib++);
 					if(check_Ok_ble(checkset_BLE[4]))
 						loop=1;
 				}

 				loop=0;
 				memset(nameBLE,0,sizeof(nameBLE));
 				jb=0;



 				while(loop!=1)
 				{
 					//""AT+NAMECDACHYD",


 					UARTSend_ble(commandset_BLE[5], strlen(commandset_BLE[5]));
 					for(ib=0;ib<0x100000;ib++);
 					if(check_Ok_ble(checkset_BLE[5]))
 						loop=1;
 				}

 				loop=0;
 				memset(nameBLE,0,sizeof(nameBLE));
 				jb=0;


 				while(loop!=1)
 				{
 					//"AT+ADTY3",


 					UARTSend_ble(commandset_BLE[6], strlen(commandset_BLE[6]));
 					for(ib=0;ib<0x100000;ib++);
 					if(check_Ok_ble(checkset_BLE[6]))
 						loop=1;
 				}

 				loop=0;
 				memset(nameBLE,0,sizeof(nameBLE));
 				jb=0;

 				while(loop!=1)
 				{
 					//"AT+IBEA1",


 					UARTSend_ble(commandset_BLE[7], strlen(commandset_BLE[7]));
 					for(ib=0;ib<0x100000;ib++);
 					if(check_Ok_ble(checkset_BLE[7]))
 						loop=1;
 				}

 				loop=0;
 				memset(nameBLE,0,sizeof(nameBLE));
 				jb=0;

 				while(loop!=1)
 				{
 					//""AT+DELO2",


 					UARTSend_ble(commandset_BLE[8], strlen(commandset_BLE[8]));
 					for(ib=0;ib<0x100000;ib++);
 					if(check_Ok_ble(checkset_BLE[8]))
 						loop=1;
 				}
 				loop=0;
 				memset(nameBLE,0,sizeof(nameBLE));
 				jb=0;


 				while(loop!=1)
 				{
 					//"AT+PWRM0"
 					UARTSend_ble(commandset_BLE[9], strlen(commandset_BLE[9]));
 					for(ib=0;ib<0x100000;ib++);
 					if(check_Ok_ble(checkset_BLE[9]))
 						loop=1;
 				}

 				loop=0;
 				memset(nameBLE,0,sizeof(nameBLE));
 				jb=0;

 				while(loop!=1)
 				{
 					//AT+RESET
 					UARTSend_ble(commandset_BLE[1], strlen(commandset_BLE[1]));
 					for(ib=0;ib<0100000;ib++);
 					if(check_Ok_ble(checkset_BLE[1]))
 						loop=1;
 				}

 				loop=0;
 				memset(nameBLE,0,sizeof(nameBLE));
 				jb=0;

 				char wkup[]=" Welcome to CDAC THE WAKEUP CALL AND THIS IS BATMAN NANANANANANANANANA THIS IS IRON MAN AND HE IS SMART BUT BATMAN IS DETECTIVE I LIKE DETECTIVES!\r\n";

					//wakeup through above string
 				for(ib=0;ib<20;ib++)
 				UARTSend_ble(wkup, strlen(wkup));
 				memset(nameBLE,0,sizeof(nameBLE));


 }
