#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main(int argc, char *argv[]){ 
    int n, m, num;

    LISTA *lista = lista_criar();

    // scanf("%d", &n);
    n = 10;
    int l[10] = {1, 1, 3, 4, 5, 6, 7, 8, 9, 10};
    int i = 0;
    while(n--){
        // scanf("%d", &num);
        ITEM *item = item_criar(l[i]);
        i++;
        lista_inserir(lista, item);
    }

    lista_inverter(&lista);
    lista_imprimir(lista);
    lista_apagar(&lista);
   	
    return (0);
}


