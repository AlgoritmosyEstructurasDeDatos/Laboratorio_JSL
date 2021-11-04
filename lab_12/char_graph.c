#include "char_graph.h"

#include <stdlib.h>
#include <stdio.h>

char_graph* create_graph(const uint_t n, const char v[]){
    char_graph* g = (char_graph*)malloc(sizeof(char_graph));
    
    g->V = n;
    g->E = 0;
    
    g->vertices = (char*)malloc(sizeof(char)*g->V);
    
    for(int i=0; i < g->V; i++)
        g->vertices[i] = v[i];
    
    g->edges = (int**)calloc(g->V, sizeof(int));
    if(!g->edges){
        fprintf(stderr, "No hay memoria D:");
        return NULL;
    }
    
    for(int i = 0; i < g->V; i++){
        g->edges[i] = (int*)calloc(g->V, sizeof(int));
        if(!g->edges[i]) printf("error");
//         printf("%lu", g->edges[i]);
    }
    
    return g;
}


void delete_graph(char_graph* g){
    free(g->edges);
    free(g->vertices);
    free(g);
}


edge new_edge(const uint_t u, const uint_t v, const int* w){
    edge e;
    if(w) e.w = *w;
    else e.w = 1;
    
    e.u = u;
    e.v = v;
    
    return e;
}


uint_t insert_edge(char_graph* g, edge e){
    g->edges[e.u][e.v] = e.w;
    g->edges[e.v][e.u] = e.w;
    g->E++;
    
    return g->E;
}


uint_t remove_edge(char_graph* g, uint_t u, uint_t v){
    g->edges[u][v] = 0;
    g->edges[v][u] = 0;
    g->E--;
    
    return g->E;
}


uint_t get_vertex_degree(const char_graph* g, const uint_t u){
    uint_t degree = 0;
    for(int i = 0; i < g->V; i++)
        if(g->edges[u][i] != 0)
            degree++;
        
    return degree;
}


uint_t* get_adjascent_vertices(const char_graph* g, 
                               const uint_t u){
    uint_t degree = get_vertex_degree(g, u);
    
    uint_t* adjacent = (uint_t*)malloc(sizeof(uint_t)*degree);
    
    for(int i = 0, j = 0; i < g->V; i++)
        if(g->edges[u][i] != 0)
            adjacent[j] = i;
        
    return adjacent;
}
