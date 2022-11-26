#include <stdio.h>
#include <stdlib.h>
#include "ab.h"

// Estrutura de dados
// ==================

typedef struct no_ NO; 
struct no_{
  ITEM *item;
  NO *esq;
  NO *dir;
};

struct ab_{ 
  NO *raiz;    
  int profundidade;
};

// Funcoes utils
// =============

bool ab_existe_(AB* ab) {
  return (ab != NULL) ? true : false;
}

bool item_existe_(ITEM* item) {
  return (item != NULL) ? true : false;
}

bool no_existe_(NO* no) {
  return (no != NULL) ? true : false;
}

NO* no_criar_(ITEM* item) {
  NO* no = (NO*) malloc(sizeof(NO));
  if (no_existe_(no)) {
    no->dir = NULL;
    no->esq = NULL;
    no->item = item;
  }
  return no;
}

NO* ab_buscar_no_(NO* raiz, int chave) {
  if (!no_existe_(raiz) || item_get_chave(raiz->item) == chave) return raiz;
  ab_buscar_no_(raiz->esq, chave);
  ab_buscar_no_(raiz->dir, chave);
}

void no_apagar_(NO** no) {
  if (no != NULL || !no_existe_(*no)) return;
  free(*no);
  *no = NULL;
  no = NULL;
}


bool ab_remover_aux_(NO** raiz, int chave) {

}

// Funcoes interface
// =================

AB *ab_criar(void) {
  AB* ab = (AB*) malloc(sizeof(AB));
  if (ab_existe_(ab)) {
    ab->raiz = NULL;
    ab->profundidade = -1;
  }
  return ab;
}

bool ab_inserir(AB *T, ITEM *item, int lado, int chave) {
  if (!ab_existe_(T) || !item_existe_(item)) return false;

  NO* no = no_criar_(item);
  if (!no_existe_(no)) return false;
  
  NO* no_ascend = ab_buscar_no_(T->raiz, chave);
  if (!no_existe_(no_ascend)) return false;

  if (lado == 0) no_ascend->esq = no;
  else if (lado == 1) no_ascend->dir = no;

  return true;
}

bool ab_remover(AB *T, int chave) {
  if (!ab_existe_(T)) return false;

  return ab_remover_aux_(&(T->raiz), chave);
}

void ab_apagar_arvore(AB **T) {

}

bool is_abb(AB *T) {

}
