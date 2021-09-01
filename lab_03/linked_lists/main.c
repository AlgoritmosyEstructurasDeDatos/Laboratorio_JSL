#include <stdio.h>

// Definiciones para las listas enlazadas
#include "linked_list.h"

int main(){
    // La lista es un puntero al primer nodo, en términos prácticos.
    p_node list = NULL;
    // Mostramos la lista vacía, solo para confirmar
    show_list(list);
    
    // Insertamos elementos, correspondientes a strings
    list = list_insert(list, "Fulano");
    list = list_insert(list, "Mengano");
    list = list_insert(list, "Sutano");
    list = list_insert(list, "Perengano");
    list = list_insert(list, "Pepito");
    list = list_insert(list, "Juanito");
    list = list_insert(list, "Esculapio");
    list = list_insert(list, "Floripondio");
    
    // Muestra la lista con los valores insertados
    show_list(list);
    
    /*
    // Este bloque es para probar la función para encontrar un elemento previo.
    // Recordar que, para una lista simplemente enlazada, eliminar es de orden O(n)
    p_node p = list_previous_node(list, "Pepito");
    if (p) printf("%s\n", p->key);
    else printf("Nulo\n");
    */
    
    // Remueve el elemento (nodo con el valor) "Pepito"
    list = list_remove(list, "Pepito");
    show_list(list);
        
    // Limpia la lista
    list_clear(list);
    
    return 0;
}
