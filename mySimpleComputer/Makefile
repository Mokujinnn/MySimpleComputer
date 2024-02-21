# ##

CC = gcc
CFLAGS = -Wall

# INCLUDEDIR = ../include/
# OBJDIR = obj/

# ##
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

TARGET = libmySimpleComputer.a
# EXE = app

all:$(SRC) $(TARGET) $(EXE)

# $(EXE): $(OBJ)
# 	$(CC) $(CFLAGS) -o $@ $(OBJ)

$(TARGET): $(OBJ)
	ar -rcs $@ $(OBJ) 
	


%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@


rm:
	rm -rf $(OBJ)