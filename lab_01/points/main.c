#include <stdio.h>

#include "point.h"

int main(){
    // Declaramos variables a utilizar
    point p, moved_point;
    char s_point[20];
    
    // Inicializamos las variables
    p = create_point(1, 2);
    // El nombre de un arreglo equivale a un puntero a su dirección
    point_to_str(s_point, p);
    
    // %s es para mostrar strings, %d para enteros, %f para flotantes,
    // %.nf es para mostrar un flotante con n dígitos de precisión (e.g. %.2f)
    printf("El punto es %s\n", s_point);
    printf("El cuadrante en que se encuentra es el %d\n", get_quadrant(p));
    
    moved_point = move_point(p, 0.2, 0.5);
    point_to_str(s_point, moved_point);
    
    printf("El punto desplazado quedó en %s\n", s_point);
    printf("La distancia desde el punto original al desplazado es %f\n",
        euclidean_distance(p, moved_point));
    
    printf("La distancia desde el punto al origen es %f\n",
        distance_from_origin(p));
    
    return 0;
}
