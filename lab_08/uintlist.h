#ifndef __UINTLIST_H__
#define __UINTLIST_H__

typedef struct node_int *link;

typedef struct node_int {
    unsigned int value;
    link next;
    link previous;
} node;

typedef struct {
    int len;
    node* head;
    node* tail;
} list;

//--------------------------------------------------
// Interfaz para la lista
//--------------------------------------------------

// Interfaz para los nodos
node* new_node(int);
void free_node(node*);

// Operaciones de lista
list* create_list();
void insert_first(list*, int);
void insert_last(list*, int);
void delete_node(list*, int);

void empty_list(list*);

void delete_list(list*);

char* list_to_string(list*);


#endif
