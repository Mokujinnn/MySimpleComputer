ASD = gcc
CFLAGS = -Wall

INCLUDEDIR = ../include/
OBJDIR = ../obj/

all: console

console: console/test.c
	$(MAKE) -C console
