CC:=g++
flags:=-Wall
dflags:=-ggdb3
cflags:=-c

default:unscramble

main:main.o
	$(CC) main.o -o main

main.o:main.cc
	$(CC) $(cflags) $(flags) main.cc

clean:
	rm *.o core main

