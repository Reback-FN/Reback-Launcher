#!/bin/bash

mkdir -p build

g++ -o build/Reback.exe src/main.cpp -lsfml-graphics -lsfml-window -lsfml-system -mwindows

cp arial.ttf build/

if [ $? -eq 0 ]; then
    echo "Reback Launcher Compiled Successfully !"
else
    echo "Error to compile the Reback Launcher."
fi