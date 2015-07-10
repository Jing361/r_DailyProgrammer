CC:=g++
flags:=-Wall -Wextra -pedantic -std=c++11
dflags:=-ggdb3
cflags:=-c $(dflags)
output:=encrypt

second:=decrypt

default:main

cipher.o:cipher.cc
	$(CC) $(cflags) $(flags) cipher.cc

main:main.o cipher.o
	$(CC) cipher.o main.o -o $(output)

main.o:main.cc
	$(CC) $(cflags) $(flags) main.cc
	ln -sf $(output) $(second) 

clean:
	rm *.o core $(output) $(second)

