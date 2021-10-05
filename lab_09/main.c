#include <stdio.h>
#include <stdlib.h>

#include "graphloader.h"
#include "tdagraph.h"

int main(){
    // Carga el grafo de ejemplo
    graph* g = read_graph_from_file("sample.digraph");
    
    // Muestra el grafo con la función definida para eso
    show_graph(g);
    
    uint_t *path = bfs(g, 2, 4);
    
    printf("Se llega a 4 desde %u\n", path[4]);
    // Borra el grafo
    delete_graph(g);
    
    free(path);
    
    // Fin del programa de prueba
    return 0;
}
