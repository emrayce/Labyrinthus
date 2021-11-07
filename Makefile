CC = g++
SRC = src/main.cc src/map.cc


CFLAGS = -g -Wall

all:
	$(CC) $(CFLAGS) $(SRC)
