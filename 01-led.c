#include <wiringPi.h>
#include <stdio.h>

#define LedGreen 1
#define LedRed 	0

void pwm(int intensity) {
	for(int i = 0; i < 10; i++) {
		digitalWrite(LedRed, HIGH);
		delay(intensity);
		digitalWrite(LedRed, LOW);
		delay(intensity-10);
	}
}

int main(void) {
	
	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}

	pinMode(LedGreen, OUTPUT);
	pinMode(LedRed, OUTPUT);
	while(1) {
		/*
		digitalWrite(LedGreen, LOW); 
		delay(1000);
		digitalWrite(LedGreen, HIGH);
		delay(1000);
		*/
		digitalWrite(LedRed, LOW);
		for(int j = 0; j < 10; j++) {
			pwm(j);
		}
		
		/*
		digitalWrite(LedRed, LOW);
		
		for(int i = 0; i < 1000; i++) {
			digitalWrite(LedRed, HIGH);
			delay(i*2);
			digitalWrite(LedRed, LOW);
			delay(2000-i*2);
		}
		*/
	}

	return 0;

}
