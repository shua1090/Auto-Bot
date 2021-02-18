.SILENT:

FILES = csrc/main.cpp # csrc/motor.cpp
LINKS = -lwiringPi -lpthread

all: build run
build: compile link
run:
	./main.x
compile:
	g++ -c $(FILES)
link:
	g++ $(wildcard *.o) -o main.x $(LINKS)
pch:
	g++ csrc/pch.hpp
clean:
	rm -f *.o *.x

.PHONY: test
test:
	g++ -c -fPIC test/foo.cpp -o foo.o
	g++ -shared foo.o -o test/libfoo.so 