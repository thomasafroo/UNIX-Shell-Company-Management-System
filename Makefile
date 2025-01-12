CC = gcc
CFLAGS = -Wall -Wextra -g
OBJS = main.o company.o employee.o position.o

all: program

program: $(OBJS)
	$(CC) $(CFLAGS) -o program $(OBJS)

main.o: main.c company.h employee.h position.h
	$(CC) $(CFLAGS) -c main.c

company.o: company.c company.h
	$(CC) $(CFLAGS) -c company.c

employee.o: employee.c employee.h position.h
	$(CC) $(CFLAGS) -c employee.c

position.o: position.c position.h
	$(CC) $(CFLAGS) -c position.c

clean:
ifeq ($(OS),Windows_NT)
	del *.o program *.gcda *.gcno *.info 2>nul || exit 0
else
	rm -f *.o program *.gcda *.gcno *.info
endif