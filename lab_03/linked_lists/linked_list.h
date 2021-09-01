#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

// Tipo de dato que usaremos como elemento de la lista, un string
typedef char* data_type;
typedef unsigned int uint;

// Declaración de tipo para poder definir la estructura node
typedef struct node_template* link;

// La estructura node, define tipo y puntero al tipo
typedef struct node_template {
    data_type key;
    link next;
} node, *p_node;

// Crea un nodo con el valor dado
p_node create_node(data_type);
// Destruye el nodo
void free_node(p_node);

// Inserta al inicio
p_node list_insert(p_node, data_type);

// Muestra la lista
void show_list(p_node);

// Vacía la lista (elimina todos los nodos de esta)
void list_clear(p_node);

// Encuentra el nodo anterior al valor que buscamos
p_node list_previous_node(p_node, data_type);
// Remueve el nodo con el valor dado
p_node list_remove(p_node, data_type);

/************************************************************
 * POR IMPLEMENTAR (TAREA)
 * 
 * Solo están declaradas acá y descritas
 ************************************************************/
// Busca el valor `x' en la lista `list' y devuelve el nodo donde se encuentra
p_node list_search(p_node list, data_type x);

// Inserta el valor `x' en la posición `pos' (número de elemnto) de la lista `list'
// Retorna un puntero al primer elemento de la lista
// Nota: hay que contar posiciones acá que no son almacenadas en la estructura
p_node list_insert_in_pos(p_node list, uint pos, data_type value);

// Recupera el último elemento de la lista `list'
p_node list_tail(p_node list);

#endif
