CC = gcc
CFLAGS = -Wall

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
HEADER = sc_variables.h

TARGET = libmySimpleComputer.a

all:$(SRC) $(TARGET)


$(TARGET): $(OBJ)
	ar -rcs $@ $^


%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@


rm:
	rm -rf $(OBJ)