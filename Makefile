.SILENT:

all: build run
build: compile link
run:
	./main.x
compile:
	g++ -c csrc/main.cpp csrc/motor.cpp
link:
	g++ main.o motor.o -o main.x -lwiringPi
pch:
	g++ csrc/pch.hpp
clean:
	rm -f *.o *.x


