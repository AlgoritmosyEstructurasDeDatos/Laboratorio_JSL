#ifndef __TDAGRAPH_H__
#define __TDAGRAPH_H__

#include "uintlist.h"

#include <stdbool.h>

typedef struct {
    unsigned int u,
    unsigned int v,
} edge;

typedef struct {
    unsigned int n_vertices;
    unsigned int n_edges;
    list *vertices;
} graph;

//--------------------------------------------------
// Interfaz para el grafo
//--------------------------------------------------

graph* create_graph(int);
void insert_edge(graph*, edge);
void delete_edge(graph*, edge);

bool is_edge(graph*, edge);

void delete_graph(graph*);

#endif
