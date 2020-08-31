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
	pinMode(MotorPin2, PWM_OUTPUT);
	pinMode(MotorEnable, OUTPUT);
	pinMode(Button, INPUT);
	
	digitalWrite(MotorEnable, HIGH);
	digitalWrite(MotorPin1, LOW);
	digitalWrite(MotorPin2, LOW);
	
	pullUpDnControl(Button, PUD_UP);
	
	int i;


	while(1){
		
		digitalWrite(MotorEnable, HIGH);
		printf("+\n");
		for (i = 700; i < 1023; i++) {
			pwmWrite(MotorPin2, i);
			delay(20);
			
		}	
		delay(1000);
		for (; i > 700; i--) {
			pwmWrite(MotorPin2, i);
			delay(20);
			
		}	
		delay(1000);
		for (i = 700; i < 1023; i++) {
			pwmWrite(MotorPin2, i);
			delay(20);
			
		}	
		
		digitalWrite(MotorEnable, LOW);

		printf("-\n");
		delay(3000);
	}

	return 0;
}
