#include <string.h>

extern int jb,ib;
extern char nameBLE,becon,beconchk;
char commandset_BLE[15][25]={
							"AT+RENEW",
							"AT+RESET",
							"AT+MARJ0x1234",
							"AT+MINO0xFA01",
							"AT+ADVI5",
							"AT+NAMECDACHYD",
							"AT+ADTY3",
							"AT+IBEA1",
							"AT+DELO2",
							"AT+PWRM0"
					};

char checkset_BLE[15][25]={
							"OK+RENEW",
							"OK+RESET",
							"OK+Set:0x1234",
							"OK+Set:0xFA01",
							"OK+Set:5",
							"OK+Set:CDACHYD",
							"OK+Set:3",
							"OK+Set:1",
							"OK+DELO2",
							"OK+Set:0",
							"OK+WAKE"



					};

void set_Becon(char str[][9])
 {

 			int loop=0;
 			int p=0;

 			for(int bec=2;bec<4;bec++){


 				char atib[]="AT+IBE";
 				char atibr[]="OK+Set:0x";


 				sprintf(becon,"%s%d%s",atib,bec,str[p]);
 				sprintf(beconchk,"%s%s",atibr,str[p]);

 				while(loop!=1)
 				{
 					UARTSend_ble(becon, strlen(becon));
 					for(ib=0;ib<0x100000;ib++);
 					if(check_Ok_ble(beconchk))
 						loop=1;
 				}
 				loop=0;
 				p++;
 			}


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



 }
