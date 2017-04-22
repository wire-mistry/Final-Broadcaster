#define NUM 512
extern char **commandset,**checkset,*name;
extern int i,j,k;


void collect_Esp(void){

	 int loop=0;
	 for(i=0;i<0x900000;i++);
	 for(i=0;i<0x900000;i++);
	 for(i=0;i<0x900000;i++);
	 for(i=0;i<0x900000;i++);
	 for(i=0;i<0x900000;i++);
	 for(i=0;i<0x900000;i++);
	 for(i=0;i<0x900000;i++);
	 for(i=0;i<0x900000;i++);
	 for(i=0;i<0x900000;i++);
	 for(i=0;i<0x900000;i++);



	  			memset(name,0,sizeof(name));
	  			j=0;

	  			while(loop!=1)
	  			{
	  				//"AT+CIPSTART=1,\"TCP\",\"things.ubidots.com\",80",
	  				UARTSend_esp(commandset[3], strlen(commandset[3]));
	  				for(i=0;i<0x500000;i++);

	  				if(check_Ok_esp(checkset[3]))
	  					loop=1;
	  			}

	  			loop=0;
	  			memset(name,0,sizeof(name));
	  			j=0;


	  			while(loop!=1)
	  			{
	  				//"AT+CIPSEND=0,169\r\n",
	  				UARTSend_esp(commandset[4], strlen(commandset[4]));
	  				for(i=0;i<0x5000;i++);
	  				if(check_Ok_esp(checkset[4]))
	  					loop=1;


	  			}

	  			loop=0;
	  			memset(name,0,sizeof(name));
	  			j=0;

	  			while(loop!=1)
	  			{
	  					//getrequest
	  				UARTSend_esp(commandset[5], strlen(commandset[5]));
	  				for(i=0;i<0x500000;i++);
	  				//if(check_Ok_esp())
	  					loop=1;

	  					printf("%s",name);
	  			}




 }
