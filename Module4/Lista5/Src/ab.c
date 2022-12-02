#include <stdio.h>
#include <stdlib.h>
#include "ab.h"

typedef struct no_ NO;

struct no_ {
  ITEM* item;
  NO* esq;
  NO* dir;
};

struct ab_ {
  NO* raiz;
  int profundidade;
};

AB* ab_criar() {
  AB* T = (AB*) malloc (sizeof(AB*));
  
}

bool ab_inserir(AB* T, ITEM* item, int lado, int chave) {

}

bool ab_remover(AB* T, int chave) {

}

bool ab_apagar_arvore(AB** T) {

}
