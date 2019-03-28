CC=g++
RM=rm -rf
BINARY=calculator
CFLAGS=-std=c++17

build:
	$(CC) $(CFLAGS) -o calculator main.cpp

clean:
	$(RM) $(BINARY)