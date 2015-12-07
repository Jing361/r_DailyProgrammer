CC:=g++
flags:=-Wall -Wextra -pedantic -std=c++11
dflags:=-ggdb3
cflags:=-c

default:main scrape

scrape:scrape.o
	$(CC) scrape.o -o scrape

main:main.o
	$(CC) main.o -o main

scrape.o:scrape.cc
	$(CC) $(cflags) $(flags) scrape.cc

main.o:main.cc
	$(CC) $(cflags) $(flags) main.cc

clean:
	rm *.o core main scrape out.txt

