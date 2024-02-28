CC = gcc
CFLAGS = -Wall

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
# HEADER = sc_variables.h

TARGET = app

all:$(SRC) $(TARGET) $(EXE)


$(TARGET): $(OBJ)
	$(CC) -o $@ $^
	

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

rm:
	rm -rf $(OBJ)