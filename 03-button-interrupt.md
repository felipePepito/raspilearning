# Verwendung der Software PWM Bibliothek

Quelle:
https://projects.drogon.net/raspberry-pi/wiringpi/software-pwm-library/

Header:
	#include <softPwm.h>

Kompilieren mit pigpio bibliothek:
	g++ -o 03-button-interrupt 03-button-interrupt.cpp -lpigpio -lrt -lpthread


Zwei Funktionen stellt die Bibliothek zur Verfügung:
	int softPwmCreate(int pin, int initialValue, int pwmRange)
	// initialisiert einen Pin als PWM Pin.
	
	int softPwmWrite(int pin, int value)
	// schreibt einen neuen Wert

