#ifndef __PQUEUE_H__
#define __PQUEUE_H__

#include <stdbool.h>

typedef struct qnode_template *qlink;

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

int tree_minimum(pqueue*);
const qnode* tree_search(const qnode*, const int);
bool pqueue_contains(const pqueue*, const int);

void inorder_tree_walk(const qnode*);

void tree_empty(qnode*);

#endif
