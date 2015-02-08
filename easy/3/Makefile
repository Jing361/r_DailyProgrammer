CC:=g++
flags:=-Wall -std=c++11
dflags:=-ggdb3
cflags:=-c
output:=encrypt

second:=decrypt

default:main

main:main.o
	$(CC) main.o -o $(output)

main.o:main.cc
	$(CC) $(cflags) $(flags) main.cc
	ln -sf $(output) $(second) 

clean:
	rm *.o core $(output) $(second)

