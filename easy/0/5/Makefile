CC:=g++
flags:=-Wall -Wextra -pedantic -std=c++14
dflags:=-ggdb3
cflags:=-c

name:=main

default:main fix manager crack

main:main.o authenticator.o hide_std_in.o
	$(CC) hide_std_in.o authenticator.o main.o -o $(name)

main.o:main.cc
	$(CC) $(cflags) $(flags) main.cc

authenticator.o:authenticator.cc
	$(CC) $(cflags) $(flags) authenticator.cc

manager:manager.o authenticator.o hide_std_in.o
	$(CC) hide_std_in.o authenticator.o manager.o -o manager

manager.o:manager.cc
	$(CC) $(cflags) $(flags) manager.cc

fix:fix.o
	$(CC) fix.o -o fix

fix.o:fix.cc
	$(CC) $(cflags) $(flags) fix.cc

hide_std_in.o:hide_std_in.cc
	$(CC) $(cflags) $(flags) hide_std_in.cc

crack:crack.o
	$(CC) crack.o -o crack

crack.o:crack.cc
	$(CC) $(cflags) $(flags) crack.cc

clean:
	rm *.o core $(name) fix manager crack

