.SILENT:

all: build run
build: compile link
run:
	./bin/main.x
compile:
	g++ -c csrc/main.cpp
link:
	g++ main.o -o bin/main.x -lwiringPi
pch:
	g++ csrc/pch.hpp
clean:
	rm -rf *.o *.x


