all: console

console: console/test.c
	make --makefile=console/Makefile
