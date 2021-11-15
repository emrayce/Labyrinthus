CC = g++
SRC = src/main.cc src/map.cc src/player.cc src/game.cc


CFLAGS = -g -Wall -Werror

all:
	$(CC) $(CFLAGS) $(SRC)
