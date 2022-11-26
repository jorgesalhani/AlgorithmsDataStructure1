#ifndef ITEM_H
  #define ITEM_H

  #include "stdbool.h"

  typedef struct item_ ITEM;

  ITEM* item_criar();
  int item_get_chave();
  bool item_set_chave();
  bool item_apagar();

#endif