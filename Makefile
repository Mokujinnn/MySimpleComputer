CC = gcc

includeDir = ../include/

all: console

console: console/test.c
	$(MAKE) -C console
