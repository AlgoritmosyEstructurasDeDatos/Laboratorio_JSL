#include "curve.h"

#include <stdio.h>

// Como stdlib.h ha sido incluido en curve.h, no hace falta incluirlo acá

// Inserta un punto de modo que queden ordenados
curve insert_point(curve c, int pos, point p, size_t* size){
    // Hacemos el espacio para el nuevo punto
    c = (curve)realloc(c, (*size+1)*sizeof(point));
    
    // Si no tenemos espacio, reportamos el error y salimos
    if (c == NULL){
        printf("Error: memoria insuficiente");
        // Definidas en stdlib.h
        exit(EXIT_FAILURE);
    }
    
    // Si tenemos el espacio, desplazamos hacia atrás cada elemento 
    // hasta la posición del el nuevo
    // Índice del arreglo
    int i = *size-1;
    // mientras queden elementos y no lo hayamos encontrado
    while (i >= pos){
        // Esto es análogo a lo que se realiza para listas estáticas
        c[i+1] = c[i];
        // Disminuimos el contador de posición
        i--;
    }
    // Copiamos el punto en la nueva posición
    c[pos] = p;
    // Llegados acá, aumentamos el tamaño del arreglo, para llevar el registro
    (*size)++;
    
    // Retorna el puntero a la curva actualizada
    return c;
}

// Remueve un punto del arreglo
curve remove_point(curve c, int pos, size_t* size){
    // Esta función es la contraria de la previa: movemos las posiciones
    // en orden inverso y luego, liberamos el espacio final.
    int i = pos;
    while (i < *size-1){
        // Movemos hacia la posición actual la siguiente
        c[i] = c[i+1];
        i++;
    }
    
    // Reducimos el tamaño del arreglo
    /* Merece mencionarse el hecho de que, si liberamos responsablemente la
     * memoria de c al terminar de usarlo (o al cierre del programa, lo que
     * ocurra primero), no es necesario quitarle el espacio.
     */
    c = (curve)realloc(c, (*size-1)*sizeof(point));
    // Disminuye el tamaño de la curva
    (*size)--;
    
    // Retorna el puntero a la curva actualizada
    return c;
}

// Para mostrar el arreglo
void print_curve(curve c, size_t size){
    // Abre la visualización del arreglo
    putchar('[');
    // Muestra los elementos separados por coma, de 5 en 5
    for(int i = 0; i < size; i++){
        char buff[20];
        point_to_str(buff, c[i]);
        printf("%s ", buff);
    }
    // Coloca el string en la salida
    puts("]\n");
}
