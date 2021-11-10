CC = g++
SRC = src/main.cc src/map.cc src/player.cc src/game.cc


CFLAGS = -g -Wall

all:
	$(CC) $(CFLAGS) $(SRC)
