CC:=g++
flags:=-Wall -std=c++11
dflags:=-ggdb3
cflags:=-c $(dflags)

name:=main

default:main

gen.o:gen.cc
	$(CC) $(cflags) $(flags) gen.cc

main:main.o gen.o
	$(CC) gen.o main.o -o $(name)

main.o:main.cc
	$(CC) $(cflags) $(flags) main.cc

clean:
	rm *.o core $(name)

