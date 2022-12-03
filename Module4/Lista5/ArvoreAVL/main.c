#include <stdio.h>
#include <stdlib.h>

#include "avl.h"

int main(void) {

  ITEM* item1 = item_criar(4);
  ITEM* item2 = item_criar(1);
  ITEM* item3 = item_criar(2);

  ITEM* item4 = item_criar(5);


  AVL* T = avl_criar();
  avl_inserir(T, item1);
  avl_inserir(T, item2);
  avl_inserir(T, item3);
  avl_inserir(T, item4);

  avl_apagar(&T);

  return 0;
}