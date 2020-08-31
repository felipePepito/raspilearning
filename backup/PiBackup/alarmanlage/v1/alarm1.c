#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <lcd.h>

#define LedAlarm 29
#define ButtonPin 25

const unsigned char Buf[] = "---Hello!!---";
const unsigned char myBuf[] = "check this out";

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

void displayTextLCD(int lcd, char text[]) {
		
	lcdClear(lcd);	
	int i;
	printf("%d \n", sizeof(text));
	for(i=0; i < sizeof(text) - 1; i++) {
		lcdPosition(lcd, i, 1);
		lcdPutchar(lcd, *(text+i));
		delay(200);
	}
		
}

int main(void) {
	
	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}
	
	printf("Alarmanlage laeuft \n");
	
	
	// Initialize LCD-Display
	int fd;
	fd = lcdInit(2,16,4, 2,3, 6,5,4,1,0,0,0,0); //see /usr/local/include/lcd.h
	
	if (fd == -1){
		printf("lcdInit 1 failed\n") ;
	}
	
	lcdClear(fd);
	lcdPosition(fd, 0, 0); 
	lcdPuts(fd, "Alarmanlage");

	lcdPosition(fd, 0, 1); 
	lcdPuts(fd, "läuft");

	delay(2000);
	lcdClear(fd);
	
	pinMode(ButtonPin, INPUT);
	pullUpDnControl(ButtonPin, PUD_UP); 
	char text[8];
	
	while(1){
		
		if(digitalRead(ButtonPin) == 0){ 
			
			displayTextLCD(fd, text);
			lcdClear(fd);
		}
	}

	alarm(0);
	
	
	return 0;
	
}
