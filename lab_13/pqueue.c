#include "pqueue.h"

#include <stdlib.h>
#include <stdio.h>

qnode* create_node(const float k, const int v){
  qnode* n = (qnode*)malloc(sizeof(qnode));

  n->key = k;
  n->value = v;
  
  n->p = NULL;
  n->left = NULL;
  n->right = NULL;

  return n;
}


qnode* pqueue_insert(qnode* root, qnode* x){
    if(!root)
        root = x;
    else if(x->key < root->key)
        root->left = pqueue_insert(root->left, x);
    else
        root->right = pqueue_insert(root->right, x);
    return root;
}

void pqueue_append(pqueue* queue, const float k, const int v){
    qnode* new = create_node(k, v);
    queue->root = pqueue_insert(queue->root, new);
}

int tree_minimum(pqueue*);
const qnode* tree_search(const qnode* x, const int k){
    if(!x || x->key == k)
        return x;
    else if(k < x->key)
        return tree_search(x->left, k);
    else
        return tree_search(x->right, k);
}


bool pqueue_contains(const pqueue* T, const int k){
    return tree_search(T->root, k) ? true:false;
}


void inorder_tree_walk(const qnode* n){
    if(n){
        inorder_tree_walk(n->left);
        printf(" (%.2f, %d) ", n->key, n->value);
        inorder_tree_walk(n->right);
    }
}


void tree_empty(qnode* n){
    if(n){
        tree_empty(n->left);
        tree_empty(n->right);
        free(n);
    }
}


void transplant(pqueue* T, qnode* u, qnode* v){
    if(!u->p) T->root = v;
    else if(u == u->p->left) u->p->left = v;
    else u->p->right = v;
    if(v) v->p = u->p;
}