#include "tdagraph.h"

// Por completitud, aunque no es necesario, porque está incluido en tdagraph.h
#include "uintlist.h"

#include <stdlib.h>
#include <stdio.h>

graph* create_graph(uint_t n){
    graph* g = (graph*)malloc(sizeof(graph));
    
    if (!g) return NULL;
    
    g->n_vertices = n;
    g->n_edges = 0;
    
    g->vertices = (list*)malloc(sizeof(list)*g->n_vertices);
    if (!g->vertices){
        free(g);
        return NULL;
    }
    
    for(int i=0; i < g->n_vertices; i++){
        g->vertices[i].len = 0;
        g->vertices[i].head = NULL;
        g->vertices[i].tail = NULL;
    }
    
    return g;
}


void delete_graph(graph *g){
    for(int i=0; i < g->n_vertices; i++){
        empty_list(&g->vertices[i]);
    }
    
    free(g->vertices);
    free(g);
}


void insert_edge(graph* g, edge e){
    if(!is_edge(g, e)){
        insert_last(&g->vertices[e.u], e.v);
        insert_last(&g->vertices[e.v], e.u);
        
        g->n_edges++;
    }
}


void delete_edge(graph* g, edge e){
    if(is_edge(g, e)){
        delete_element(&g->vertices[e.u], e.v);
        delete_element(&g->vertices[e.v], e.u);
        
        g->n_edges--;
    }
}


bool is_edge(graph* g, edge e){
    node* n = g->vertices[e.u].head;
    
    for(int i = 0; i < g->vertices[e.u].len; i++){
        if (n->value == e.v)
            return true;
        n = n->next;
    }
    
    return false;
}


void show_graph(graph* g){
    printf("Grafo de orden %d y tamaño %d:\n",
           g->n_vertices, g->n_edges);
    for(int i = 0; i < g->n_vertices; i++){
        char *adjacent_vertices = list_to_string(&g->vertices[i]);
        printf("%d: %s\n", i, adjacent_vertices);
        free(adjacent_vertices);
    }
}
