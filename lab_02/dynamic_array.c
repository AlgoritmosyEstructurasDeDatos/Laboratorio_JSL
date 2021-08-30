#include <stdio.h>
#include <stdlib.h>

/* Este programa genera un arreglo de puntos equiespaciados entre dos
 * límites dados por el usuario, con la cantidad de puntos requeridos,
 * incluyendo ambos límites
 */
int main(){
    // Puntero a flotante inicializado apuntando a ninguna parte
    float *x = NULL;
    // Valores mínimos y máximos para la lista de puntos a generar
    float xmin = 0, xmax = 0;
    /* Cantidad de puntos. Este dato podría ser un entero, pero el uso
     * de size_t lo hace más explícito un "tamaño". Hay que notar, sin
     * embargo, que este tipo está más bien pensado para tamaños en bytes,
     * no en "posiciones", por lo que estoy forzando un poco el tipo.
     */
    size_t size = 0;
    
    // Pide la entrada al usuario: dos flotantes y un entero sin signo
    printf("Ingrese los valores de inicio, término y cantidad de \
puntos:\n");
    scanf("%f %f %u", &xmin, &xmax, &size);
    
    // Pide el espacio para el arreglo
    x = (float*)malloc(size*sizeof(float));
    
    /* Acá no están corregidos los errores, pero hay que recordar que, si
     * malloc falla, x seguirá siendo un putero a NULL y esto generaría
     * errores, si no lo verificamos.
     */
    
    // Distancia entre puntos
    float dx = (xmax-xmin)/(size-1);
    for(int i = 0; i < size; i++)
        // Valor de cada punto
        x[i] = xmin + i*dx;
    
    // Para mostrar los puntos
    for(int i=0; i < size - 1; i++)
        printf("%f, ", x[i]);

    printf("%f\n", x[size-1]);
    
    // Libera la memoria del arreglo generado
    free(x);
    
    return 0;
}
