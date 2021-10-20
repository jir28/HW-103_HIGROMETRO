/*
 Jair Zamorano Garcia UAM Lerma
 */

#include <wiringPi.h>
#include <stdio.h>
#include <time.h>
#include <signal.h>

#define SEN 21
#define BLUE 19
#define RED 26

int blink = 1;

void cleanup(int signo){
	blink = 0;
	}

int main (void){
	
  signal(SIGINT, cleanup);
  signal(SIGTERM, cleanup);
  signal(SIGHUP, cleanup);
	
  wiringPiSetupGpio() ;
  pinMode(SEN, INPUT) ;
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);

  while(blink){
	  digitalWrite(BLUE, LOW);
	  digitalWrite(RED, LOW);
	  if(digitalRead(SEN)==0){
		  
		  digitalWrite (BLUE, HIGH);
         	  printf("Hay Humedad \n");
          
	  }
          
       else{
		   digitalWrite(RED, HIGH);
		   printf("NO humedad \n");
		   }
      delay(1200);    
		  
    }
  
  digitalWrite(BLUE, LOW);
  digitalWrite(RED, LOW);
  digitalWrite(SEN, LOW);
	
  pinMode(BLUE, INPUT);
  pinMode(RED, INPUT);
  pinMode(SEN, INPUT);
  return 0 ;
}
