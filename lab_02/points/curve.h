#ifndef __CURVE_H__
#define __CURVE_H__

#include "point.h"

#include <stdlib.h>

// Tipo para un arreglo de puntos ordenados por el eje x
/* Una forma alternativa de definir este nuevo tipo sería como una
 * estructura, de modo que uno de sus elementos sea el tamaño actual
 * del arreglo y el otro, el arreglo en sí.
 * Ejercicio propuesto: implementar esta biblioteca utilizando
 * dicha estructura, en lugar de esta
 */
typedef point* curve;

/*************************************
 * Operaciones sobre curvas
 *************************************/
// Inserta un punto de modo que queden ordenados
curve insert_point(curve, int, point, size_t*);
// Remueve un punto del arreglo
curve remove_point(curve, int, size_t*);

// Para mostrar el arreglo
void print_curve(curve, size_t);

// Operación faltante: buscar

#endif
