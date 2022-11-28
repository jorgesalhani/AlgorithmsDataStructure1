#include "ab.h"
#include <stdio.h>

int main(int argc, char *argv[]){ 
    
    // ITEM* item1 = item_criar(15);
    // ITEM* item2 = item_criar(13);
    // ITEM* item3 = item_criar(12);
    // ITEM* item4 = item_criar(11);
    // ITEM* item5 = item_criar(10);
    // ITEM* item6 = item_criar(9);

    // AB* T = ab_criar();
    // ab_inserir(T, item1, 0, 15);
    // ab_inserir(T, item2, 0, 15);
    // ab_inserir(T, item3, 0, 13);
    // ab_inserir(T, item4, 0, 12);
    // ab_inserir(T, item5, 0, 11);
    // ab_inserir(T, item6, 1, 10);

    // if (is_abb(T)) printf("ABB");
    // else printf("N ABB");

    // ab_apagar_arvore(&T);
    
    AB *A = ab_criar();

    int n, m;
    int a, b, c;

    scanf("%d", &n);

    while(n--){
        scanf("%d %d %d", &a, &b, &c);

        ITEM *item = item_criar(a);

        ab_inserir(A, item, b, c);
    }

    if(is_abb(A)) printf("É uma ABB.\n");
    else printf("Não é uma ABB.\n");

    ab_apagar_arvore(&A);
      	
    return (0);
}


