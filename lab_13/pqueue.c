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

qnode* tree_minimum(qnode* x){
    while(x->left)
        x = x->left;
    return x;
}

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


void pqueue_delete_node(pqueue* T, qnode* z){
    if(!z->left)
        transplant(T, z, z->right);
    else if(!z->right)
        transplant(T, z, z->left);
    else{
        qnode* y = tree_minimum(z->right);
        if(y->p != z){
            transplant(T, y, y->right);
            y->right = z->right;
            y->right->p = y;
        }
        transplant(T, z, y);
        y->left = z->left;
        y->left->p = y;
    }
}


int pqueue_extract_min(pqueue* q){
    qnode* min = tree_minimum(q->root);
    pqueue_delete_node(q, min);
    int value = min->value;
    free(min);
    return value;
}
