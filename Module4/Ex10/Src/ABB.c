#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "ABB.h"

typedef struct No NO; 
struct No{
  ITEM *item;
  NO *esq;
  NO *dir;
};

struct abb_{ 
  NO *raiz;    
  int profundidade;
};

// Funcoes utilitarias
// ===================

bool abb_existe_(ABB* abb) {
  return abb != NULL ? true : false;
}

bool no_existe_(NO* no) {
  return no != NULL ? true : false;
}

NO* abb_criar_no(ITEM* item) {
  NO* no = (NO*) malloc(sizeof(NO));
  if (no_existe_(no)) {
    no->item = item;
    no->dir = NULL;
    no->esq = NULL;
  }
  return no;
}

NO* abb_inserir_no_aux(NO* no, ITEM* item) {
  if (item == NULL) return NULL;

  if (no_existe_(no)) {
    no = abb_criar_no(item);
  } else 
  if (item_get_chave(item) < item_get_chave(no->item)) {
    no->esq = abb_inserir_no_aux(no->esq, item);
  } else
  if (item_get_chave(item) > item_get_chave(no->item)) {
    no->dir = abb_inserir_no_aux(no->dir, item);
  }

  return no;
}

void abb_imprimir_aux(NO* no) {
  if (no_existe_(no)) {
    item_imprimir(no->item);
    abb_imprimir_aux(no->esq);
    abb_imprimir_aux(no->dir);
  }
}

void abb_apagar_aux(NO** no) {
  if (no_existe_(*no)) {
    abb_apagar_aux(&(*no)->esq);
    abb_apagar_aux(&(*no)->dir);
    item_apagar(&(*no)->item);
    free(*no);
    *no = NULL;
  }
}

void troca_max_esq(NO* troca, NO* no, NO* anterior) {
  if (no_existe_(troca->dir)) {
    troca_max_esq(troca->dir, no, troca);
    return;
  }

  if (no == anterior) anterior->esq = troca->esq;
  else anterior->dir = troca->esq;

  no->item = troca->item;
  free(troca);
  troca = NULL;
}

bool abb_remover_aux(NO** no, int chave) {
  if (!no_existe_(*no)) return NULL;
  NO* no_aux = NULL;

  if (chave == item_get_chave((*no)->item)) {
    if (!no_existe_((*no)->esq) || !no_existe_((*no)->dir)) {
      no_aux = *no;
      
      if (!no_existe_((*no)->esq)) {
        *no = (*no)->dir;
      } else 
      if (!no_existe_((*no)->dir)) {
        *no = (*no)->esq;
      }
      
      free(no_aux);
      no_aux = NULL;
      
    } else {
      troca_max_esq((*no)->esq, (*no), (*no));
    }

    return true;
  } else {
    if (chave < item_get_chave((*no)->item)) {
      return abb_remover_aux(&(*no)->esq, chave);
    } else {
      return abb_remover_aux(&(*no)->dir, chave);
    }
  }
}

ITEM* abb_busca_aux(NO* no, int chave) {
  if (!no_existe_(no)) return NULL;
  if (chave == item_get_chave(no->item)) {
    return no->item;
  }

  if (chave < item_get_chave(no->item)) {
    return abb_busca_aux(no->esq, chave);
  } else {
    return abb_busca_aux(no->dir, chave);
  }
}

// Funcoes de interface
// ====================

ABB *abb_criar (void) {
  ABB* abb = (ABB*) malloc(sizeof(ABB));
  if (abb_existe_(abb)) {
    abb->profundidade = -1;
    abb->raiz = NULL;
  }
  return abb;
}

bool abb_inserir (ABB *T, ITEM *item) {
  if (!abb_existe_(T) || item == NULL) return false;
  NO* no = abb_inserir_no_aux(T->raiz, item);
  return no_existe_(no);
}

void abb_imprimir (ABB *T) {
  if (abb_existe_(T)) {
    abb_imprimir_aux(T->raiz);
  }
}

void abb_apagar (ABB **T) {
  if (T == NULL || abb_existe_(*T)) return;
  abb_apagar_aux((*T)->raiz);
  free(*T);
  *T = NULL;
  T = NULL;
  return;
}

bool abb_remover(ABB *T, int chave) {
  if (abb_existe_(T)) {
    return abb_remover_aux(&(T->raiz), chave);
  } 
  return false;
} 

ITEM *abb_busca(ABB *T, int chave) {
  if (!abb_existe_(T)) return NULL;
  return abb_busca_aux(T->raiz, chave);
}

bool abb_vazia(ABB *T) {
  return (abb_existe_(T) && no_existe_(T->raiz)) ? true : false;
}
