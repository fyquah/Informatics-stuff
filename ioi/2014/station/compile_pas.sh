#!/bin/sh
NAME=station
/usr/bin/fpc -dEVAL -O2 -o$NAME -XS grader.pas
