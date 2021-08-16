#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

void add_function();
void subs_function();
void scale_function();
void module_fuction();

int main(){
    int option = 0;
    
    printf("Menú:\
\n\t1) Sumar dos vectores.\
\n\t2) Restar dos vectores.\
\n\t3) Escalar un vector.\
\n\t4) Calcular módulo.\n\nSeleccione opción: ");
    scanf("%d", &option);
    
    switch (option){
        case 1:
            add_function();
            break;
        case 2:
            subs_function();
            break;
        case 3:
            scale_function();
            break;
        case 4:
            module_fuction();
            break;
        default:
            printf("ERROR: opción inválida.\n");
        
    }
    
    return 0;
}

void add_function(){
    vec2d_t u, v, w;
    
    // Entradas de usuario
    get_vector("Ingrese el primer vector: ", &u);
    get_vector("Ingrese el segundo vector: ", &w);
    
    // Suma
    v = add_vector(u, w);
    // A string
    char* str_v = vec2d_to_string(v);
    printf("La suma es %s\n", str_v);
    
    // Libera la memoria del string
    free(str_v);
    
    return;
}

void subs_function(){
    vec2d_t u, v, w;
    
    // Entradas de usuario
    get_vector("Ingrese el primer vector: ", &u);
    get_vector("Ingrese el segundo vector: ", &w);
    
    // Suma
    v = subs_vector(u, w);
    // A string
    char* str_v = vec2d_to_string(v);
    printf("La resta es %s\n", str_v);
    
    // Libera la memoria del string
    free(str_v);
    
    return;
}

void scale_function(){
    vec2d_t u, v;
    double scalar;
    
    // Entradas de usuario
    get_vector("Ingrese el vector: ", &u);
    printf("Ingrese el valor escalar: ");
    scanf("%lf", &scalar);
    
    v = scale_vector(scalar, u);
    // A string
    char* str_v = vec2d_to_string(v);
    printf("El nuevo vector es es %s\n", str_v);
    
    // Libera la memoria del string
    free(str_v);
    
    return;
}

void module_fuction(){
    vec2d_t u;
    double module;
    // Entradas de usuario
    get_vector("Ingrese el vector: ", &u);
    module = vector_module(u);
    
    printf("El módulo del vector es %f\n", module);
    
    return;
}
