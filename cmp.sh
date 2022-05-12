#!/bin/bash

str=`./$2 "$3"`

if [ "$1" != "$str" ]; then
	exit 1
else
	exit 0
fi