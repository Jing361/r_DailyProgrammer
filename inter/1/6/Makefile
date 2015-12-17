CC:=g++
flags:=-Wall -Wextra -pedantic -std=c++14
dflags:=-ggdb3
cflags:=-c

default:main

main:main.o dice.o
	$(CC) main.o dice.o -o main

main.o:main.cc
	$(CC) $(cflags) $(flags) main.cc

dice.o:dice.cc
	$(CC) $(cflags) $(flags) dice.cc

clean:
	rm *.o core main

