CC = gcc
CFLAGS = -Wall
INCLUDEDIR = ../include/

LIB = -lmySimpleComputer
LIBDIR = ../mySimpleComputer

LIBDEPENDANCE = ../mySimpleComputer/libmySimpleComputer.a

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

TARGET = pr01

all:$(SRC) $(TARGET) $(EXE) 

$(TARGET): $(OBJ) $(LIBDEPENDANCE)
	$(CC) -o $@ $(OBJ) -L$(LIBDIR) $(LIB)  
	


%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@ -I$(INCLUDEDIR)


rm:
	rm -rf $(OBJ)