#include <stdio.h>

#include "pqueue.h"

int main(){
    pqueue q;
    q.root = 0;
    
    pqueue_append(&q, 0, 10);
    pqueue_append(&q, 2.5, 20);
    pqueue_append(&q, -2.5, 30);
    pqueue_append(&q, 3, 1);
    pqueue_append(&q, 4, 2);
    pqueue_append(&q, 2.6, 5);
    pqueue_append(&q, -1.2, 10);
    
    inorder_tree_walk(q.root);
    putchar('\n');
    
    printf("Mínima prioridad: %d\n", pqueue_extract_min(&q));
    
    inorder_tree_walk(q.root);
    putchar('\n');
    
    tree_empty(q.root);
    return 0;
}
