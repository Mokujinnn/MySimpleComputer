CC = gcc
CFLAGS = -Wall -g -O0

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
HEADER = sc_variables.h

TARGET = ../libs/libmySimpleComputer-d.a

all:$(SRC) $(TARGET)


$(TARGET): $(OBJ)
	ar -rcs $@ $^


%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@


rm:
	rm -rf $(OBJ)