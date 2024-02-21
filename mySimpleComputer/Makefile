# ##

CC = gcc
CFLAGS = -Wall

# INCLUDEDIR = ../include/
# OBJDIR = ../obj/

# ##
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

TARGET = libmySimpleComputer.a

all:$(SRC) $(TARGET)

$(TARGET): $(OBJ)
	ar -rcs $@ $(OBJ) 
	
%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@


rm:
	rm -rf $(OBJ)