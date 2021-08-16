#ifndef POINT_H_
#define POINT_H_

// Estructura para almacenar un vector
typedef struct {
    // Coordenadas cartesianas
    double x;
    double y;
} vec2d_t;

// Suma vectorial
vec2d_t add_vector(vec2d_t, vec2d_t);
// Multiplicación de vector por escalar
vec2d_t scale_vector(double, vec2d_t);
// Resta vectorial
vec2d_t subs_vector(vec2d_t, vec2d_t);
// Módulo del vector
double vector_module(vec2d_t);

// Convierte el vector a string
char* vec2d_to_string(vec2d_t);

/* Obtiene un vector de usuario, mostrando un 
 * mensaje para el usuario
 */
void get_vector(char*, vec2d_t*);

#endif
