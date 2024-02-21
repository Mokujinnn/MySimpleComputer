CC = gcc
CFLAGS = -Wall
INCLUDEDIR = ../include/

LIB = -lmySimpleComputer-d
LIBDIR = ../mySimpleComputer


SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

TARGET = app

all:$(SRC) $(TARGET) $(EXE)

$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ) -L$(LIBDIR) $(LIB)  
	


%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@ -I$(INCLUDEDIR) -g -O0


rm:
	rm -rf $(OBJ)