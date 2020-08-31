#!/bin/bash

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
else
    echo $ip
fi

scp ~/Workspace/RasPi/02-button.cpp pi@$ip:02-button.cpp

