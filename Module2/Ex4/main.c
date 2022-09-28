#include "Pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include "item.h"

int main(int argc, char *argv[]){
   char str_sequencia[105];

   ITEM* item = item_criar(20.3);
   item_imprimir(item);
   PILHA* pilha = pilha_criar();
   pilha_empilhar(pilha, item);
   pilha_print(pilha);
   ITEM* item1 = item_criar(480.3);
   pilha_empilhar(pilha, item1);
   pilha_print(pilha);
   pilha_apagar(&pilha);
   // item_apagar(&item);

   // while(scanf("%s", str_sequencia) != EOF){
   //    float resultado = rpn(str_sequencia);

   //    printf("%.2f\n", resultado);
   // }    

   return 0;
}