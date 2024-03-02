CC = gcc
CFLAGS = -Wall
INCLUDEDIR = ../include/

LIB = -lmySimpleComputer -lmyTerm
LIBDIR = ../libs/

LIBDEPENDANCE = ../libs/libmySimpleComputer.a ../libs/libmyTerm.a

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

TARGET = pr03

all:$(SRC) $(TARGET) $(EXE) 

$(TARGET): $(OBJ) $(LIBDEPENDANCE)
	$(CC) -o $@ $(OBJ) -L$(LIBDIR) $(LIB)  
	
$(LIBDEPENDANCE): ../mySimpleComputer/libmySimpleComputer.a ../myTerm/libmyTerm.a
	cp ../mySimpleComputer/libmySimpleComputer.a ../libs/libmySimpleComputer.a
	cp ../myTerm/libmyTerm.a ../libs/libmyTerm.a


%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@ -I$(INCLUDEDIR)


rm:
	rm -rf $(OBJ)