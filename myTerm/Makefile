CC = gcc
CFLAGS = -Wall

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
HEADER = ../include/myTerm.h
INCLUDEDIR = ../include/

TARGET = libmyTerm.a

all:$(SRC) $(TARGET) $(EXE)


$(TARGET): $(OBJ)
	ar -rcs $@ $^
	

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@ -I$(INCLUDEDIR)

rm:
	rm -rf $(OBJ)