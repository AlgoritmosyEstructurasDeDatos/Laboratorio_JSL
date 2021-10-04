#include "graphloader.h"

#include <stdio.h>

graph* read_graph_from_file(char* filename){
    // Archivo a leer
    FILE *fp = fopen(filename, "r");
    
    // Carga el número de vértices
    int vertices;
    fscanf(fp, "%d", &vertices);
    
    // Crea el grafo con los vértices cargados
    graph* g = create_graph(vertices);
    
    // Arista que se agregará en el grafo con cada vuelta
    edge new_edge;
    /* La familia de funciones scanf entrega como resultado la cantidad de
     * elementos leídos desde el flujo que se les indica. Como el formato de
     * grafo usado en este ejemplo es una arista por línea, busca leer dos
     * enteros seguidos, separados por algún espacio en blanco. Si podemos leer
     * eso, significa que aún podemos leer aristas. Si lee menos que eso, por
     * ejemplo, porque llegó al final del archivo, simplemente la condición no
     * se cumple.
     * 
     * Nótese que, como necesita la dirección (puntero) donde almacenar lo que lee,
     * le pasamos la dirección de los miembros de la arista (i.e. los miembros de
     * la estructura edge definida en tdagraph.h)
     */
    while (fscanf(fp, "%d %d", &new_edge.u, &new_edge.v) == 2){
        // Agrega la arista al grafo
        insert_edge(g, new_edge);
    }
    
    // Cierra el archivo y retorna el grafo cargado
    fclose(fp);
    return g;
}
