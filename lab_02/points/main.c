#include <stdio.h>

#include "curve.h"
#include "point.h"

float polynomial_function(float);

int main(){
    curve polynomial = NULL;
    // Tamaño inicial de la curva, al inicializarla con malloc más abajo
    size_t poly_size = 0;
    
    float xmin = -1, xmax = 1, dx;
    int n_points = 10;
    
    // Distancia entre valores de x
    dx = (xmin-xmax)/(n_points-1);
    for(int i = 0; i < n_points; i++){
        float x = xmin + i*dx;
        point p = create_point(x, polynomial_function(x));
        printf("(%.2f, %.2f)\n", p.x, p.y);
        polynomial = insert_point(polynomial, i, p, &poly_size);
    }
    
    print_curve(polynomial, poly_size);
    
    free(polynomial);
}

float polynomial_function(float x){
    return x*x + 2*x + 1;
}
