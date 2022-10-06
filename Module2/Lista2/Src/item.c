#include <stdlib.h>
#include <stdio.h>
#include "item.h"

struct item_ {
  int chave;
};

ITEM* item_criar(int chave) {
  ITEM* item = (ITEM*) malloc(sizeof(ITEM));
  if (item != NULL) item->chave = chave;
  return item;
}

int item_get_chave(ITEM* item) {
  if (item == NULL) return CODIGO_ERRO;
  return item->chave;
}

bool item_apagar(ITEM** loc_item) {
  if (*loc_item == NULL) return false;
  free(*loc_item);
  *loc_item = NULL;
  loc_item = NULL;
  return true;
}

bool item_set_chave(ITEM* item, int chave) {
  if (item == NULL) return false;
  item->chave = chave;
  return true;
}

void item_imprimir(ITEM* item) {
  if (item == NULL) return;
  printf("ITEM | chave: %d\n", item->chave);
  return;
}
