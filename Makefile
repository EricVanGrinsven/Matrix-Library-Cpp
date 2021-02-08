# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g
 
# ****************************************************
# Targets needed to bring the executable up to date
 
main: main.o BrainMatrix.o MatrixMath.o
	$(CC) $(CFLAGS) -o main main.o BrainMatrix.o MatrixMath.o 
# The main.o target can be written more simply
 
main.o: main.cpp BrainMatrix.h MatrixMath.h
	$(CC) $(CFLAGS) -c main.cpp
 
BrainMatrix.o: BrainMatrix.h

MatrixMath.o: MatrixMath.h BrainMatrix.h

clean:
	rm *.o
#Thus, we see that we have a complete makefile that compiles three C++ files and then generates an executable main from the object files.
