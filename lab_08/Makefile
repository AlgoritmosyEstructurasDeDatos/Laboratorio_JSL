CC = gcc
CFLAGS = -Wall -g

DEPS = uintlist.h tdagraph.h

# Regla para código objeto
%o: %.c $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

# Para la prueba de las listas
test:test_list.c uintlist.o
	$(CC) -o $@ $< uintlist.o $(CFLAGS)

.PHONY:all clean

all:test clean cleanobj

clean: cleanobj
	rm -rf *~

cleanobj:
	rm *.o
