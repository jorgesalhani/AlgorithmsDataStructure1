#ifndef ARVORE_AVL_H
  #define ARVORE_AVL_H

  #include <stdbool.h>
  #include "item.h"

  typedef struct avl_ AVL;

  AVL* avl_criar();
  bool avl_apagar(AVL** T);
  bool avl_inserir(AVL* T);
  bool avl_remover(AVL* T, int chave);

#endif