#!/bin/bash

g++ -DDEBUG -DLOCAL -g -fsanitize=address -o sfml-demo.out sfml-demo.cpp -lsfml-graphics -lsfml-window -lsfml-system -lm && ./sfml-demo.out
rm -rf *.out
