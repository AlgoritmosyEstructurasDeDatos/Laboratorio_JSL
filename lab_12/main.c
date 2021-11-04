#include <stdio.h>
#include <stdlib.h>

#include "char_graph.h"


int main(){
    // Datos a rellenar
    char vertices[] = "abcdefgh";
    int N = 8;
    
    // Crea el grafo e inserta algunas aristas
    char_graph* g = create_graph(N, vertices);
    
    edge e = new_edge(0, 1, NULL);
    insert_edge(g, e);
    e = new_edge(6, 1, NULL);
    insert_edge(g, e);
    
    // Muestra la matriz del grafo
    for(int i=0; i < g->V; i++)
        printf("\t%c", g->vertices[i]);
    putchar('\n');
    for(int i=0; i < g->V; i++){
        printf("%c\t", g->vertices[i]);
        for(int j=0; j < g->V; j++)
            printf("%d\t", g->edges[i][j]);
        putchar('\n');
    }
    
    // Obtiene el grado de un vértice y muestra sus conexiones
    uint_t degree = get_vertex_degree(g, 1);
    printf("El grado del vértice %c es %d\n", g->vertices[1], degree);
    uint_t *adjacents = get_adjascent_vertices(g, 1);
    
    for(int i = 0; i < degree; i++){
        printf("%c -- %c\n", g->vertices[1], g->vertices[adjacents[i]]);
    }
    
    // Libera la memoria
    free(adjacents);
    delete_graph(g);
    
    return 0;
}
