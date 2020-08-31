/**********************************************************************
* Filename    : led.c
* Description : Make an led blinking.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Date        : 2014/08/27
**********************************************************************/
#include <wiringPi.h>
#include <stdio.h>

#define LedGreen 	4
#define LedRed 	5
#define ButtonPin 23

int main(void)
{
	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}
	printf("linker LedPin : GPIO %d(wiringPi pin)\n",LedGreen); //when initialize wiring successfully,print message to screen
	
	pinMode(LedGreen, OUTPUT);
	pinMode(LedRed, OUTPUT);
	pinMode(ButtonPin, INPUT);

	pullUpDnControl(ButtonPin, PUD_UP); 
	
	int i;
	
	while(1){
			
			if(digitalRead(ButtonPin) == 0) {
				
				delay(50);
				printf("Buttonpressed\n");
			
			} else {
					
				digitalWrite(LedGreen, LOW);  //led on
				delay(100);
				
				digitalWrite(LedRed, LOW);  //led off			
				delay(500);

				digitalWrite(LedGreen, HIGH);  //led on
				delay(200);
				
				digitalWrite(LedRed, HIGH);  //led off			
				delay(50);	
				
				for(i = 0; i<30; i = i+1) {
					
					digitalWrite(LedRed, LOW);  		
					delay(i);
					digitalWrite(LedRed, HIGH);		
					delay(i);
				}
				
			}
	}

	return 0;
}

