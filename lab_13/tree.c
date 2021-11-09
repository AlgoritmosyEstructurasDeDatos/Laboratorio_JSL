#include "tree.h"

#include <stdlib.h>

qnode* create_node(const int k){
  node* n = (node*)malloc(sizeof(node));

  n->key = k;
  
  n->p = NULL;
  n->left_child = NULL;
  n->right_sibling = NULL;

  return n;
}

node* insert_at_left(node* x, int k){
    node* n = create_node(k);
    
    n->p = x;
    
    if(x->left_child)
        n->right_sibling = x->left_child;
    x->left_child = n;
    
    return n;
    
}


node* insert_at_right(node* x, int k){
    node* n = create_node(k);
    
    n->p = x;
    
    if(!x->left_child)
        x->left_child = n;
    else{
        node* child = x->left_child;
        while(child->right_sibling)
            child = child->right_sibling;
        child->right_sibling = n;
    }
}


void tree_empty(node* x){
    if(x){
        node* next = x->left_child->right_sibling;
        tree_empty(x->left_child);
        while(next){
            node* temp = next->right_sibling;
            tree_empty(next);
            next = temp;
        }
        free(x);
    }
}
