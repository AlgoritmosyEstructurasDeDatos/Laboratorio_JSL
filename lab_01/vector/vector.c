#include "vector.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Suma vectorial
vec2d_t add_vector(vec2d_t v, vec2d_t w){
    // Nuevo vector donde almacenar el resultado
    vec2d_t u;
    
    u.x = v.x + w.x;
    u.y = v.y + w.y;
    
    return u;
}

// Multiplicación de vector por escalar
vec2d_t scale_vector(double a, vec2d_t v){
    // Nuevo vector donde almacenar el resultado
    vec2d_t u;
    
    u.x = a*v.x;
    u.y = a*v.y;
    
    return u;
}

// Resta vectorial v-w
vec2d_t subs_vector(vec2d_t v, vec2d_t w){
    return add_vector(v, scale_vector(-1, w));
}

// Módulo del vector
double vector_module(vec2d_t v){
    // Retorna la raíz de la suma de los cuadrados
    return sqrt((v.x*v.x) + (v.y*v.y));
}

// Convierte el vector a string
char* vec2d_to_string(vec2d_t v){
    // Buffer para guardar el string
    char *buff = malloc(50*sizeof(char));
    // Imprime al string
    sprintf(buff, "(%f, %f)", v.x, v.y);
    
    return buff;
}

/* Obtiene el vector como entrada de usuario.
 * Presenta, además, el mensaje como prompt de usuario.
 */
void get_vector(char* msg, vec2d_t* v){
    printf("%s", msg);
    scanf("%lf, %lf", &v->x, &v->y);
}
