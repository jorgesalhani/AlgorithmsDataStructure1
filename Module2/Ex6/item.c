#include <stdio.h>
#include <stdlib.h>
#include "item.h"

struct item_ {
  int chave;
};

// Funcoes utils
// =============

bool _item_existe(ITEM* item) {
  return item != NULL ? true : false;
}

// Funcoes de interface
// ====================

ITEM *item_criar(int chave) {
  ITEM* item = (ITEM*) malloc(sizeof(ITEM));
  if (_item_existe(item)) item->chave = chave;
  return item;
}

bool item_apagar(ITEM **item) {
  if (!_item_existe(*item) || item == NULL) return false;
  free(*item);
  *item = NULL;
  item = NULL;
  return true;
}

void item_imprimir(ITEM *item) {
  if (!_item_existe(item)) return;
  printf("ITEM | %d\n", item->chave);
  return;
}

int item_get_chave(ITEM *item) {
  return _item_existe(item) ? item->chave : ERRO;
}

bool item_set_chave(ITEM *item, int chave) {
  if (!_item_existe(item)) return false;
  item->chave = chave;
  return true;
}
