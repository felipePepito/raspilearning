# Installation der WiringPi Library
sudo apt install wiringpi

# IP des RasPi finden


# Kopieren des Quellcodes auf den Raspi
scp Workspace/RasPi/01-led.c pi@192.168.2.119:01-led.c

# Kompilieren und starten auf dem Raspi
ssh pi@192.168.2.119 -p
gcc -Wall -o 01-led 01-led.c -lwiringPi
./01-led
