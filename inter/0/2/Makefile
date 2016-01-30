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

$(name):main.o AdventureGame.o Menu.o libTarSplit.a libMoon.so
	$(CC) main.o AdventureGame.o Menu.o libTarSplit.a -ldl -o $(name)

main.o:main.cc
	$(CC) $(cflags) $(flags) main.cc

moon.o:moon.cc
	$(CC) $(cflags) $(flags) -fPIC moon.cc

libMoon.so:moon.o
	$(CC) -shared -o libMoon.so moon.o

tarSplit.o:tarSplit.cc
	$(CC) $(cflags) $(flags) tarSplit.cc

libTarSplit.a:tarSplit.o
	ar -cvq libTarSplit.a tarSplit.o

clean:
	rm *.a *.so *.o core $(name)

