#ifndef __TREE_H__
#define __TREE_H__

typedef struct node_template* link;
typedef struct node_template {
    int key;
    
    link p;
    link left_child;
    link right_sibling;
} node;

typedef struct {
    link root;
} tree;

node* insert_at_left(node*, int);
node* insert_at_right(node*, int);

#endif
