CFLAGS = -c -g
CC = gcc

visitors_system: main.o functions.o menu.o visitor.o file_handler.o admin.o
	$(CC) -o visitors_system main.o functions.o menu.o visitor.o file_handler.o admin.o

main.o: main.c main.h defs.h
	$(CC) $(CFLAGS) main.c

functions.o: functions.c functions.h
	$(CC) $(CFLAGS) functions.c

menu.o: menu.c menu.h
	$(CC) $(CFLAGS) menu.c

admin.o: admin.c admin.h
	$(CC) $(CFLAGS) admin.c

visitor.o: visitor.c visitor.h
	$(CC) $(CFLAGS) visitor.c

file_handler.o: file_handler.c file_handler.h
	$(CC) $(CFLAGS) file_handler.c

clean:
	@echo "Cleaning"
	rm -rvf *.o ./visitors_system