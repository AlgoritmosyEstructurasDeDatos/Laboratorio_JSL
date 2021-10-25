#include "bst_tree.h"

#include <stdlib.h>
#include <stdio.h>

node* create_node(int x){
  node* n = (node*)malloc(sizeof(node));

  n->key = x;
  n->p = NULL;
  n->left = NULL;
  n->right = NULL;

  return n;
}

void tree_insert(bst_tree* T, int z){
    node* parent = NULL;
    node* x = T->root;
    
    while(x){
        parent = x;
        if(z < x->key)
            x = x->left;
        else
            x = x->right;
    }
    
    node* new_node = create_node(z);
    new_node->p = parent;
    if(parent == NULL) T->root = new_node;
    else if(new_node->key < parent->key)
        parent->left = new_node;
    else
        parent->right = new_node;
}


int tree_minimum(const bst_tree* T){
    node* x = T->root;
    while(x->left)
        x = x->left;
    
    return x->key;
}


const node* tree_search(const node* x, const int k){
    if(!x || x->key == k)
        return x;
    else if(k < x->key)
        return tree_search(x->left, k);
    else
        return tree_search(x->right, k);
}



void inorder_tree_walk(const node* n){
  if(n){
    inorder_tree_walk(n->left);
    printf(" %d ", n->key);
    inorder_tree_walk(n->right);
  }
}
