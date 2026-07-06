TARGET = meu_sistema
CC = gcc
CFLAGS = -Wall -g

$(TARGET): main.o node.o struct.o util.o vector.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o node.o struct.o util.o vector.o

main.o: main.c node.h struct.h util.h vector.h
	$(CC) $(CFLAGS) -c main.c -o main.o

node.o: node.c node.h struct.h vector.h
	$(CC) $(CFLAGS) -c node.c -o node.o

struct.o: struct.c struct.h
	$(CC) $(CFLAGS) -c struct.c -o struct.o

util.o: util.c util.h struct.h node.h
	$(CC) $(CFLAGS) -c util.c -o util.o

vector.o: vector.c vector.h struct.h node.h util.h
	$(CC) $(CFLAGS) -c vector.c -o vector.o

clean:
	rm -f *.o $(TARGET)