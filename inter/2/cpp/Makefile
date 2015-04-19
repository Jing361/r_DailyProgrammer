CC:=g++
flags:=-Wall -Wextra -pedantic -std=c++11
dflags:=-ggdb3
cflags:=-c $(dflags)

name:=LunarAdventure

default:$(name)

AdventureGame.o:AdventureGame.cc
	$(CC) $(cflags) $(flags) AdventureGame.cc

Menu.o:Menu.cc
	$(CC) $(cflags) $(flags) Menu.cc

$(name):main.o AdventureGame.o Menu.o
	$(CC) main.o AdventureGame.o Menu.o -o $(name)

main.o:main.cc
	$(CC) $(cflags) $(flags) main.cc

clean:
	rm *.o core $(name)

