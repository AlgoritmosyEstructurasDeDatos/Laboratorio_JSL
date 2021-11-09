#include <stdio.h>

#include "pqueue.h"

int main(){
    pqueue q;
    q.root = 0;
    
    pqueue_append(&q, 0, 10);
    pqueue_append(&q, 2.5, 20);
    pqueue_append(&q, -2.5, 10);
    
    inorder_tree_walk(q.root);
    putchar('\n');
    
    return 0;
}
