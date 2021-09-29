#include <stdio.h>

#include "graphloader.h"
#include "tdagraph.h"

int main(){
    // Carga el grafo de ejemplo
    graph* g = read_graph_from_file("sample.digraph");
    
    // Muestra el grafo con la función definida para eso
    show_graph(g);
    
    // Borra el grafo
    delete_graph(g);
    
    // Fin del programa de prueba
    return 0;
}
