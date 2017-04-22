#define B_NUM 64
#define NUM 512
#define delay() {\
					for(i=0;i<0x900000;i++);\
					for(i=0;i<0x900000;i++);\
				}


int ib,jb,i,j,k;
char nameBLE[B_NUM+1] = {'\0'};//BLE USART REC BUFFER
char becon[16]={"\0"};
char beconchk[17]={"\0"};
char name[NUM+1] = {'\0'};
char becconstring[2][9]={

						49,48,48,48,48,48,48,48,'\0',
						49,48,48,48,48,48,48,48,'\0'


};//initialising with zero

char becconstring1[2][9]={

							48,48,48,48,48,48,48,49,'\0',
							48,48,48,48,48,48,48,49,'\0'


	};
