CC = gcc
CFLAGS = -Wall #-g -O0 

INCLUDEDIR = ../include/

LIB = -lmyTerm
LIBDIR = -L../libs

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
HEADER = $(wildcard ../include/*.h)

TARGET = app

all:$(TARGET)


$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LIBDIR) $(LIB)


%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@ -I$(INCLUDEDIR)


rm:
	rm -rf $(OBJ)