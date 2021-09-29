CC = gcc
CFLAGS = -Wall -g

DEPS = uintlist.h tdagraph.h graphloader.h
OBJECTS = uintlist.o tdagraph.o graphloader.o

# Regla para código objeto
%o: %.c $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)


# REGLAS
all:full_test

# Para la prueba de las listas
list_test:test_list.c uintlist.o
	$(CC) -o $@ $< uintlist.o $(CFLAGS)
	
full_test:main.c $(OBJECTS)
	$(CC) -o $@ $< $(OBJECTS) $(CFLAGS)

.PHONY:all clean cleanobj

clean: cleanobj
	rm -rf *~

cleanobj:
	rm *.o
