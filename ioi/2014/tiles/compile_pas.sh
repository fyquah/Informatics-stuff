#!/bin/sh
NAME=tile
/usr/bin/fpc -dEVAL -O2 -o$NAME -XS grader.pas
