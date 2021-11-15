CC = g++
SRC_DIR = src/
SRC_FILES := $(wildcard $(SRC_DIR)/*.cc)

CFLAGS = -g -Wall -Werror

all:
	$(CC) $(CFLAGS) $(SRC_FILES)
