CC:=g++
flags:=-Wall -Wextra -pedantic -std=c++11
dflags:=-ggdb3
cflags:=-c

default:unscramble

unscramble:main.o
	$(CC) main.o -o main

main.o:main.cc
	$(CC) $(cflags) $(flags) main.cc

clean:
	rm *.o core main

