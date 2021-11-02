#ifndef __CHAR_GRAPH_H__
#define __CHAR_GRAPH_H__

typedef unsigned int uint_t;

typedef struct {
    // Desde
    uint_t u;
    // Hacia
    uint_t v;
} edge;

typedef struct {
    // Número de vértices
    uint_t V;
    // Número de aristas
    uint_t E;
    
    // Arreglo con los caracteres guardados
    char* vertices;
    
    // Matriz de adyacencia
    int** m_adj;
} char_graph;

#endif
