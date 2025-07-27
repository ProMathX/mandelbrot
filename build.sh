#!/bin/bash

echo 'building file'

gcc -o bin/mandelbrot src/main.c  $(sdl2-config --cflags --libs) -lm

echo 'executing binary'

exec bin/mandelbrot

