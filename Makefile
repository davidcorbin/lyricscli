SHELL = /bin/sh
CC = gcc
TARGET = lyrics
OBJECTS = lyrics.c lyrics.h
CFLAGS = -Wall -Wextra -g -lcurl -std=c99

$(TARGET) : $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(CFLAGS)