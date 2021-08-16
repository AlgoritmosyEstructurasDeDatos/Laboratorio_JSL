# Compilador
# Parámetros normales
CC = gcc
CFLAGS = -Wall
LDFLAGS = -lm

objects = vector.o
program = vector_test

# Objeto
%.o:%.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<

program:main.c $(objects)
	$(CC) $(CFLAGS) -o $@ $< $(objects) $(LDFLAGS)

all:$(program)

clean:
	rm $(objects)
