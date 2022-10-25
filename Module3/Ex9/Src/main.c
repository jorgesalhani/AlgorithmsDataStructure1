#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main(int argc, char *argv[]){ 
    int n, m, num;

    LISTA *lista = lista_criar();
    ITEM* item1 = item_criar(1);
    lista_inserir(lista, item1);

    lista_apagar(&lista);

    // scanf("%d", &n);

    // while(n--){
    //     scanf("%d", &num);
    //     ITEM *item = item_criar(num);

    //     lista_inserir(lista, item);
    // }

    // lista_inverter(&lista);
    // lista_imprimir(lista);
    // lista_apagar(&lista);
   	
    return (0);
}


