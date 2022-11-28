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
  if (!no_existe_(raiz)) return NULL;

  if (item_get_chave(raiz->item) == chave) return raiz;
  
  if (ab_buscar_no_(raiz->esq, chave) == NULL) {
    ab_buscar_no_(raiz->dir, chave);
  };
}

void no_apagar_(NO** no) {
  if (no == NULL || !no_existe_(*no)) return;
  free(*no);
  *no = NULL;
  no = NULL;
}

bool ab_trocar_max_esq_(NO* troca, NO* raiz, NO* ascend) {
  if (no_existe_(troca->dir)) {
    ab_trocar_max_esq_(troca->dir, raiz, troca);
    return true;
  }

  if (raiz == ascend) ascend->esq = troca->esq;
  else ascend->dir = troca->esq;

  ITEM* item_raiz = raiz->item;
  item_apagar(&item_raiz);
  raiz->item = troca->item;
  no_apagar_(&troca);
  return true;
}

bool ab_remover_no_(NO** raiz) {
  if (no_existe_((*raiz)->dir) && no_existe_((*raiz)->esq)) return ab_trocar_max_esq_((*raiz)->esq, (*raiz), (*raiz));
  
  NO* raiz_aux = *raiz;
  if (no_existe_((*raiz)->esq)) *raiz = (*raiz)->esq;
  if (no_existe_((*raiz)->dir)) *raiz = (*raiz)->dir;

  free(raiz_aux);
  raiz_aux = NULL;
  return true;
}

bool ab_remover_aux_(NO** raiz, int chave) {
  if (!no_existe_(*raiz)) return false;
  if (item_get_chave((*raiz)->item) == chave) ab_remover_no_(raiz);
}

void ab_apagar_arvore_aux_(NO** raiz) {
  if (!no_existe_(*raiz)) return;

  ab_apagar_arvore_aux_(&((*raiz)->esq));
  ab_apagar_arvore_aux_(&((*raiz)->dir));

  if (!no_existe_((*raiz)->dir) && !no_existe_((*raiz)->esq)) {
    ITEM* item = (*raiz)->item;
    item_apagar(&item);
    no_apagar_(raiz);
    return;
  }
}

bool is_abb_aux_(NO* raiz) {
  if (!no_existe_(raiz)) return false;

  if (
    (no_existe_(raiz->dir) && item_get_chave(raiz->item) > item_get_chave(raiz->dir->item)) ||
    (no_existe_(raiz->esq) && item_get_chave(raiz->item) < item_get_chave(raiz->esq->item))
  ) return false;

  if (is_abb_aux_(raiz->esq) && is_abb_aux_(raiz->dir)) return true;
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
  if (!ab_existe_(T) || item == NULL) return false;

  NO* no = no_criar_(item);
  if (!no_existe_(no)) return false;

  if (!no_existe_(T->raiz)) {
    T->raiz = no;
  } else {
    NO* no_ascend = ab_buscar_no_(T->raiz, chave);
    if (!no_existe_(no_ascend)) return false;

    if (lado == 0) no_ascend->esq = no;
    else if (lado == 1) no_ascend->dir = no;
  }

  return true;
}

bool ab_remover(AB *T, int chave) {
  if (!ab_existe_(T)) return false;

  return ab_remover_aux_(&(T->raiz), chave);
}

void ab_apagar_arvore(AB **T) {
  if (T == NULL || !ab_existe_(*T)) return;
  ab_apagar_arvore_aux_(&((*T)->raiz));
  free(*T);
  *T = NULL;
  T = NULL;
}

bool is_abb(AB *T) {
  if (!ab_existe_(T)) return false;

  return is_abb_aux_(T->raiz);
}
