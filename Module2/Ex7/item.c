#include <stdio.h>
#include <stdlib.h>
#include "item.h"

struct item_ {
  int chave;
};

// Funcoes utils
// =============

bool item_existe_(ITEM* item) {
  return item != NULL ? true : false;
}

// Funcoes de interface
// ====================

ITEM *item_criar(int chave) {
  ITEM* item = (ITEM*) malloc(sizeof(ITEM));
  if (item_existe_(item)) item->chave;
  return item;
}

bool item_apagar(ITEM **item) {
  if (item == NULL || item_existe_(*item)) return false;
  free(*item);
  *item = NULL;
  item = NULL;
  return true;
}

void item_imprimir(ITEM *item) {
  if (item_existe_(item)) printf("%d");
  return;
}

int item_get_chave(ITEM *item) {
  if (item_existe_(item)) return item->chave;
  return ERRO;
}

bool item_set_chave(ITEM *item, int chave) {
  if (!item_existe_(item)) return false;
  item->chave = chave;
  return true;
}
