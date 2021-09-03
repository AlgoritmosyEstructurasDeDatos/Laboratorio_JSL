#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

p_node create_node(data_type x){
    // Calcula el tamaño del dato que vamos a guardar
    size_t len = strlen(x);
    
    // Crea el espacio para el nodo (dos punteros) 
    p_node n = (p_node)malloc(sizeof(node));
    // Crea el espacio para el string que tenemos que apuntar con n->key
    n->key = (char*)malloc(len);
    /* La copia de strings se hace mediante la esta función. Su primer parámetro
     * es el destino y el segundo, el original a copiar.
     */
    strcpy(n->key, x);
    // Inicializa el puntero a próximo especificando que sea NULL
    n->next = NULL;
    
    return n;
}

void free_node(p_node n){
    /* Si esto no se hace en este orden, se pierde el acceso al string apuntado
     * por el nodo y, por lo tanto, no se podrá liberar después.
     */
    // Libera la memoria del string guardado
    free(n->key);
    // Libera la memoria del nodo
    free(n);
}

p_node list_insert(p_node list, data_type x){
    /*
     * Este es el algoritmo de inserción:
     * nodo <- crear_nodo(x)
     * si el nodo es nulo, retorna
     * nodo.next <- list.head;
     * list.head = nodo;
     */
    // Crea un nodo para el valor a guardar
    p_node new = create_node(x);
    // Si es nulo, no pudo crearse el nodo y termina el programa
    if (new == NULL){
        printf("No hay memoria...\n");
        exit(EXIT_FAILURE);
    }
    // Apunta el próximo nodo al "ex-primero"
    new->next = list;
    // La lista ahora apunta al nuevo nodo
    list = new;
    
    return list;
}

void show_list(p_node list){
    // Si hay un elemento que mostrar
    if (list != NULL){
        // El primer nodo
        p_node n = list;
        do {
            // Muestra el primer nodo
            printf("%s -> ", n->key);
            // Actualiza el nodo yendo al siguiente
            n = n->next;
            // Repite mientras el nodo no sea nulo (es decir, el final)
        } while (n != NULL);
    }
    /* Esta función escribe el string directamente en la pantalla, insertando
     * salto de línea al final.
     * A diferencia de printf, esta no formatea nada, sino poner el string en bruto.
     */
    // El final
    puts("Null");
}

void list_clear(p_node list){
    // El primer elemento de la lista
    p_node n = list;
    // Mientras no llegue al final
    while (n != NULL){
        // Dirección del próximo nodo
        p_node next = n->next;
        // Libera el nodo
        free_node(n);
        // Actualiza la dirección del próximo nodo a limpiar
        n = next;
    }
    
    return;
}

/* Algoritmo para encontrar el nodo previo
 * 
 * Anterior(lista, nodo)
 * anterior <- lista
 * mientras anterior->next != nulo && anterior->next != nodo
 *  anterior <- anterior->next
 * returna anterior
 */
p_node list_previous_node(p_node list, data_type x){
    // Inicio de la lista
    p_node previous = list;
    
    // Mientras no se llegue al final de la lista y el próximo sea diferente
    // del valor buscado
    /* La comparación de strings en C se realiza caracter a caracter, equivalente
     * a la comparación alfabética de palabras (e.g. "a" está antes que "absoluto"),
     * pero utilizando los valores de los caracteres en las tablas de ídem (como 
     * ASCII extendido). Mediante la función strcmp, del módulo string.h, comparamos
     * strings de forma relativamente indolora, pero hay que entender su resultado:
     * es un entero que, si es >0, el segundo string es mayor al primero; si es <0, el
     * segundo es menor al primero; si es == 0, son iguales. Entonces acá, que queremos
     * saber si son iguales, seguimos la búsqueda mientras sea != 0, es decir, mientras
     * no sea igual.
     */
    while (previous->next != NULL && strcmp(previous->next->key, x) != 0){
        // Avanzamos al próximo nodo
        previous = previous->next;
    }
    
    // Estas líneas son equivalentes al operador ternario "a? b:c"
    // Su objetivo es devolver NULL si no se encontró el valor buscado.
//     if (previous->next == NULL)
//         return NULL
//     return previous;
    // En este operador, a?b:c, si a es verdadero, resulta b; de otro modo, resulta c
    return previous->next == NULL ? NULL:previous;
}

/* Algoritmo de eliminación de nodo
 * 
 * eliminar(lista, valor)
 * previo <- Anterior(lista, valor)
 * nodo <- previo->next
 * previo->next <- nodo->next
 * destruir(nodo)
 * retorna lista
 */
p_node list_remove(p_node list, data_type x){
    /******************************************************************
     * TAREA
     * 
     * Arreglar esta función (y el algoritmo), para que no falle
     * si no se encuentra el valor a eliminar.
     ******************************************************************/
    // Declara puntero al nodo a remover
    p_node n;
    // El nodo previo al que remover
    p_node p = list_previous_node(list, x);
    // El nodo a remover
    n = p->next;
    // El próximo nodo ahora será el que viene a continuación del removido
    p->next = n->next;
    // Borra el nodo de interés
    free_node(n);
    return list;
}
