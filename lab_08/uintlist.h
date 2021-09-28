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
node* new_node(uint_t);
void free_node(node*);

// Operaciones de lista
list* create_list();
void insert_first(list*, uint_t);
void insert_last(list*, uint_t);
void delete_node(list*, uint_t);

void empty_list(list*);

void delete_list(list*);

char* list_to_string(list*);


#endif
