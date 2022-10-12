#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "deque.h"

int main(void) {

  ITEM* item = item_criar(1);
  ITEM* item2 = item_criar(2);
  ITEM* item3 = item_criar(3);
  ITEM* item4 = item_criar(4);

  DEQUE* deque = deque_criar();
  deque_inserir_inicio(deque, item);
  deque_imprimir_inicio(deque);
  printf(" -- ");
  deque_imprimir_fim(deque);
  printf("\n");

  deque_inserir_inicio(deque, item2);
  deque_imprimir_inicio(deque);
  printf(" -- ");
  deque_imprimir_fim(deque);
  printf("\n");

  deque_inserir_inicio(deque, item3);
  deque_imprimir_inicio(deque);
  printf(" -- ");
  deque_imprimir_fim(deque);
  printf("\n");

  deque_inserir_fim(deque, item4);
  deque_imprimir_inicio(deque);
  printf(" -- ");
  deque_imprimir_fim(deque);
  printf("\n");

  ITEM* item_pop = deque_remover_inicio(deque);
  item_apagar(&item_pop);
  deque_imprimir_inicio(deque);
  printf(" -- ");
  deque_imprimir_fim(deque);
  printf("\n");

  deque_inverter_extremos(deque);
  deque_imprimir_inicio(deque);
  printf(" -- ");
  deque_imprimir_fim(deque);
  printf("\n");

  item_pop = deque_remover_fim(deque);
  item_apagar(&item_pop);
  deque_imprimir_inicio(deque);
  printf(" -- ");
  deque_imprimir_fim(deque);
  printf("\n");

  item_pop = deque_remover_fim(deque);
  item_apagar(&item_pop);
  deque_imprimir_inicio(deque);
  printf(" -- ");
  deque_imprimir_fim(deque);
  printf("\n");

  deque_apagar(&deque);

  // item_apagar(&item);

  return 0;
}