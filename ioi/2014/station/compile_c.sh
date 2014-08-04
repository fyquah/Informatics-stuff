#!/bin/sh
NAME=station
/usr/bin/gcc -std=c11   -O2 -DEVAL -o $NAME grader.c   $NAME.c   -lm -static
