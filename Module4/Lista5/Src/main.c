#include <stdio.h>
#include <stdlib.h>
#include "ab.h"
#include "item.h"

int main(void) {

  ITEM* item = item_criar(1);
  printf("%d\n", item_get_chave(item));
  item_imprimir(item);
  item_apagar(&item);

  return 0;
}