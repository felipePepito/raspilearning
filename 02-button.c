#include <wiringPi.h>
#include <stdio.h>

#define LEDGREEN 25
#define LEDRED 	21

#define BUTTON1 28
#define BUTTON2 1

int main(void) {
	
	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}

	pinMode(LEDGREEN, OUTPUT);
	pinMode(LEDRED, OUTPUT);
	pinMode(BUTTON1, INPUT);
	pinMode(BUTTON2, INPUT);
	
	pullUpDnControl(BUTTON1, PUD_UP);
	
	while(1) {
		if(digitalRead(BUTTON1)==1) {
			digitalWrite(LEDGREEN, 1);
		} else {
			digitalWrite(LEDGREEN, 0);
		}
	}

	return 0;

}
