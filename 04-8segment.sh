#!/bin/bash

action="r"
while [ "$action" != "q" ]
do


# determine ip address of raspi in wlan

	if [ -z ${ip+x} ]
	then
	    echo "determine ip address of raspberry pi with hostname 'raspberrypi'"
	    export ip=$(nmap -sP 192.168.2.0/24 | grep raspberrypi | awk {'print $6'} | sed 's/[()]//g')
	    if [ -z $ip ]
	    then
	            echo "unable to resolve ip address! Exiting..."
	            exit
	    fi
	    echo "ip is set to $ip"
	fi

	scp ~/Workspace/RasPi/04-8segment.cpp pi@$ip:04-8segment.cpp
	ssh pi@$ip "g++ -o 04-8segment 04-8segment.cpp -lpigpio -lrt -lpthread; sudo ./04-8segment"

	echo "Press enter to continue, 'q' to exit"
	read action
done