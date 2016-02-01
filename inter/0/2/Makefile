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

$(name):main.o AdventureGame.o Menu.o libTarSplit.a moon.tar
	$(CC) main.o AdventureGame.o Menu.o libTarSplit.a -ldl -o $(name)

main.o:main.cc
	$(CC) $(cflags) $(flags) main.cc

moon/moon.o:moon/moon.cc
	$(CC) $(cflags) $(flags) -fPIC -o moon/moon.o moon/moon.cc

moon/libMoon.so:moon/moon.o
	$(CC) -shared -o moon/libMoon.so moon/moon.o

tarSplit.o:tarSplit.cc
	$(CC) $(cflags) $(flags) tarSplit.cc

libTarSplit.a:tarSplit.o
	ar -cvq libTarSplit.a tarSplit.o

moon.tar:moon/moon.adv moon/libMoon.so
	cd moon && tar -cf moon.tar libMoon.so moon.adv && mv moon.tar ..

clean:
	rm *.a *.so *.o core $(name) moon.tar moon.adv moon/*.a moon/*.so moon/*.o

tidy:
	rm moon.adv libMoon.so
