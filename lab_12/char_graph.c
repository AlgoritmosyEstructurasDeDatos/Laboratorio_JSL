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
    
    // Espacio para el arreglo de punteros. El espacio a pedir es suficiente
    // para almacenar los punteros que necesitamos.
    g->edges = (int**)malloc(g->V * sizeof(int*));
    if(!g->edges){
        fprintf(stderr, "Error de memoria");
        free(g->vertices);
        free(g);
        return NULL;
    }

    /*
     * Mediante esta estrategia, solo llamamos a malloc dos veces: una para
     * el arreglo de punteros y otra para pedir el bloque completo de la matriz.
     * Además, nos da la ventaja de que la matriz quedará en un bloque contiguo de
     * memoria, mientras que la otra versión podría tener algunas filas en lugares
     * diferentes.
     * 
     * La complicación de esta versión es poner en el lugar correcto cada puntero,
     * para lo que hay que saber que, en una matriz de NxM, la fila i (de 0 a N-1)
     * comienza en la posición i*M.
     */
//     int *region = (int*)malloc(g->V*g->V*sizeof(int));
//     for(int i = 0; i < g->V; i++) g->edges[i] = region+(i*g->V);
    
    // Inicializa la matriz
    for(int i = 0; i < g->V; i++){
        // Espacio para cada arreglo de enteros (fila
        g->edges[i] = (int*)malloc(g->V * sizeof(int));
        // Chequeo de errores
        if(!g->edges[i]){
            fprintf(stderr, "Error de memoria");
            for(i = i-1; i >= 0; i--) free(g->edges[i]);
            free(g->vertices);
            free(g);
            return NULL;
        }
        // Inicializa la fila en 0
        for(int j= 0; j < g->V; j++) g->edges[i][j] = 0;
    }
    
    return g;
}


void delete_graph(char_graph* g){
    // Esta versión libera el bloque de memoria pedido en un solo malloc
    //free(g->edges[0]);
    
    // Libera las filas
    for(int i= 0; i < g->V; i++) free(g->edges[i]);
    free(g->edges);
    free(g->vertices);
    free(g);
}


// Crea una nueva arista. Si w == NULL, supone peso 1
edge new_edge(const uint_t u, const uint_t v, const int* w){
    edge e;
    if(w) e.w = *w;
    else e.w = 1;
    
    e.u = u;
    e.v = v;
    
    return e;
}


// Inserta una arista en el grafo no dirigido
uint_t insert_edge(char_graph* g, edge e){
    g->edges[e.u][e.v] = e.w;
    g->edges[e.v][e.u] = e.w;
    g->E++;
    
    return g->E;
}


// Remueve la arista en el grafo no dirigido
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
