# ##

CC = gcc
CFLAGS = -Wall

INCLUDEDIR = ../include/
OBJDIR = ../obj/

# ##
SRC = sc_variables.c
OBJ = $(SRC:.c=.o)

EXE = app

all:$(SRC) $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE)
	
%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@ -I'$(INCLUDEDIR)'

