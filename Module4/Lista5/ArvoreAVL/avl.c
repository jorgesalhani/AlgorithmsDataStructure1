#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

// Estruturas abstratas de dados
// =============================

typedef struct no_ NO;
struct no_ {
  ITEM* item;
  NO* esq;
  NO* dir;
  int altura;
};

struct avl_ {
  NO* raiz;
  int profundidade;
};

// Funcoes auxiliares
// ==================

// Basicas

bool avl_existe_(AVL* T) {
  return (T != NULL) ? true : false;
}

bool no_existe_(NO* raiz) {
  return (raiz != NULL) ? true : false;
}

int avl_altura_no_(NO* raiz) {
  return (no_existe_(raiz)) ? raiz->altura : -1;
}

int avl_max_(int v1, int v2) {
  return (v1 > v2) ? v1 : v2;
}

// Auxiliares recursivas gerais AB

bool avl_apagar_aux_(NO** raiz) {
  if (raiz == NULL || !no_existe_(*raiz)) return false;

  avl_apagar_aux_(&((*raiz)->dir));
  avl_apagar_aux_(&((*raiz)->esq));

  item_apagar(&((*raiz)->item));
  free(*raiz);
  *raiz = NULL;
  return true;
}

NO* avl_criar_no_(ITEM* item) {
  NO* no = (NO*) malloc(sizeof(NO));
  if (no_existe_(no)) {
    no->item = item;
    no->altura = 0;
    no->dir = NULL;
    no->esq = NULL;
  }
  return no;
}

int avl_profundidade_(NO* raiz) {
  if (!no_existe_(raiz)) return -1;

  int profund_esq = avl_profundidade_(raiz->esq);
  int profund_dir = avl_profundidade_(raiz->dir);

  return avl_max_(profund_dir, profund_esq) + 1;
}

// Auxiliares especiais AVL

NO* avl_rotacionar_esquerda_(NO* raiz) {
  NO* b = raiz->dir;
  raiz->dir = b->esq;
  b->esq = raiz;

  int altura_no = avl_max_(avl_altura_no_(raiz->esq), avl_altura_no_(raiz->dir));
  raiz->altura = altura_no + 1;
  return b;
}

NO* avl_rotacionar_direita_(NO* raiz) {
  NO* b = raiz->esq;
  raiz->esq = b->dir;
  b->dir = raiz;

  int altura_no = avl_max_(avl_altura_no_(raiz->esq), avl_altura_no_(raiz->dir));
  raiz->altura = altura_no + 1;
  return b;
}

NO* avl_rotacionar_esq_dir_(NO* raiz) {
  raiz->esq = avl_rotacionar_esquerda_(raiz->esq);
  return avl_rotacionar_direita_(raiz);
}

NO* avl_rotacionar_dir_esq_(NO* raiz) {
  raiz->dir = avl_rotacionar_direita_(raiz->dir);
  return avl_rotacionar_esquerda_(raiz);
}

NO* avl_rotacionar_subarvore_(NO* raiz, ITEM* item) {
  if (avl_altura_no_(raiz->esq) - avl_altura_no_(raiz->dir) == -2) {
    if (item_get_chave(item) > item_get_chave(raiz->dir->item)) {
      raiz = avl_rotacionar_esquerda_(raiz);
    } else {
      raiz = avl_rotacionar_dir_esq_(raiz);
    }
  }

  if (avl_altura_no_(raiz->esq) - avl_altura_no_(raiz->dir) == 2) {
    if (item_get_chave(item) < item_get_chave(raiz->esq->item)) {
      raiz = avl_rotacionar_direita_(raiz);
    } else {
      raiz = avl_rotacionar_esq_dir_(raiz);
    }
  }

  return raiz;
}

NO* avl_inserir_aux_(NO* raiz, ITEM* item) {
  if (!no_existe_(raiz)) {
    raiz = avl_criar_no_(item);
  } else

  if (item_get_chave(item) < item_get_chave(raiz->item)) {
    raiz->esq = avl_inserir_aux_(raiz->esq, item);
  } else
  
  if (item_get_chave(item) > item_get_chave(raiz->item)) {
    raiz->dir = avl_inserir_aux_(raiz->dir, item);
  }

  int no_altura = avl_max_(avl_altura_no_(raiz->esq), avl_altura_no_(raiz->dir)) + 1;
  raiz->altura = no_altura;

  raiz = avl_rotacionar_subarvore_(raiz, item);

  return raiz;
}

// Funcoes de interface
// ====================

AVL* avl_criar() {
  AVL* T = (AVL*) malloc (sizeof(AVL));
  if (avl_existe_(T)) {
    T->raiz = NULL;
    T->profundidade = -1;
  }
  return T;
}

bool avl_apagar(AVL** T) {
  if (T == NULL) return false;
  
  if ((*T)->profundidade == -1) {
    item_apagar(&((*T)->raiz->item));
    free((*T)->raiz);
    (*T)->raiz = NULL;
  } else {
    avl_apagar_aux_(&(*T)->raiz);
  }

  free(*T);
  *T = NULL;
  
  return true;
}

bool avl_inserir(AVL* T, ITEM* item) {
  if (!avl_existe_(T) || item == NULL) return false;

  if (!no_existe_(T->raiz)) {
    NO* no = avl_criar_no_(item);
    if (!no_existe_(no)) return false;
    T->raiz = no;
  } else {
    avl_inserir_aux_(T->raiz, item);
    T->profundidade = avl_profundidade_(T->raiz);
  }
}

bool avl_remover(AVL* T, int chave) {

}
