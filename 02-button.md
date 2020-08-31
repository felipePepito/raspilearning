# Verwendung der Software PWM Bibliothek

Quelle:
https://projects.drogon.net/raspberry-pi/wiringpi/software-pwm-library/

Header:
	#include <softPwm.h>

Kompilieren mit pthread bibliothek:
	g++ -o 02-button 02-button.cpp -lwiringPi -lpthread

Zwei Funktionen stellt die Bibliothek zur Verfügung:
	int softPwmCreate(int pin, int initialValue, int pwmRange)
	// initialisiert einen Pin als PWM Pin.
	
	int softPwmWrite(int pin, int value)
	// schreibt einen neuen Wert

