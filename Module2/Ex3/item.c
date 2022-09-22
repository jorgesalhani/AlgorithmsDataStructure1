#include "item.h"
#include <stdlib.h>
#include <stdio.h>

struct item_
{
  char chave;
};

ITEM *item_criar(char chave) {
  ITEM *item = (ITEM *) malloc(sizeof(ITEM));

  if (item != NULL && sizeof(chave) == sizeof(char)) {
    item->chave = chave;
    return item;
  }
  return NULL;
}

bool item_apagar(ITEM **item) {
  if (*item != NULL && sizeof(*item) == sizeof(ITEM*)) {
    free(*item);
    *item = NULL;
    return true;
  }
  return false;
}

void item_imprimir(ITEM *item) {
  if (item != NULL) printf("%c\n", item->chave);
}

char item_get_chave(ITEM *item) {
  if (item == NULL) return '\0';
  return (item->chave);
}

bool item_set_chave(ITEM *item, char chave) {
  if (item == NULL) return false;
  item->chave = chave;
  return true;
}