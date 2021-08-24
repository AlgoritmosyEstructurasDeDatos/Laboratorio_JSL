#include <stdio.h>
#include <stdlib.h>

int main(){
    float *x = NULL;
    float xmin = 0, xmax = 0;
    size_t size = 0;
    
    printf("Ingrese los valores de inicio, término y cantidad de \
puntos:\n");
    scanf("%f %f %u", &xmin, &xmax, &size);
    
    x = (float*)malloc(size*sizeof(float));
    
    float dx = (xmax-xmin)/(size-1);
    for(int i = 0; i < size; i++)
        x[i] = xmin + i*dx;
//         printf("%f\n", xmin+i*dx);
    
    for(int i=0; i < size - 1; i++)
        printf("%f, ", x[i]);

    printf("%f\n", x[size-1]);
    
    free(x);
    
    return 0;
}

