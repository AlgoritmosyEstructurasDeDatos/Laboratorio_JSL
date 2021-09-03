#include <stdio.h>

// Tamaño máximo del arreglo
#define MAX_LENGTH 100

// Tipo "dummy", un placeholder para cualquier tipo necesario para la lista
typedef int data_type;

// Ya que usamos tanto este tipo, le damos un nombre adecuado
// Este nombre es algo estándar y se ve en bastantes librerías
typedef unsigned int uint_t;

// Añade al final
void list_append(data_type* l, data_type x, uint_t *n){
    // Si la lista está llena, no podemos agregar
    if (*n == MAX_LENGTH) return;
    
    // El nuevo último elemento estará en el último (n-1) más uno (n)
    l[*n] = x;
    // Aumenta la cantidad de elementos en la lista
    (*n)++;
}

// Borra del final
void list_delete_last(data_type *l, uint_t *n){
    // Si no hay nada que borrar, no hace nada
    if(*n == 0) return;
    // El último elemento se deja como "nulo", o lo equivalente.
    l[*n-1] = 0;
    // Disminuye el total de elementos en la lista
    (*n)--;
}

// Inserta en una posición
void list_insert(data_type *l, uint_t *n, data_type x, uint_t pos){
    // Si la lista está llena, no podemos agregar
    if (*n == MAX_LENGTH) return;
    
    // Posición del último elemento
    uint_t i = *n-1;
    // Mueve una posición hacia arriba todos los elementos hasta el
    // que está donde queremos insertar el nuevo
    while (i >= pos){
        // Mueve
        l[i+1] = l[i];
        // Baja al anterior
        i--;
    }
    // "Inserta" el nuevo elemento en la posición pedida
    l[pos] = x;
    // Aumenta el total de elementos en la lista
    (*n)++;
}

// Muestra los elementos de la lista separados por coma
void show_list(data_type *l, uint_t n){
    putchar('[');
    for(int i=0; i < n-1; i++)
        printf("%d, ", l[i]);
    printf("%d]\n", l[n-1]);
}

void list_insert_at_first(data_type *l, uint_t *n, data_type x){
    if (*n == MAX_LENGTH) return;
    
    for(int i=*n-1; i >= 0; i--)
        l[i+1] = l[i];
    
    l[0] = x;
    (*n)++;
}

int main(){
    data_type list[MAX_LENGTH];
    uint_t length = 0;
    
    for(int i = 10; i < 100; i=i+10)
        list_append(list, i, &length);
    show_list(list, length);
    list_delete_last(list, &length);
    show_list(list, length);
    
    list_insert_at_first(list, &length, 0);
    
    list_insert(list, &length, 5, 3);
    show_list(list, length);
}
