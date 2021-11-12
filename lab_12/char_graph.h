#ifndef __CHAR_GRAPH_H__
#define __CHAR_GRAPH_H__

#include <stdbool.h>

typedef unsigned int uint_t;

typedef struct {
    // Desde
    uint_t u;
    // Hacia
    uint_t v;
    // Peso
    float w;
} edge;

typedef struct {
    // Número de vértices
    uint_t V;
    // Número de aristas
    uint_t E;
    
    // Si es dirigido
    bool is_digraph;
    
    // Arreglo con los caracteres guardados
    char* vertices;
    
    // Matriz de adyacencia
    float** edges;
} char_graph;

char_graph* create_graph(const uint_t, const char[]);
void set_digraph(char_graph*);
void unset_digraph(char_graph*);
void delete_graph(char_graph*);

edge new_edge(const uint_t, const uint_t, const float);

uint_t insert_edge(char_graph*, edge);
uint_t remove_edge(char_graph*, uint_t, uint_t);

uint_t get_vertex_degree(const char_graph*, const uint_t);
uint_t* get_adjascent_vertices(const char_graph*, const uint_t);

#endif
