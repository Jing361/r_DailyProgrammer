CC:=g++
flags:=-Wall -std=c++11
dflags:=-ggdb3
cflags:=-c $(dflags)

default:main

main:main.o
	$(CC) main.o -o main

main.o:main.cc
	$(CC) $(cflags) $(flags) main.cc

clean:
	rm *.o core main

