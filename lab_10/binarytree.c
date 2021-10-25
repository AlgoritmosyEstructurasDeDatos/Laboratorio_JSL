#include "binarytree.h"

#include <stdlib.h>

tree_node* create_node(int value, tree_node* p){
    tree_node* n = (tree_node*)malloc(sizeof(tree_node));
    
    n->key = value;
    n->parent = p;
    n->left = NULL;
    n->right = NULL;
    
    return n;
}


void insert_at_left(tree* t, int x){
    tree_node* z = t->root;
    
    while(z->left != NULL)
        z = z->left;
    
    tree_node* n = create_node(x, z);
    z->left = n;
}


void insert(tree* t, int value){
    tree_node *parent = NULL;
    tree_node *x = t->root;
    
    while(x != NULL){
        parent = x;
        if(value < x.key) x = x->left;
        else x = x->right;
    }
    
    tree_node *z = create_node(value, parent);
    if(parent == NULL) t->root = z;
    else if(z.key < parent.key) parent->left = z;
    else parent->right = z;
    
    return;
}
