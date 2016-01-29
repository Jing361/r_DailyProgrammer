CC:=g++
flags:=-Wall -Wextra -pedantic -std=c++14
dflags:=-ggdb3
cflags:=-c $(dflags)

name:=LunarAdventure

default:$(name)

AdventureGame.o:AdventureGame.cc
	$(CC) $(cflags) $(flags) AdventureGame.cc

Menu.o:Menu.cc
	$(CC) $(cflags) $(flags) Menu.cc

$(name):main.o AdventureGame.o Menu.o libTarSplit.so
	$(CC) main.o AdventureGame.o Menu.o -ldl -o $(name)

main.o:main.cc
	$(CC) $(cflags) $(flags) main.cc

tarSplit.o:tarSplit.cc
	$(CC) $(cflags) $(flags) -fPIC tarSplit.cc

libTarSplit.so:tarSplit.o
	$(CC) -shared -o libTarSplit.so tarSplit.o

clean:
	rm *.o core $(name) libTarSplit.so

