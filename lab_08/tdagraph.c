#include "tdagraph.h"

// Por completitud, aunque no es necesario, porque está incluido en tdagraph.h
#include "uintlist.h"

#include <stdlib.h>

graph* create_graph(int n){
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
        empty_list(g->vertices[i]);
    }
    
    free(g->vertices);
    free(g);
}


void insert_edge(graph* g, edge e){
    if(!is_edge(g, e)){
        insert_last(g->vertices[e.u], e.v);
        insert_last(g->vertices[e.v], e.u);
        
        g->n_edges++;
    }
}


void delete_edge(graph*, edge){
    if(is_edge(g, e)){
        delete_node(g->vertices[e.u], e.v);
        delete_node(g->vertices[e.v], e.u);
        
        g->n_edges--;
    }
}


bool is_edge(graph* g, edge e){
    list *edges = g->vertices[e.u];
    node* n = edges->head;
    
    for(int i = 0; i < edges->len; i++){
        if (n->value == e.v)
            return true;
        n = n->next;
    }
    
    return false;
}
