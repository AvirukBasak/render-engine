#!/bin/bash

g++ -DDEBUG -DLOCAL -g -fsanitize=address -o reng-demo.out reng-demo.cpp -I../include -L../build/lib -lreng -lsfml-graphics -lsfml-window -lsfml-system -lm && ./reng-demo.out
