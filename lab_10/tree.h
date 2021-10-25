#ifndef __TREE_H__
#define __TREE_H__

typedef struct node_t* link;
typedef struct node_t {
  int key;
  
  link p;
  link left;
  link right;
} node;

typedef struct {
  node* root;
} tree;

node* create_node(int);
node* insert_left(tree*, int);
node* insert_right(tree*, int);

void insert_at_left(node*, int);
void insert_at_right(node*, int);

void inorder_tree_walk(node*);

#endif
