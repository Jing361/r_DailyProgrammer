CC:=g++
flags:=-Wall -Wextra -pedantic -std=c++14
dflags:=-ggdb3
cflags:=-c

default:main

main:main.o board.o
	$(CC) main.o board.o -o main

main.o:main.cc
	$(CC) $(cflags) $(flags) main.cc

board.o:
	$(CC) $(cflags) $(flags) board.cc

clean:
	rm *.o core main

