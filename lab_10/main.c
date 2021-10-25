#include <stdio.h>

#include "tree.h"

int main(void) {
  tree T;
  T.root = create_node(4);

  node* n = insert_left(&T, 5);
  insert_at_right(n, 6);
  insert_right(&T, 8);

  inorder_tree_walk(T.root);
  putchar('\n');

  return 0;
}
