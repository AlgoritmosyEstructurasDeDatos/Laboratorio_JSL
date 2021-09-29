#ifndef __TDAGRAPH_H__
#define __TDAGRAPH_H__

#include "uintlist.h"

#include <stdbool.h>

typedef unsigned int uint_t;

typedef struct {
    uint_t u;
    uint_t v;
} edge;

typedef struct {
    uint_t n_vertices;
    uint_t n_edges;
    list *vertices;
} graph;

//--------------------------------------------------
// Interfaz para el grafo
//--------------------------------------------------

graph* create_graph(uint_t);
void insert_edge(graph*, edge);
void delete_edge(graph*, edge);

bool is_edge(graph*, edge);

void delete_graph(graph*);

#endif
