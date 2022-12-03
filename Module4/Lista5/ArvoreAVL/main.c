#include <stdio.h>
#include <stdlib.h>

#include "item.h"

int main(void) {

  ITEM* item = item_criar(1);
  item_imprimir(item);
  item_apagar(&item);

  return 0;
}