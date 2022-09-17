#include "item.h"
#include <stdlib.h>

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

}

int item_get_chave(ITEM *item) {

}

bool item_set_chave(ITEM *item, char chave) {

}