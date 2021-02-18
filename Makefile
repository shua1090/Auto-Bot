.SILENT:

FILES = csrc/main.cpp
LINKS = -lwiringPi -lpthread

all: build run
build: compile link
run:
	./main.x
compile:
	g++ -c $(FILES)
link:
	g++ main.o -o main.x $(LINKS)
pch:
	g++ csrc/pch.hpp
clean:
	rm -f *.o *.x