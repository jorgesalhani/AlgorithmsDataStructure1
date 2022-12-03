#include <stdio.h>
#include <stdlib.h>
#include "ab.h"
#include "item.h"

int main(void) {

  ITEM* item1 = item_criar(1);
  ITEM* item2 = item_criar(2);
  ITEM* item3 = item_criar(3);
  ITEM* item4 = item_criar(4);
  ITEM* item5 = item_criar(5);
  
  AB* T = ab_criar();
  ab_inserir(T, item1, 0, 1);
  ab_inserir(T, item2, 1, 1);
  ab_inserir(T, item5, 0, 1);
  ab_inserir(T, item3, 0, 2);
  ab_inserir(T, item4, 1, 2);

  printf("profund: %d\n", ab_profundidade(T));

  printf("soma: %d\n", ab_soma_conteudo(T));

  printf("n. nós: %d\n", ab_total_nos(T));

  printf("AB estrita? %s\n", ab_estrita(T) ? "Sim" : "Nao");

  ab_apagar_arvore(&T);
  

  return 0;
}