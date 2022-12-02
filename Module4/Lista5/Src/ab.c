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

// Funcoes auxiliares
// ==================

bool ab_existe_(AB* T) {
  return (T != NULL) ? true : false;
}

bool no_existe_(NO* no) {
  return (no != NULL) ? true : false;
}

void ab_apagar_aux_(NO** raiz) {
  if (!no_existe_(*raiz)) return;

  ab_apagar_aux_(&(*raiz)->esq);
  ab_apagar_aux_(&(*raiz)->dir);

  item_apagar(&(*raiz)->item);
  free(*raiz);
  *raiz = NULL;
}

NO* ab_buscar_no_(NO* raiz, int chave) {
  if (!no_existe_(raiz)) return NULL;

  ab_buscar_no_(raiz->dir, chave);
  ab_buscar_no_(raiz->esq, chave);

  if (item_get_chave(raiz->item) == chave) return raiz;
}

NO* ab_criar_no_(ITEM* item) {
  if (item == NULL) return NULL;

  NO* no = (NO*) malloc(sizeof(NO));
  if (no_existe_(no)) {
    no->item = item;
    no->esq = NULL;
    no->dir = NULL;
  }
  return no;
}

// Funcoes interface
// =================

AB* ab_criar() {
  AB* T = (AB*) malloc (sizeof(AB*));
  if (ab_existe_(T)) {
    T->raiz = NULL;
    T->profundidade = -1;
  }
  return T;
}

bool ab_inserir(AB* T, ITEM* item, int lado, int chave) {
  if (!ab_existe_(T) || item == NULL) return false;
  NO* no_ascend = ab_buscar_no_(T->raiz, chave);
  if (!no_existe_(no_ascend)) return false;

  NO* no = ab_criar_no_(item);
  if (lado == DESC_DIR) no_ascend->dir = no;
  else
  if (lado == DESC_ESQ) no_ascend->esq = no;

  return true;
}

bool ab_apagar_arvore(AB** T) {
  if (T == NULL || ab_existe_(*T)) return false;
  ab_apagar_aux_(&(*T)->raiz);
  free(*T);
  *T = NULL;
  return true;
}
