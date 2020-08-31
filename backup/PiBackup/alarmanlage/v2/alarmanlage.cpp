#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

#define LedAlarm 29

int alarm(int alarmTyp) {
	
	pinMode(LedAlarm, OUTPUT);
	
	int i = 0;
	while (i < 10) {
		digitalWrite(LedAlarm, LOW);  //led on
		delay(500);
		printf("alarm \n");
			
		digitalWrite(LedAlarm, HIGH);  //led off			
		delay(200);
		i++;
	}
	
	return 0;
}

int main() {
	
	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}
	
	printf("Alarmanlage laeuft \n");
	
	

	alarm(0);
	
	
	return 0;
	
}
