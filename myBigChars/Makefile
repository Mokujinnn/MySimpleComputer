CC = gcc
CFLAGS = -Wall -g -O0 

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
HEADER = $(wildcard ../include/*.h)
INCLUDEDIR = ../include/

TARGET = ../libs/libmyBigChars-d.a

all:$(TARGET)


$(TARGET): $(OBJ)
	ar -rcs $@ $^


%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@ -I$(INCLUDEDIR)


rm:
	rm -rf $(OBJ)