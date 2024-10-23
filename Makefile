CC = gcc
HFLAGS = -W -Wall -std=c89 -pedantic -O2
LFLAG = -L/usr/lib -lMLV
OBJ = ./index.o ./modules/ui/ui.o
TARGET = index

$(TARGET) : $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LFLAG)
	rm -rf $(OBJ)

./index.o : index.c
	$(CC) $(HFLAGS) -c index.c -o index.o

./modules/ui/ui.o : ./modules/ui/ui.c
	$(CC) $(HFLAGS) -c ./modules/ui/ui.c -o ./modules/ui/ui.o

clean :
	rm -rf $(TARGET) *.o *~