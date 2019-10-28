all: exec

exec: main.cpp
	g++ -std=c++11 -Wall -pedantic -g -O0 -o exec main.cpp

run:
	./exec