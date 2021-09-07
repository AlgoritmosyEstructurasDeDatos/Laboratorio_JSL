#include <stdio.h>
// Usa la estructura definida en la clase previa.
// Para esto uno define bibliotecas.
#include "../lab_03/linked_lists/linked_list.h"

// Ejercicio 4 de la guía de TDA
// Une dos listas por el final
// En esta versión, hacemos que la primera lista apunte a la segunda
// Alternativamente, podríamos *copiar* las dos listas en una nueva
p_node join_lists(p_node first, p_node second){
    // Buscamos el último nodo de la primera lista
    p_node last = first;
    while (last->next != NULL)
        last = last->next;
    
    // Hacemos que el último apunte al inicio de la segunda lista
    last->next = second;
    
    // Devolvemos la referencia al inicio de la lista
    return first;
}

int main(){
    // Muy importante inicializar los punteros a nulo
    p_node list_a = NULL, list_b = NULL;
    
    // Listas con valores de ejemplo
    list_a = list_insert(list_a, "a");
    list_a = list_insert(list_a, "b");
    list_a = list_insert(list_a, "c");
    
    list_b = list_insert(list_b, "1");
    list_b = list_insert(list_b, "2");
    list_b = list_insert(list_b, "3");
    
    show_list(list_a);
    show_list(list_b);
    
    // Une las listas
    p_node full = join_lists(list_a, list_b);
    show_list(full);
    // Limpia solo una vez la lista completa. No es necesario borrar el resto,
    // pues ha sido borrado acá.
    list_clear(full);
    
//     list_clear(list_a);
//     list_clear(list_b);
//     
    return 0;
}
