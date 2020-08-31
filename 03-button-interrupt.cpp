// g++ -o 02-button 02-button.cpp -lwiringPi -lpthread

#include <pigpio.h>
#include <iostream>



#define LEDGREEN 25
#define LEDRED 	21

#define BUTTON1 20
#define BUTTON2 1

void alert(int gpio, int level, uint32_t tick) {
	std::cout << "Button pressed - level: " << level << std::endl;
	time_sleep(0.01);
}

int main() {
	
	if (gpioInitialise()<0) return 1;
	
	// initialize input
	gpioSetMode(BUTTON1, PI_INPUT);
	gpioSetPullUpDown(BUTTON1, PI_PUD_UP);
	gpioSetAlertFunc(BUTTON1, alert);
	
	time_sleep(60);
	return 0;

}
