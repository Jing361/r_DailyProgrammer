CC:=gcc
flags:=-Wall
dflags:=-ggdb3
cflags:=-c

default:main

main:main.o
	$(CC) main.o -o main

main.o:main.c
	$(CC) $(cflags) $(flags) main.c

clean:
	rm *.o core main record

