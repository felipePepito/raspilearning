#!/bin/bash

filename="05-pir"

action="r"
while [ "$action" != "q" ]
do


# determine ip address of raspi in wlan

	if [ -z ${ip+x} ]
	then
	    echo "determine ip address of raspberry pi with hostname 'raspberrypi'"
	    export ip=$(nmap -sn 192.168.2.0/24 | grep raspberrypi | awk {'print $6'} | sed 's/[()]//g')
	    if [ -z $ip ]
	    then
	            echo "unable to resolve ip address! Exiting..."
	            exit
	    fi
	    echo "ip is set to $ip"
	fi

	scp ~/Workspace/RasPi/$filename.cpp pi@$ip:$filename.cpp
	ssh pi@$ip "g++ -o $filename $filename.cpp -lpigpio -lrt -lpthread; sudo ./$filename"

	echo "Press enter to continue, 'q' to exit"
	read action
done