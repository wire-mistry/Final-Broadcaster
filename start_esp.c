#define NUM 512
char commandset[7][256]={
 						"AT\r\n",/*AT check*/
 						//"AT+CWJAP=\"Whack\",\"123123123\"\r\n",/*Acess point name and pwd*/
 						//"AT+CWJAP=\"project101\",\"123123123\"\r\n",
 						"AT+CIPMODE=0\r\n",/*mode set needs to be set at zero to enable CIPMUX*/
 						"AT+CIPMUX=1\r\n",/*mode set needs to be set at zero to enable CIPMUX*/
 						"AT+CIPSTART=1,\"TCP\",\"things.ubidots.com\",80\r\n",/*etablising TCP connection with connection name "1" with cloud IP*/
 						"AT+CIPSEND=1,169\r\n",/*GET request length and responding to the "1" connection made over TCP*/
 						"GET http://things.ubidots.com/api/v1.6/variables/5883a35476254263119ae1fa/values/?page_size=1&token=ULrIhhzRYNrYJXOJyRrNJwnbcd10sE HTTP/1.1\r\nHost: things.ubidots.com\r\n\r\n"

 						//"AT+CIPSERVER=0\r\n"

 					};
 char checkset[7][256]={//respective replies array
 					"AT\r\r\n\r\nOK\r\n",
 					//"AT+CWJAP=\"Whack\",\"123123123\"\r\r\nWIFI DISCONNECT\r\nWIFI CONNECTED\r\nWIFI GOT IP\r\n",
 					"AT+CIPMODE=0\r\r\n\r\nOK\r\n",
 					"AT+CIPMUX=1\r\r\n\r\nOK\r\n",
 					"AT+CIPSTART=1,\"TCP\",\"things.ubidots.com\",80\r\r\n1,CONNECT\r\n\r\nOK\r\n",
 					"AT+CIPSEND=1,169\r\r\n\r\nOK\r\n> ",




 					};

 extern char **name;
 extern int i,j,k;

 void start_Esp(void)
  {
  int loop=0;

  j=0;
      printf("six starting ESP inside\r");
  	//while(loop!=1)

      UARTSend_esp("AT+RST\r\n",strlen("AT+RST\r\n"));
      memset(name,0,sizeof(name));

      for(i=0;i<0x900000;i++);
     		 for(i=0;i<0x900000;i++);
     		 for(i=0;i<0x900000;i++);

      memset(name,0,sizeof(name));


  			while(loop!=1)
  			{
  				//AT-OK

  				UARTSend_esp(commandset[0],strlen(commandset[0]));
  				for(i=0;i<0x100000;i++);
  				printf("%s",name);
  				if(check_Ok_esp(checkset[0]))
  					loop=1;

  			}

  				loop=0;
  				memset(name,0,sizeof(name));
  				j=0;


  			while(loop!=1)
  			{
  				//"AT+CIPMODE=0\r\n"
  				UARTSend_esp(commandset[1], strlen(commandset[1]));
  				for(i=0;i<0x100000;i++);
  				if(check_Ok_esp(checkset[1]))
  					loop=1;
  			}

  			loop=0;
  			memset(name,0,sizeof(name));
  			j=0;

  			while(loop!=1)
  			{
  				//"AT+CIPMUX=1\r\n",
  				UARTSend_esp(commandset[2], strlen(commandset[2]));
  				for(i=0;i<0x100000;i++);
  				if(check_Ok_esp(checkset[2]))
  					loop=1;
  			}

  			loop=0;
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
  				for(i=0;i<0x100000;i++);
  				//if(check_Ok_esp())
  					loop=1;

  					printf("%s",name);
  			}
  	printf("loop endiiiiiiiiiiiiiiiiiiiiiiiiiiiiiing\r");
  }
