#include <stdio.h>

#include "bst_tree.h"

int main(void) {
  bst_tree T;
  T.root = 0;
  
  tree_insert(&T, 10);
  tree_insert(&T, 2);
  tree_insert(&T, 0);
  tree_insert(&T, 6);
  tree_insert(&T, 4);
  tree_insert(&T, 7);
  tree_insert(&T, 12);
  tree_insert(&T, 15);
  tree_insert(&T, 20);
  tree_insert(&T, 13);
  

  inorder_tree_walk(T.root);
  putchar('\n');
  
  printf("El nodo más pequeño es %d\n", tree_minimum(&T));
  
  int x = 21;
  if(tree_search(T.root, x))
      printf("El valor %d está en el árbol.\n", x);
  else
      printf("No está el valor %d.\n", x);
//   
  show(T.root, 0);
  
  tree_empty(T.root);

  return 0;
}
