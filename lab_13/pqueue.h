#ifndef __PQUEUE_H__
#define __PQUEUE_H__

#include <stdbool.h>

typedef struct qnode_template *qlink;

typedef struct {
    int vertex;
    int p;
} prim_node;


typedef struct qnode_template {
    float key;
    int value;
    
    qlink p;
    qlink left;
    qlink right;
} qnode;

typedef struct {
    qnode* root;
} pqueue;

void pqueue_append(pqueue*, const float, const int);

qnode* tree_minimum(qnode* x);

int pqueue_extract_min(pqueue*);

const qnode* tree_search(const qnode*, const int);
bool pqueue_contains(const pqueue*, const int);

void inorder_tree_walk(const qnode*);

void tree_empty(qnode*);
void pqueue_delete_node(pqueue*, qnode*);


#endif
