CC:=g++
flags:=-Wall -std=c++11
dflags:=-ggdb3
cflags:=-c $(dflags)

name:=AlphaCipher

default:main

cipher.o:cipher.cc
	$(CC) $(cflags) $(flags) cipher.cc

main:main.o cipher.o
	$(CC) cipher.o main.o -o $(name)

main.o:main.cc
	$(CC) $(cflags) $(flags) main.cc

clean:
	rm *.o core $(name)

