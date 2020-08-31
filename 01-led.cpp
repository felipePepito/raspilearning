#include <pigpio.h>
#include <iostream>

const int pin0 = 5;

int main(void) {
	
	if (gpioInitialise()<0) return 1;

	gpioSetMode(pin0, PI_OUTPUT);

	while(1) {
		
		for (int i = 0; i <= 255; i++) {
			gpioPWM(pin0, i);
			time_sleep(0.01);
		}
		
	}

	return 0;

}
