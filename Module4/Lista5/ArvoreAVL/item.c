#include <stdlib.h>
#include <stdio.h>
#include "item.h"

struct item_ {
  int chave;
};

bool item_existe_(ITEM* item) {
  return (item != NULL) ? true : false;
}

ITEM* item_criar(int chave) {
  ITEM* item = (ITEM*) malloc (sizeof(ITEM));
  if (item_existe_(item)) item->chave = chave;
  return item; 
}

bool item_apagar(ITEM** item) {
  if (item == NULL || !item_existe_(*item)) return false;

  free(*item);
  *item = NULL;
  return true;
}

int item_get_chave(ITEM* item) {
  return (item_existe_(item)) ? item->chave : -40404;
}

bool item_set_chave(ITEM* item, int chave) {
  if (!item_existe_(item)) return false;

  item->chave = chave;
  return true;
}

void item_imprimir(ITEM* item) {
  if (item_existe_(item)) printf("%d\n", item->chave);
}
