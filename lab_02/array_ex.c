#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

// Función para mostrar el arreglo en una sola línea
void show_array(int*, size_t);

int main(){
    // Arreglo inicializado solo en los primeros cinco valores
    int array[LENGTH] = {2, 3, 4, 5, 6};
    
    // Pide los otros valores como entrada de usuario
    printf("Ingrese 5 valores:\n");
    /* Acá usamos el nombre del arreglo como puntero, desplazándolo para
     * entregar las direcciones de las posiciones que nos faltaron
     */
    scanf("%d %d %d %d %d", array+5, array+6, array+7, array+8, array+9);
    
    // Muestra el arreglo cargado completo
    show_array(array, LENGTH);
    
    return 0;
}

void show_array(int* array, size_t size){
    for(int i=0; i < size - 1; i++)
        // Muestra todos los elementos separados por coma, salvo el último
        printf("%d, ", array[i]);

    // Coloca el elemento final sin coma a continuación.
    printf("%d\n", array[size-1]);
    return;
}
