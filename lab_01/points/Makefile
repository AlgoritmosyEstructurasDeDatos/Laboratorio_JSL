# Compilador
CC = gcc
# Parámetros opcionales: -Wall muestra todos los warnings al compilar
CFLAGS = -Wall
# Librerías que incluir
LDFLAGS = -lm

# Códigos fuentes de los que depende el programa
sources = point.c
# Headers que utiliza, los mismos de sources, pero con .h, en vez de .c
headers = $(sources:.c=.h)

# Regla para construir el objetivo, escrita como
# objetivo: dependencias
point_test:main.c $(sources)
	$(CC) $(CFLAGS) $< $(sources) -o $@ $(LDFLAGS)
# Variables adicionales usadas aquí:
# $< significa la primera dependencia del archivo, lo primero después de :
# $@ significa el objetivo de la regla, lo que viene antes de :

# Regla por defecto
all:point_test

clean:
	rm $(program)
