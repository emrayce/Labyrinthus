CC = g++
SRC = src/main.cc src/map.cc src/player.cc


CFLAGS = -g -Wall

all:
	$(CC) $(CFLAGS) $(SRC)
