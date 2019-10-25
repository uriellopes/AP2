all: exec

exec: main.cpp
	g++ -Wall -pedantic -g -O0 -o exec main.cpp

run:
	./exec