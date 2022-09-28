#include <stdlib.h>
#include <stdio.h>
#include "item.h"

struct item_ {
  float chave;
};

ITEM *item_criar(float chave) {
  ITEM* item = (ITEM*) malloc(sizeof(ITEM));
  if (item != NULL) item->chave = chave;
  return item;
}

bool item_apagar(ITEM **item) {
  if (*item == NULL) return false;
  free(*item);
  *item = NULL;
  item = NULL;
}

void item_imprimir(ITEM *item) {
  if (item == NULL) return;
  printf("%f\n", item->chave);
}

float item_get_chave(ITEM *item) {
  if (item == NULL) return 404.404;
  return item->chave;
}

bool item_set_chave(ITEM *item, float chave) {
  if (item == NULL) return false;
  item->chave = chave;
  return true;
}
