#include "ab.h"

int main(int argc, char *argv[]){ 
    
    ITEM* item = item_criar(1);
    item_imprimir(item);
    item_apagar(&item);

    AB* T = ab_criar();
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


