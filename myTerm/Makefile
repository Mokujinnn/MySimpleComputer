CC = gcc
CFLAGS = -Wall

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
HEADER = ../include/myTerm.h
INCLUDEDIR = ../include/

TARGET = app

all:$(SRC) $(TARGET) $(EXE)


$(TARGET): $(OBJ)
	$(CC) -o $@ $^
	

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@ -I$(INCLUDEDIR)

rm:
	rm -rf $(OBJ)