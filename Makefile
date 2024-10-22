CC = gcc
HFLAGS = -W -Wall -std=c89 -pedantic -O2
LFLAG = -L/usr/lib -lMLV
OBJ = index.o
TARGET = index

$(TARGET) : $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LFLAG)
	rm -f $(OBJ)

index.o : index.c
	$(CC) $(HFLAGS) -c index.c -o index.o

clean :
	rm -f $(TARGET)