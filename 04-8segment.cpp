// g++ -o 02-button 02-button.cpp -lwiringPi -lpthread

#include <pigpio.h>
#include <iostream>



#define LEDGREEN 25
#define LEDRED 	21

#define BUTTON1 20
#define BUTTON2 1

const int pin1 = 18;
const int pin2 = 23;
const int pin3 = 24;
const int pin4 = 25;

void dim(int pin);

int main() {
	
	if (gpioInitialise()<0) return 1;
	
	// initialize input
	gpioSetMode(pin1, PI_OUTPUT);
	gpioSetMode(pin2, PI_OUTPUT);
	gpioSetMode(pin3, PI_OUTPUT);
	gpioSetMode(pin4, PI_OUTPUT);

	for (int i = 0; i<10; i++) {

		dim(pin1);
		dim(pin2);
		dim(pin3);
		dim(pin4);
	}

	return 0;

}

void dim(int pin) {
	for (int i = 0; i <= 255; i++) {
			gpioPWM(pin, i);
			time_sleep(0.005);
		}
		for (int i = 255; i >=0; i--) {
			gpioPWM(pin, i);
			time_sleep(0.005);
		}
}
