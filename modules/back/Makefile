CC = gcc
CFLAGS = -W -Wall -std=c89 -pedantic -O2 `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` -fsanitized==undifined
LDFLAGS = `pkg-config --libs-only-l MLV`
OBJ = ./index2.o ./modules/ui/ui.o ./src/style/stylesheet.o
TARGET = index2

$(TARGET) : $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(TARGET) 
	rm -rf $(OBJ)

./index.o : index2.c
	$(CC) $(CFLAGS) -c index.c -o index.o

./modules/ui/ui.o : ./modules/ui/ui.c
	$(CC) $(CFLAGS) -c ./modules/ui/ui.c -o ./modules/ui/ui.o

./src/style/stylesheet.o : ./src/style/stylesheet.c
	$(CC) $(CFLAGS) -c ./src/style/stylesheet.c -o ./src/style/stylesheet.o

clean :
	rm -rf $(TARGET) *.o *~