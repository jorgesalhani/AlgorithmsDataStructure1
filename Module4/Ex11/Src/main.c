#include "ab.h"

int main(int argc, char *argv[]){ 
    
    ITEM* item1 = item_criar(1);
    ITEM* item2 = item_criar(2);
    ITEM* item3 = item_criar(3);
    ITEM* item4 = item_criar(4);
    ITEM* item5 = item_criar(5);
    ITEM* item6 = item_criar(6);

    AB* T = ab_criar();
    ab_inserir(T, item1, 0, 1);
    ab_inserir(T, item2, 0, 1);
    ab_inserir(T, item3, 1, 2);
    ab_inserir(T, item4, 0, 2);
    ab_inserir(T, item5, 1, 4);
    ab_inserir(T, item6, 0, 5);
    ab_apagar_arvore(&T);
    
    // AB *A = ab_criar();

    // int n, m;
    // int a, b, c;

    // scanf("%d", &n);

    // while(n--){
    //     scanf("%d %d %d", &a, &b, &c);

    //     ITEM *item = item_criar(a);

    //     ab_inserir(A, item, b, c);
    // }

    // if(is_abb(A)) printf("É uma ABB.\n");
    // else printf("Não é uma ABB.\n");

    // ab_apagar_arvore(&A);
      	
    return (0);
}


