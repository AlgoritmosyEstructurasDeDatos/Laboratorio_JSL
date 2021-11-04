#include <stdio.h>

#include "char_graph.h"


int main(){
    char vertices[] = "abcdefgh";
    int N = 8;
    
    char_graph* g = create_graph(N, vertices);
    
    edge e = new_edge(0, 1, NULL);
    insert_edge(g, e);
    e = new_edge(6, 1, NULL);
    insert_edge(g, e);
    
    for(int i=0; i < g->V; i++)
        printf("\t%c", g->vertices[i]);
    putchar('\n');
    for(int i=0; i < g->V; i++){
        printf("%c\t", g->vertices[i]);
        for(int j=0; j < g->V; j++)
            printf("%d\t", g->edges[i][j]);
        putchar('\n');
    }
    
    delete_graph(g);
    
    return 0;
}
