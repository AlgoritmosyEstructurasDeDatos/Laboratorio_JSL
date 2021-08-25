#include <stdio.h>
#include <stdlib.h>

#include "point.h"

float polinomy(float);

/* Este programa es equivalente al main.c de esta carpeta, salvo porque
 * definimos un arreglo de puntos, en lugar de la otra forma rebuscada.
 */
int main(){
    // Esta versión guarda el cuadrado de cada valor de i
    // Arreglo de point
    point c[10];
    
    for(int i = 0; i < 10; i++){
        // Buffer para mostrar el punto
        char buff[20];
        // Crea el punto
        c[i] = create_point(i, i*i);
        // Muestra el punto por pantalla, tras pasarlo a string
        point_to_str(buff, c[i]);
        printf("%s\n", buff);
    }
    
    return 0;

    /*
    // Puntero a point, para generar los valores de la curva dinámicamente
    point* c;
    // Arreglo para las posiciones en x
    float x[10];
    // Pedimos la memoria para el arreglo
    c = (point*)malloc(sizeof(point)*10);
    
    for(int i = 0; i < 10; i++){
        // Buffer para mostrar el punto (ver point.c)
        char s_point[20];
        // Cálculo de las posiciones de los puntos
        x[i] = -1.0 + ((float)i)/5.0;
        // Crea un punto en la posición del arreglo requerida
        c[i] = create_point(x[i], polinomy(x[i]));
        // Convierte el punto a string
        point_to_str(s_point, c[i]);
        // Muestra el punto
        printf("%s\n", s_point);
    }
    
    // Liberamos la memoria
    free(c);
    
    return 0;
    */
}

float polinomy(float x){
    return x*x + 2*x + 1;
}
