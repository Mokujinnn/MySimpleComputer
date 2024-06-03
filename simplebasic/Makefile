CC = g++
CFLAGS = -Wall -g -O0 

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
HEADER = $(wildcard ../simpleassembler/*.hpp) $(wildcard ./*.hpp)
INCLUDEDIR = ../simpleassembler

TARGET = sbt

all:$(TARGET)


$(TARGET): $(OBJ)
	$(CC) -o $@ $^


%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@ -I$(INCLUDEDIR)


rm:
	rm -rf $(OBJ)