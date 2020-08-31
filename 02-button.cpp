// g++ -o 02-button 02-button.cpp -lwiringPi -lpthread

#include <wiringPi.h>
#include <iostream>
#include <softPwm.h> 


#define LEDGREEN 25
#define LEDRED 	21

#define BUTTON1 28
#define BUTTON2 1

// Konstanten für bessere Lesbarkeit
#define YES 0
#define NO 1
#define PRESSED true
#define NOTPRESSED false


struct LedState {
	int pin;
	int brightness; // anything from 0 to 100 (see pwm range)
	int dimDirection; // 1 -> up, 0 -> down
};

LedState adjustBrightness(LedState currentState) {
	if (currentState.dimDirection == 1) {
		if (currentState.brightness < 100) {
			currentState.brightness += 20;
		} else {
			currentState.brightness -= 20;
			currentState.dimDirection = 0;
		}
	} else {
		if (currentState.brightness > 0) {
			currentState.brightness -= 20;
		} else {
			currentState.brightness += 20;
			currentState.dimDirection = 1;
		}
	}
			
	softPwmWrite(currentState.pin, currentState.brightness);
	return currentState;
}

int main() {
	
	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}

	// initialize pins
	pinMode(LEDGREEN, OUTPUT);
	pinMode(LEDRED, OUTPUT);
	pinMode(BUTTON1, INPUT);
	pinMode(BUTTON2, INPUT);
	pullUpDnControl(BUTTON1, PUD_UP);
	
	// flag if button was pressed
	bool buttonPressedFlag = NOTPRESSED;
	
	// initialize green LED
	int ledStateGreen = 0;
	digitalWrite(LEDGREEN, 0);
	
	// initialize red LED
	LedState ledStateRed = { LEDRED, 1, 0 };
	softPwmCreate(ledStateRed.pin, ledStateRed.brightness, 100);
	
	while(1) {
		
		int buttonPressed = digitalRead(BUTTON1);
		
		if(buttonPressed==YES && buttonPressedFlag==NOTPRESSED) {
			
			if (ledStateGreen == 0) {
				digitalWrite(LEDGREEN, 1);
				ledStateGreen = 1;
				
				delay(200);
			} else {
				digitalWrite(LEDGREEN, 0);
				ledStateGreen = 0;
				delay(200);
			}
			buttonPressedFlag = PRESSED;
			//std::cout << "Gedrückt\n" << std::endl;
			ledStateRed = adjustBrightness(ledStateRed);
			
		} else if (buttonPressed==NO && buttonPressedFlag==PRESSED) {
			buttonPressedFlag = NOTPRESSED;
			//std::cout << "Losgelassen\n" << std::endl;
		}
	}

	return 0;

}
