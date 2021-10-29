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
} // fin tree_insert


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


void printnode(int value, int h){
    for(int i = 0; i<h;i++) printf("   ");
    printf("%3d\n", value);
}


void show(node* x, int h){
    if (!x){
        for(int i=0; i<h; i++) printf("   ");
        puts("*");
        return;
    }
    
    show(x->right, h+1);
    printnode(x->key, h);
    show(x->left, h+1);
}


void tree_empty(node* n){
    if(n){
        tree_empty(n->left);
        tree_empty(n->right);
        free(n);
    }
}
