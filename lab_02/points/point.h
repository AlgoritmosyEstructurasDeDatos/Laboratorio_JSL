#ifndef _POINT_H__
#define _POINT_H__

/* Estructura para representar un punto en el 
 * plano cartesiano
 */
typedef struct {
    float x;
    float y;
} point;

/*****************************************
 * Funciones informativas y de creación
 *****************************************
 */
// Crea un punto a partir de dos valores "reales"
point create_point(float, float);
// Entrega el cuadrante en el que está el punto
int get_quadrant(point);

// Convierte un punto a string
void point_to_str(char*, point);

/*****************************************
 * Funciones de operaciones
 *****************************************
 */
// Desplaza un punto y entrega el resultado
point move_point(point, float, float);
// Obtiene la distancia (euclidiana, la clásica) entre dos puntos
float euclidean_distance(point, point);
// Optiene la distancia al origen
float distance_from_origin(point);

#endif
