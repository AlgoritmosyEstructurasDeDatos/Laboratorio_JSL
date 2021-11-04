CC=gcc
CFLAGS=-g -Wall

SOURCES=char_graph.c

default:all

all:gtest

gtest:main.c $(SOURCES)
	$(CC) -o $@ $< $(SOURCES)

.PHONY:clean
clean:
	rm *~ *.o
