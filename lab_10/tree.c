#include "tree.h"

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


node* insert_left(tree* T, int x){
  node* n = T->root;
  if(n == NULL){
    n = create_node(x);
    T->root = n;
    return n;
  }
  
  while(n->left)
    n = n->left;

  node* new_node = create_node(x);
  new_node->p = n;
  n->left = new_node;

  return new_node;
}


void insert_at_left(node* parent, int x){
  node* new_node = create_node(x);
  new_node->p = parent;
  parent->left = new_node;
}


node* insert_right(tree* T, int x){
  node* n = T->root;
  if(n == NULL){
    n = create_node(x);
    T->root = n;
    return n;
  }
  
  while(n->right)
    n = n->right;

  node* new_node = create_node(x);
  new_node->p = n;
  n->right = new_node;

  return new_node;
}


void insert_at_right(node* parent, int x){
  node* new_node = create_node(x);
  new_node->p = parent;
  parent->right = new_node;
}


void inorder_tree_walk(node* n){
  if(n){
    inorder_tree_walk(n->left);
    printf(" %d ", n->key);
    inorder_tree_walk(n->right);
  }
}
