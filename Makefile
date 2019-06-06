SHELL = /bin/bash
CC=gcc
CFLAGS= -c

mobbac: main.o interface.o functions.o
		$(CC) -o mobbac main.o interface.o functions.o

main.o: main.c interface.o functions.o
		$(CC) $(CFLAGS) main.c

interface.o: interface.c interface.h
		$(CC) $(CFLAGS) interface.c

functions.o: functions.c functions.h
		$(CC) $(CFLAGS) functions.c
run:
		./mobbac

clean:
		rm -f main.o interface.o functions.o mobbac
