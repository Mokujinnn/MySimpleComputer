CC = gcc
CFLAGS = -Wall

INCLUDEDIR = ../include/

LIB = -lmyTerm
LIBDIR = -L./

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
HEADER = $(wildcard ../include/*.h)

TARGET = app

all:$(SRC) $(TARGET)


$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LIBDIR) $(LIB)


%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@ -I$(INCLUDEDIR)


rm:
	rm -rf $(OBJ)