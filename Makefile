CC = gcc
CFLAGS = -W -Wall -std=c89 -pedantic -O2 `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV`
LDFLAGS = `pkg-config --libs-only-l MLV` -lX11
OBJ = ./index.o ./modules/ui/ui.o ./modules/util/util.o ./src/style/stylesheet.o ./modules/back/game.o
TARGET = index

$(TARGET) : $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(TARGET) 
	rm -rf $(OBJ)

./index.o : index.c
	$(CC) $(CFLAGS) -c index.c -o index.o

./modules/ui/ui.o : ./modules/ui/ui.c
	$(CC) $(CFLAGS) -c ./modules/ui/ui.c -o ./modules/ui/ui.o

./modules/util/util.o : ./modules/util/util.c
	$(CC) $(CFLAGS) -c ./modules/util/util.c -o ./modules/util/util.o
	
./modules/back/game.o : ./modules/back/game.c
	$(CC) $(CFLAGS) -c ./modules/back/game.c -o ./modules/back/game.o


./src/style/stylesheet.o : ./src/style/stylesheet.c
	$(CC) $(CFLAGS) -c ./src/style/stylesheet.c -o ./src/style/stylesheet.o

clean :
	rm -rf $(TARGET) $(OBJ)