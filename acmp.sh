#!/bin/bash


adb push $2 /data/local/tmp

str=`adb shell "cd /data/local/tmp && ./$2 \"$3\""`

if [ "$1" != "$str" ]; then
	exit 1
else
	exit 0
fi