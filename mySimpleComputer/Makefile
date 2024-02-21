# ##

CC = gcc
CFLAGS = -Wall

# INCLUDEDIR = ../include/
# OBJDIR = obj/

# ##
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
HEADER = sc_variables.h

TARGET = libmySimpleComputer.a
# EXE = app

all:$(SRC) $(TARGET) $(EXE)

# $(EXE): $(OBJ)
# 	$(CC) $(CFLAGS) -o $@ $(OBJ)

$(TARGET): $(OBJ)
	ar -rcs $@ $(OBJ) 
	


%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@


rm:
	rm -rf $(OBJ)