#include <stdio.h>
#include <stdlib.h>

#include "graphloader.h"
#include "tdagraph.h"

int main(){
    // Carga el grafo de ejemplo
    graph* g = read_graph_from_file("sample.digraph");
    
    // Muestra el grafo con la función definida para eso
    show_graph(g);
    
    uint s = 2, e = 8;
    uint_t *path = dfs(g, s, e);
    
    for(int i = 0; i < g->n_vertices; i++)
        printf("%u\n", path[i]);
    
    for(uint_t i=e; i != path[i]; i = path[i])
        printf("Se llega a %u desde %u\n", i, path[i]);
    // Borra el grafo
    delete_graph(g);
    
    free(path);
    
    // Fin del programa de prueba
    return 0;
}
