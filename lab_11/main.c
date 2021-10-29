#include <stdio.h>

#include "bst_tree.h"

int main(void) {
  bst_tree T;
  
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
  
  if(tree_search(T.root, 13))
      puts("El valor 13 está en el árbol.");
  else
      puts("No está el valor 13.");
  
  show(T.root, 0);

  return 0;
}
