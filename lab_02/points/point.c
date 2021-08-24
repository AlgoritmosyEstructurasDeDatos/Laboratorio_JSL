#include "point.h"

// Estas librerías son utilizadas por las funciones de este código, por lo que debemos incluirlas
#include <stdio.h>
#include <math.h>

// Crea un punto a partir de dos valores "reales"
point create_point(float x, float y){
    // Crea el punto
    point p;
    // Asigna los valores en los ejes
    p.x = x;
    p.y = y;
    
    return p;
}

// Entrega el cuadrante en el que está el punto
int get_quadrant(point p){
    /* Los cuadrantes son definidos desde 1 a 4, en el sentido contrario
     * a las manecillas del reloj, partiendo por 1 en x>0 && y>0.
     */
    // Al poner condiciones, deben ir entre paréntesis
    if (p.x> 0 && p.y > 0) {
        /* Cuando el objetivo es retornar un valor, podemos prescindir de
         * `else`, sin embargo, cuando tenemos varias condiciones a evaluar
         * contradictorias entre sí, como en este caso, estas deben ir dentro
         * del `else` de la previa, lo que puede volver engorrosa la escritura.
         */
        return 1;
    }
    if (p.x< 0 && p.y > 0) {
        return 2;
    }
    if (p.x< 0 && p.y < 0) {
        return 3;
    }
    if (p.x> 0 && p.y < 0) {
        return 4;
    }
    
    /* Si no, está en un eje (x = 0 || y = 0), para lo que no tenemos un
     * cuadrante definido.
     */
    return 0;
}

/* Convierte un punto a un string.
 * Para esta función, bastaría con imprimirlo por pantalla, pero haremos
 * algo más interesante: volcaremos el punto con formato (x, y) a un string
 * previamente preparado para ello.
 * 
 * En C, un string es un **arreglo de caracteres**, por lo que tenemos que
 * pasar un puntero a caracter con el espacio adecuado. Es usual considerar
 * este arreglo de caracteres un "buffer", por lo que lo llamamos así.
 * 
 * Podríamos considerar una cierta cantidad de caracteres mínimos para esto,
 * que podríamos calcular a partir de cuántos necesitaremos, pero basta con que
 * el buffer sea "suficientemente grande". Más adelante podríamos ver ejemplos
 * de cómo determinarlo de forma dinámica.
 * 
 * Nótese que esta función hace algo ligeramente diferente a lo declarado
 * en el enunciado como imprimirPunto
 */
void point_to_str(char* buff, point p){
    /* Esta función es exactamente igual a printf, excepto por un detalle:
     * su primer parámetro es un string donde escribir el resultado que, 
     * en printf, iría a la pantalla.
     */
    // Usa 3 dígitos de precisión, porque sí
    sprintf(buff, "(%.3f, %.3f)", p.x, p.y);
    
    /* El valor de "retorno" de esta función es buff, sin embargo, como
     * pedimos la dirección de esta, guardamos los datos directamente en ella
     * y, por lo tanto, no tenemos retorno.
     */
    return;
}

// Desplaza un punto y entrega el resultado
point move_point(point p, float dx, float dy){
    // Una forma diferente de hacer el arreglo es esta
    point new_point = {p.x + dx, p.y + dy};
    return new_point;
}

// Obtiene la distancia entre dos puntos
/* La distancia euclidiana es la hipotenusa del triángulo rectángulo 
 * formado por los puntos
 * 
 * Esta función utiliza la función sqrt del módulo math.h. Este módulo debe 
 * ser incluido como biblioteca con la que enlazar por el compilador. En 
 * cristiano, esto significa que debemos agregar el parámetro -lm al final del
 * comando gcc:
 * $ gcc archivo1.c archivo2.c ... -o salida.exe -lm
 */
float euclidean_distance(point p_1, point p_2){
    float dx, dy, distance;
    dx = p_1.x - p_2.x;
    dy = p_1.y - p_2.y;
    distance = sqrt(dx*dx + dy*dy);
    
    return distance;
}

// Optiene la distancia al origen
float distance_from_origin(point p){
    // Aprovechamos que la distancia al origen es la distancia entre p y (0, 0)
    point zero = {0, 0};
    return euclidean_distance(p, zero);
}
