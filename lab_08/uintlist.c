#include "uintlist.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Interfaz para los nodos
node* new_node(uint_t value){
    node* n = (node*)malloc(sizeof(node));
    
    if(!n) return NULL;
    
    n->value = value;
    n->previous = NULL;
    n->next = NULL;
    
    return n;
}


void free_node(node* n){
    // Un simple wrapper para el free
    free(n);
}


// Operaciones de lista
list* create_list(){
    list* l = (list*)malloc(sizeof(list));
    
    if(!l) return NULL;
    
    l->len = 0;
    l->head = NULL;
    l->tail = NULL;
    
    return l;
}


void insert_first(list* l, uint_t value){
    node* n = new_node(value);
    
    // La cabeza antigua ahora es el segundo elemento
    n->next = l->head;
    l->head = n;
    // Cuando es el primer elemento insertado, debemos insertar, también, la cola
    if(!l->tail) l->tail = n;
    // Aumenta el total de elementos
    l->len++;
}


void insert_last(list* l, uint_t value){
    node* n = new_node(value);
    
    // Cuando es el primer elemento insertado, también insertamos la cabeza
    if(!l->head) l->head = n;
    
    // Si hay elementos
    if(l->tail){
        // El penúltimo elemento
        n->previous = l->tail;
        // El penúltimo elemento ahora apunta a la cola
        l->tail->next = n;
        // La cola es el nuevo elemento
    }
    l->tail = n;
    // Aumenta el total de elementos
    l->len++;
}


void delete_node(list* l, uint_t value){
    // Si la lista está en blanco, no hay nada que borrar
    if (l->len == 0) return;
    node *n = l->head;
    
    // Mientras n no sea nulo y el valor no sea el que vamos a eliminar
    while(n && n->value != value)
        n = n->next;
    
    // Nada que borrar
    if(!n) return;
    
    // Si hay un previo, hay que ponerle el próximo de este como su propio
    // próximo
    if (n->previous)
        n->previous->next = n->next;
    // Si hay un próximo, hay que ponerle el previo de este como su propio
    // previo
    if (n->next)
        n->next->previous = n->previous;
    
    // Liberamos el nodo
    free_node(n);
    
    // bajamos el tamaño de la lista
    l->len--;
    
    // Fin
    return;
}


void empty_list(list*l){
    while(l->tail){
        // Guarda la cola
        node *n = l->tail;
        // Mueve la cola al penúltimo
        l->tail = n->previous;
        // Borra el nodo
        free_node(n);
        l->len--;
    }
    
    l->head = NULL;
}


void delete_list(list* l){
    empty_list(l);
    // Borrados todos los elementos, libera la lista
    free(l);
}


char* list_to_string(list* l){
    node *n = l->head;
    if(!n){
        return "";
    }
    
    const size_t BUFLEN = 64;
    size_t buf_size = BUFLEN;
    
    size_t current_len = 0;
    
    char *buffer = (char*)malloc(buf_size);
    current_len += sprintf(buffer, "%d", n->value);
    n = n->next;
    
    while (n != NULL){
        char numbuf[BUFLEN];
        size_t written = sprintf(numbuf, ", %d", n->value);
        
        if(current_len + written >= buf_size){
            size_t new_size = buf_size + BUFLEN;
            char* tmp = (char*)realloc(buffer, new_size);
            if(!tmp){
                return buffer;
            }
            buffer = tmp;
            buf_size = new_size;
        }
        strcat(buffer, numbuf);
        current_len += written;
        n = n->next;
    }
    
    return buffer;
}
