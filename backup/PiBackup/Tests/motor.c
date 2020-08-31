/**********************************************************************
* Filename    : motor.c
* Description : Controlling a motor.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Date        : 2014/08/27
**********************************************************************/
#include <wiringPi.h>
#include <stdio.h>

#define MotorPin1    0
#define MotorPin2    1
#define MotorEnable  2
#define Button 4

void toggle(void) {
	if (digitalRead(MotorEnable) == LOW) {
		digitalWrite(MotorEnable, HIGH);
		printf("It's getting hot in here - Cool it!\n");
	} else {
		digitalWrite(MotorEnable, LOW);
		printf("Shut up.\n");
	}
}

int main(void)
{
	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}
	
	pinMode(MotorPin1, OUTPUT);
	pinMode(MotorPin2, OUTPUT);
	pinMode(MotorEnable, OUTPUT);
	pinMode(Button, INPUT);
	
	digitalWrite(MotorEnable, HIGH);
	digitalWrite(MotorPin1, HIGH);
	digitalWrite(MotorPin2, LOW);
	
	pullUpDnControl(Button, PUD_UP);


	while(1){
		

		if (digitalRead(Button) == 0) {
			toggle();
			//printf("toggle\n");
		}
				
		delay(1000);

	}

	return 0;
}
