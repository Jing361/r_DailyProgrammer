CC:=g++
flags:=-Wall -Wextra -pedantic -std=c++11
dflags:=-ggdb3
cflags:=-c $(dflags)

name:=main

default:main fix

main:main.o authenticator.o
	$(CC) authenticator.o main.o -o $(name)

main.o:main.cc
	$(CC) $(cflags) $(flags) main.cc

authenticator.o:authenticator.cc
	$(CC) $(cflags) $(flags) authenticator.cc

fix:fix.o
	$(CC) fix.o -o fix

fix.o:fix.cc
	$(CC) $(cflags) $(flags) fix.cc

clean:
	rm *.o core $(name) fix

