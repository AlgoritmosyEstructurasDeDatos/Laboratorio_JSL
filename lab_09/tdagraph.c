#include "tdagraph.h"

#include "uintqueue.h"
#include "uintstack.h"

#include <stdlib.h>
#include <stdio.h>

graph* create_graph(uint_t n){
    // Espacio para el grao
    graph* g = (graph*)malloc(sizeof(graph));
    if (!g) return NULL;
    
    // Inicializa sus valores
    g->n_vertices = n;
    g->n_edges = 0;
    
    // Inicializa el arreglo de listas de adyacencia
    g->vertices = (list*)malloc(sizeof(list)*g->n_vertices);
    // Si no se pudo iniciar, hay que liberar el espacio, porque no se puede
    // crear el grafo y se retorna nulo como resultado del error
    if (!g->vertices){
        free(g);
        return NULL;
    }
    
    // Todo puntero debe inicializarse en NULL, si no se asignará de inmediato
    for(int i=0; i < g->n_vertices; i++){
        // Puede no ser necesario inicializar números a 0, pero resulta conveniente
        g->vertices[i].len = 0;
        g->vertices[i].head = NULL;
        g->vertices[i].tail = NULL;
    }
    
    // El grafo está listo para ser utilizado
    return g;
}


void delete_graph(graph *g){
    /* Al borrar una estructura como esta, es importante recordar que tiene
     * mucha memoria asignada de manera dinámica que, si no liberamos como
     * corresponde, quedará perdida (pedida y sin poder liberarse). Por lo que
     * borramos desde la estructura más interna hasta la más externa, liberando
     * toda la memoria solicitada.
     */
    // Primero vacía los nodos añadidos a las listas
    for(int i=0; i < g->n_vertices; i++){
        /* Nótese que el arreglo es un arreglo de listas, por lo que, como 
         * las funciones de listas declaradas en uintlist.h son con punteros a
         * lista, tenemos que pasarle la dirección (de ahí el & antes de la
         * variable)
         */
        empty_list(&g->vertices[i]);
    }
    
    // Libera el espacio del arreglo
    free(g->vertices);
    // Libera el espacio para la estructura principal
    free(g);
}


void insert_edge(graph* g, edge e){
    // Si la arista no existe, la agrega (pasa de largo, si no)
    if(!is_edge(g, e)){
        // Notar que esto es para un *grafo no dirigido*
        insert_last(&g->vertices[e.u], e.v);
        insert_last(&g->vertices[e.v], e.u);
        
        // Aumenta la cantidad de aristas en el grafo
        g->n_edges++;
    }
}


void delete_edge(graph* g, edge e){
    // Si la arista existe, la elimina (pasa de largo si no)
    if(is_edge(g, e)){
        // Notar que esto es para un *grafo no dirigido*
        delete_element(&g->vertices[e.u], e.v);
        delete_element(&g->vertices[e.v], e.u);
        
        // Disminuye la cantidad de aristas en el grafo
        g->n_edges--;
    }
}


bool is_edge(graph* g, edge e){
    // Toma el primer nodo. Si la lista está vacía, esto es un NULL
    node* n = g->vertices[e.u].head;
    
    // Recorre todos los nodos, usando el largo actual de la lista como 
    // límite. Si head es NULL, el largo es 0
    for(int i = 0; i < g->vertices[e.u].len; i++){
        // Si el valor del nodo es el que se está comprobando, retorna verdadero
        if (n->value == e.v)
            return true;
        // Vamos al próximo elemento
        n = n->next;
    }
    
    // Llegando al final sin haber retornado verdadero es señal de que no existe
    return false;
}


void show_graph(graph* g){
    // Información básica del grafo
    printf("Grafo de orden %d y tamaño %d:\n",
           g->n_vertices, g->n_edges);
    
    // Recorre cada vértice (lista de adyacencia de)
    for(int i = 0; i < g->n_vertices; i++){
        // Convierte la lista a string
        char *adjacent_vertices = list_to_string(&g->vertices[i]);
        // Muestra el índice y sus vértices adyacentes
        printf("%d: %s\n", i, adjacent_vertices);
        // Libera la memoria usada por el string
        free(adjacent_vertices);
    }
}


uint_t* bfs(graph* g, uint_t start, uint_t goal){
    uintqueue *q = create_queue();
//     list *visited = create_list();
    uint_t visited[g->n_vertices];
    for(int i = 0; i < g->n_vertices; i++)
        visited[i] = 0;
    
    uint_t* parents = (uint_t*)calloc(sizeof(uint_t), g->n_vertices);
    parents[start] = start;
//     insert_first(visited, start);
    visited[start] = 1;
    enqueue(q, start);
    
    while (q->head){
        uint_t u = dequeue(q);
        
        node *v = g->vertices[u].head;
        for(int i=0; i < g->vertices[u].len; i++){
//             if(!is_in_list(visited, v->value)){
//                 insert_first(visited, v->value);
            if(visited[v->value] == 0){
                visited[v->value] = 1;
                parents[v->value] = u;
                if (v->value == goal) {
//                     delete_list(visited);
//                     delete_queue(q);
                    return parents;
                }
                enqueue(q, v->value);
            }
            v = v->next;
        }
    }
    
//     delete_list(visited);
    delete_queue(q);
    free(parents);
    return NULL;
}

uint_t* dfs(graph* g, uint_t start, uint_t goal){
    uintstack *s = create_stack(g->n_vertices);
    uint_t visited[g->n_vertices];
    for(int i = 0; i < g->n_vertices; i++)
        visited[i] = 0;
    
    uint_t* parents = (uint_t*)calloc(sizeof(uint_t), g->n_vertices);
    parents[start] = start;
    visited[start] = 1;
    push(s, start);
    
    while (s->top > 0){
        uint_t u = pop(s);
        
        node *v = g->vertices[u].head;
        for(int i=0; i < g->vertices[u].len; i++){
            if(visited[v->value] == 0){
                visited[v->value] = 1;
                parents[v->value] = u;
                if (v->value == goal) {
                    delete_stack(s);
                    return parents;
                }
                push(s, v->value);
            }
            v = v->next;
        }
    }
    
    delete_stack(s);
    free(parents);
    return NULL;
}
