.SILENT:

all: build run
build: compile link
run:
	./bin/main.x
compile:
	g++ -c src/main.cpp
link:
	g++ main.o -o bin/main.x -lwiringPi
pch:
	g++ src/pch.hpp
clean:
	rm -rf *.o *.x


