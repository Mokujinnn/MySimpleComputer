CC = gcc
CFLAGS = -Wall
INCLUDEDIR = ../include/

LIB = mySimpleComputer
LIBDIR = ../mySimpleComputer


SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

TARGET = main

all:$(SRC) $(TARGET) $(EXE)

$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ) -L$(LIBDIR) -l$(LIB)
	


%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@ -I$(INCLUDEDIR)


rm:
	rm -rf $(OBJ)