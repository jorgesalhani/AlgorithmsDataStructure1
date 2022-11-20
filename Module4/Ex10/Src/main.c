#include "ABB.h"
#include <stdio.h>
#include <stdlib.h>
    
int main(int argc, char *argv[]){

  // ABB *T;
  // T = abb_criar();
  // ITEM* item1 = item_criar(2);
  // ITEM* item2 = item_criar(1);
  // ITEM* item3 = item_criar(3);
  // ITEM* item4 = item_criar(5);
  // ITEM* item5 = item_criar(7);
  // ITEM* item6 = item_criar(6);
  // ITEM* item7 = item_criar(4);
  // abb_inserir(T, item1);
  // abb_inserir(T, item2);
  // abb_inserir(T, item3);
  // abb_inserir(T, item4);
  // abb_inserir(T, item5);
  // abb_inserir(T, item6);
  // abb_inserir(T, item7);
  // abb_remover(T, 2);
  // ITEM* it = abb_busca(T, 4);
  // item_imprimir(it);
  // abb_apagar(&T);


  ABB *T;
  int n, m, x, op;
  
  T = abb_criar();

  scanf("%d %d", &n, &m);

  for(int i = 0; i < n; i++){
    scanf("%d", &x);
    ITEM *item = item_criar(x);
    abb_inserir(T, item);
  }

  while(m--){
    scanf("%d", &op);

    switch(op){
      case 1: { //Busca
        int num;
        scanf("%d", &num);

        if(abb_busca(T, num) != NULL) printf("Item encontrado.\n");
        else printf("Item não encontrado.\n");
        
        break;
    }
      case 2: { //Remoção
        int num;
        scanf("%d", &num);
      
        if(abb_remover(T,num)) printf("Item removido.\n");
        else printf("Item não removido.\n");
      
        break;
      }
    }
  }
  
  abb_apagar(&T);

  return 0;
}
