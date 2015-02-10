CC:=g++
flags:=-Wall -std=c++11
dflags:=-ggdb3
cflags:=-c $(dflags)

name:=LunarAdventure

default:main

AdventureGame.o:AdventureGame.cc
	$(CC) $(cflags) $(flags) AdventureGame.cc

main:main.o AdventureGame.o
	$(CC) AdventureGame.o main.o -o $(name)

main.o:main.cc
	$(CC) $(cflags) $(flags) main.cc

clean:
	rm *.o core $(name)

