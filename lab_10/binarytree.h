#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

typedef struct node* link;

typedef struct node {
    int key;
    
    link parent;
    link left;
    link right;
} tree_node;

typedef struct {
    link root;
} tree;

tree_node* create_node(int, tree_node*);

void insert_at_left(tree*, int);

void insert(tree*, int);

#endif
