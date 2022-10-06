#ifndef ITEM_H
  #define ITEM_H
  #include <stdbool.h>
  #define CODIGO_ERRO -21

  typedef struct item_ ITEM;

  ITEM* item_criar(int chave);
  int item_get_chave(ITEM* item);
  bool item_apagar(ITEM** loc_item);
  bool item_set_chave(ITEM* item, int chave);
  void item_imprimir(ITEM* item);

#endif