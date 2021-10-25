# Configuración del compilador
CC = gcc
CFLAGS = -Wall -g

# Dependencias principales
DEPS = uintlist.h tdagraph.h graphloader.h uintqueue.h uintstack.h
# Objetos a generar
OBJECTS = uintlist.o tdagraph.o graphloader.o uintqueue.o uintstack.o

# Regla para código objeto (archivos compilados, pero no enlazados en un
# ejecutable, a partir de ellos se generan módulos precompilados y, de paso,
# evitan tener que compilar a cada rato cosas que ya estaban listas)
%o: %.c $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

# REGLAS
all:full_test

# Para la prueba de las listas
list_test:test_list.c uintlist.o
	$(CC) -o $@ $< uintlist.o $(CFLAGS)

# El programa principal para las pruebas, que depende del main.c y los
# objetos generados, al usarlos todos
full_test:main.c $(OBJECTS)
	$(CC) -o $@ $< $(OBJECTS) $(CFLAGS)

# Reglas a ejecutar sin preocuparse de las dependencias
.PHONY:all clean cleanobj

# Estas reglas solo funcionan en Linux
# Regla para borrar todo
cleanall:clean
	rm full_test list_test
# Para borrar archivos de respaldo
clean: cleanobj
	rm -rf *~

# Para borrar los código objeto (*.o) generados
cleanobj:
	rm *.o
