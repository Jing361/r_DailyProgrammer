CC:=g++
flags:=-Wall -std=c++11
dflags:=-ggdb3
cflags:=-c $(dflags)

name:=main

default:main

main:main.o calculator.o
	$(CC) calculator.o main.o -o $(name)

calculator.o:calculator.cc
	$(CC) $(cflags) $(flags) calculator.cc

main.o:main.cc
	$(CC) $(cflags) $(flags) main.cc

clean:
	rm *.o core $(name)

