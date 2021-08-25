#include <stdio.h>

#include "curve.h"
#include "point.h"

// Función para implementar el polinomio a calcular
float polynomial_function(float);

int main(){
    // Puntero para almacenar los puntos
    curve polynomial = NULL;
    // Tamaño inicial de la curva, al inicializarla con malloc más abajo
    size_t poly_size = 0;
    
    /* Salvo dx, todos estos valores pueden ser pedidos al usuario como 
     * en otro de los ejemplos
     */
    // Valores del rango de puntos a utilizar
    float xmin = -1, xmax = 1;
    // Distancia entre puntos equiespaciados
    float dx;
    // Cantidad de puntos
    int n_points = 10;
    
    // Distancia entre valores de x
    dx = (xmin-xmax)/(n_points-1);
    // Genera todos los puntos necesarios
    for(int i = 0; i < n_points; i++){
        // El eje x del punto
        float x = xmin + i*dx;
        // Crea el punto con el eje x y el valor del polinomio
        point p = create_point(x, polynomial_function(x));
        // Solo para control
        printf("(%.2f, %.2f)\n", p.x, p.y);
        // Inserta en la lista el nuevo punto y la devuelve.
        polynomial = insert_point(polynomial, i, p, &poly_size);
    }
    
    // Imprime los puntos de la curva en una sola línea
    print_curve(polynomial, poly_size);
    
    // Libera la memoria utilizada por la curva
    free(polynomial);
}

// Calcula el valor del polinomio para x dado.
float polynomial_function(float x){
    return x*x + 2*x + 1;
}
