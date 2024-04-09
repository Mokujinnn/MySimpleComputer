CC = gcc
CFLAGS = -Wall
INCLUDEDIR = ../include/

LIB = -lmySimpleComputer -lmyTerm -lmyBigChars
LIBDIR = ../libs/

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
HEADER = $(wildcard ../include/*.h)
LIBDEPENDANCE = $(wildcard ../libs/*.a)

TARGET = pr04

all:$(SRC) $(TARGET)

$(TARGET): $(OBJ) $(LIBDEPENDANCE)
	$(CC) -o $@ $(OBJ) -L$(LIBDIR) $(LIB)  


%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@ -I$(INCLUDEDIR)


rm:
	rm -rf $(OBJ)