CC = gcc
CFLAGS = -Wall -g -O0

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
HEADER = ../include/myTerm.h
INCLUDEDIR = ../include/

TARGET = ../libs/libmyTerm-d.a

all:$(SRC) $(TARGET)


$(TARGET): $(OBJ)
	ar -rcs $@ $^
	

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@ -I$(INCLUDEDIR)

rm:
	rm -rf $(OBJ)