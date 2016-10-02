#!/bin/bash
# change resouce

sed '/main/, /XXX/d' 000.cpp > 001.cpp
cat $1 >> 001.cpp
rm -f 000.cpp
cp ./001.cpp ./000.cpp
g++ ./000.cpp -g -std=c++11 -o ./000
./000
