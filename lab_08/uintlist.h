#ifndef __UINTLIST_H__
#define __UINTLIST_H__

typedef unsigned int uint_t;

typedef struct node_int *link;

typedef struct node_int {
    uint_t value;
    link next;
    link previous;
} node;

typedef struct {
    uint_t len;
    node* head;
    node* tail;
} list;

//--------------------------------------------------
// Interfaz para la lista
//--------------------------------------------------

// Interfaz para los nodos
// Crea un nodo nuevo para la lista
node* new_node(uint_t);
// Borra un nodo
void free_node(node*);

// Operaciones de lista
// Crea una lista como puntero
list* create_list();
// Inserta un elemento al inicio de la lista
void insert_first(list*, uint_t);
// Inserta un elemento al final de la lista
void insert_last(list*, uint_t);
// Borra un elemento de la lista
void delete_element(list*, uint_t);

// Vacía la lista
void empty_list(list*);
// Borra la lista apuntada por el parámetro
void delete_list(list*);

// Convierte la lista a un string con sus valores separados por coma
// Debe liberarse la memoria del puntero devuelto manualmente
char* list_to_string(list*);

#endif
