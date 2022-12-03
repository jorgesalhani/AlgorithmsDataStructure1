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

bool avl_existe_(AVL* T) {
  return (T != NULL) ? true : false;
}

bool no_existe_(NO* raiz) {
  return (raiz != NULL) ? true : false;
}

bool avl_apagar_aux_(NO** raiz) {
  if (raiz == NULL || !no_existe_(*raiz)) return false;

  
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
  if (T == NULL || avl_existe_(*T)) return false;

  if (!no_existe_((*T)->raiz)) return false;
  return avl_apagar_aux_(&(*T)->raiz);
}

bool avl_inserir(AVL* T) {

}

bool avl_remover(AVL* T, int chave) {

}
