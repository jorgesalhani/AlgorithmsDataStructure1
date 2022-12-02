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

  if (item_get_chave(raiz->item) == chave) return raiz;

  if (ab_buscar_no_(raiz->dir, chave) == NULL) {
    ab_buscar_no_(raiz->esq, chave);
  }
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

int ab_profundidade_(NO* raiz) {
  if (!no_existe_(raiz)) return -1;

  int e = ab_profundidade_(raiz->esq);
  int d = ab_profundidade_(raiz->dir);
  int max = (e > d) ? e : d;
  return max + 1;
}

int ab_soma_conteudo_aux_(NO* raiz) {
  if (!no_existe_(raiz)) return 0;
  int soma = item_get_chave(raiz->item);
  soma += ab_soma_conteudo_aux_(raiz->esq);
  soma += ab_soma_conteudo_aux_(raiz->dir);

  return soma;
}

int ab_total_nos_aux_(NO* raiz) {
  if (!no_existe_(raiz)) return 0;
  
  int total_nos = 1;
  total_nos += ab_total_nos_aux_(raiz->esq);
  total_nos += ab_total_nos_aux_(raiz->dir);

  return total_nos;
}

bool ab_estrita_aux_(NO* raiz) {
  if (!no_existe_(raiz)) return false;

  ab_estrita_aux_(raiz->dir);
  ab_estrita_aux_(raiz->esq);

  if ((!no_existe_(raiz->dir) && !no_existe_(raiz->esq)) ||
      (no_existe_(raiz->dir) && no_existe_(raiz->esq))) {
    return true;
  }
}

// Funcoes interface
// =================

AB* ab_criar() {
  AB* T = (AB*) malloc (sizeof(AB));
  if (ab_existe_(T)) {
    T->raiz = NULL;
    T->profundidade = -1;
  }
  return T;
}

bool ab_inserir(AB* T, ITEM* item, int lado, int chave) {
  if (!ab_existe_(T) || item == NULL) return false;

  NO* no = ab_criar_no_(item);
  if (no_existe_(no) && !no_existe_(T->raiz)) {
    T->raiz = no;
    return true;
  }

  NO* no_ascend = ab_buscar_no_(T->raiz, chave);
  if (!no_existe_(no_ascend)) return false;

  if (lado == DESC_DIR) no_ascend->dir = no;
  else
  if (lado == DESC_ESQ) no_ascend->esq = no;

  T->profundidade = ab_profundidade_(T->raiz);

  return true;
}

bool ab_apagar_arvore(AB** T) {
  if (T == NULL) return false;
  if (ab_existe_(*T)) {
    ab_apagar_aux_(&(*T)->raiz);
  }
  free(*T);
  *T = NULL;
  return true;
}

// Funcoes especiais
// =================

int ab_profundidade(AB* T) {
  if (ab_existe_(T)) return T->profundidade;
}

int ab_soma_conteudo(AB* T) {
  if (!ab_existe_(T) || !no_existe_(T->raiz)) return -1;

  return ab_soma_conteudo_aux_(T->raiz);
}

int ab_total_nos(AB* T) {
  if (!ab_existe_(T) || !no_existe_(T->raiz)) return -1;

  return ab_total_nos_aux_(T->raiz);
}

bool ab_estrita(AB* T) {
  if (!ab_existe_(T));

  return ab_estrita_aux_(T->raiz);
}