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
} bst_tree;

node* create_node(int);

void tree_insert(bst_tree*, int);

int tree_minimum(const bst_tree*);
const node* tree_search(const node*, const int);

void inorder_tree_walk(const node*);

void show(node*, int);


#endif
