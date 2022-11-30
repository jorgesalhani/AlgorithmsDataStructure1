#include "ab.h"
#include <stdio.h>

int main(int argc, char *argv[]){ 
    
    // ITEM* item1 = item_criar(50);
    // ITEM* item2 = item_criar(40);
    // ITEM* item3 = item_criar(60);
    // ITEM* item4 = item_criar(30);
    // ITEM* item5 = item_criar(70);
    // ITEM* item6 = item_criar(20);
    // // ITEM* item7 = item_criar(10);
    // // ITEM* item8 = item_criar(7);
    // // ITEM* item9 = item_criar(30);

    // AB* T = ab_criar();
    // ab_inserir(T, item1, 0, 50);
    // ab_inserir(T, item2, 0, 50);
    // ab_inserir(T, item3, 1, 50);
    // ab_inserir(T, item4, 0, 40);
    // ab_inserir(T, item5, 1, 60);
    // ab_inserir(T, item6, 0, 30);
    // // ab_inserir(T, item7, 1, 5);
    // // ab_inserir(T, item8, 0, 10);
    // // ab_inserir(T, item9, 0, 7);

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


