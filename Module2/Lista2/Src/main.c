#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "fila.h"

int main(void) {

  ITEM* item1 = item_criar(1);
  ITEM* item2 = item_criar(2);
  ITEM* item3 = item_criar(3);
  ITEM* item4 = item_criar(4);
  ITEM* item5 = item_criar(5);
  ITEM* item6 = item_criar(6);
  ITEM* item7 = item_criar(7);
  
  FILA* fila = fila_criar();
  fila_inserir(fila, item1);
  fila_inserir(fila, item2);
  fila_inserir(fila, item3);
  fila_inserir(fila, item4);
  fila_inserir(fila, item5);

  fila_imprimir(fila);
  fila_completa_imprimir(fila);
  
  ITEM* item_aux = fila_remover(fila);
  ITEM* item_aux2 = fila_remover(fila);

  fila_imprimir(fila);
  fila_completa_imprimir(fila);
  
  fila_inserir(fila, item6);
  fila_completa_imprimir(fila);

  
  ITEM* item_aux3 = fila_remover(fila);
  
  fila_inserir(fila, item7);
  
  fila_imprimir(fila);
  fila_completa_imprimir(fila);

  fila_apagar(&fila);

  item_apagar(&item_aux);
  item_apagar(&item_aux2);
  item_apagar(&item_aux3);
  
  

  return 0;
}