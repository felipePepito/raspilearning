
#include <pigpio.h>
#include <iostream>


const int pirInput = 22;
const int ledRed = 5;
const int ledGreen = 26;

const int segment1 = 18;
const int segment2 = 23;
const int segment3 = 24;
const int segment4 = 25;

pthread_t *thread1;


void alert(int gpio, int level, uint32_t tick);
void dim(int pin);
void *looping(void * arg);

int main() {

	
	if (gpioInitialise()<0) return 1;
	
	// initialize Pins
	gpioSetMode(pirInput, PI_INPUT);
	gpioSetMode(ledGreen, PI_OUTPUT);
	gpioSetMode(ledRed, PI_OUTPUT);

	gpioWrite(ledGreen, 1);
	gpioWrite(ledRed, 0);

	gpioSetMode(segment1, PI_OUTPUT);
	gpioSetMode(segment2, PI_OUTPUT);
	gpioSetMode(segment3, PI_OUTPUT);
	gpioSetMode(segment4, PI_OUTPUT);

	

	gpioSetAlertFunc(pirInput, alert);
	
	time_sleep(60);
	return 0;

}

void alert(int gpio, int level, uint32_t tick) {
	if(level > 0.5) {
		std::cout << "Motion detected at " << tick << std::endl;
		gpioWrite(ledGreen, 0);
		gpioWrite(ledRed, 1);
		thread1 = gpioStartThread(looping, NULL);

	} else {
		std::cout << "No more motion at " << tick << std::endl;
		gpioWrite(ledGreen, 1);
		gpioWrite(ledRed, 0);
		gpioStopThread(thread1);

		
	}
	
	time_sleep(0.01);
}

void *looping(void *arg) {
	for (int i = 0; i<3; i++) {
		dim(segment1);
		dim(segment2);
		dim(segment3);
		dim(segment4);
	}
}

void dim(int pin) {
	for (int i = 0; i <= 255; i++) {
			gpioPWM(pin, i);
			time_sleep(0.002);
		}
		for (int i = 255; i >=0; i--) {
			gpioPWM(pin, i);
			time_sleep(0.002);
		}
}