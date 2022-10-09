#include "item.h"
#include <stdlib.h>
#include <stdio.h>

struct item_ {
  int chave;
};

ITEM *item_criar(int chave) {
  ITEM* item = (ITEM*) malloc(sizeof(ITEM));
  if (item != NULL) item->chave = chave;
  return item;
}

bool item_apagar(ITEM **item) {
  if (item == NULL || *item == NULL) return false;
  free(*item);
  *item = NULL;
  item = NULL;
  return true;
}

void item_imprimir(ITEM *item) {
  if (item == NULL) return;
  printf("%d", item->chave);
  return;
}

int item_get_chave(ITEM *item) {
  if (item == NULL) return ERRO;
  return item->chave;
}

bool item_set_chave(ITEM *item, int chave) {
  if (item == NULL) return false;
  item->chave = chave;
  return true;
}
