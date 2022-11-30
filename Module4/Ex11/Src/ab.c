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

int abb_max_esq_(NO* raiz) {
  if (!no_existe_(raiz)) return 0;
  
  int max_esq = abb_max_esq_(raiz->esq);
  int max_dir = abb_max_esq_(raiz->dir);

  int max = max_esq;
  if (max_esq < max_dir) max = max_dir;
  if (item_get_chave(raiz->item) > max) max = item_get_chave(raiz->item);

  return max;
}

int abb_min_dir_(NO* raiz) {
  if (!no_existe_(raiz)) return 0;

  int min_esq = abb_min_dir_(raiz->esq);
  int min_dir = abb_min_dir_(raiz->dir);

  int min = item_get_chave(raiz->item);
  if (min_esq != 0 && min_esq < min_dir) min = min_esq;
  if (item_get_chave(raiz->item) < min) min = item_get_chave(raiz->item);

  return min;
}

bool is_abb_aux_(NO* raiz) {
  if (!no_existe_(raiz)) return false;

  int max_esq = abb_max_esq_(raiz->esq);
  int min_dir = abb_min_dir_(raiz->dir);

  if (max_esq > item_get_chave(raiz->item)) return false;
  if (min_dir < item_get_chave(raiz->item)) return false;

  return true;
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

/**
 * @author Jorge Augusto Salgado Salhani
 * @brief Funcao que verifica se dada AB e' ABB
 * 
 * ABB: 
 *  1. maior no da subarvore esquerda deve ser menor
 *     que o no raiz
 *  2. menor no da subarvore direita deve ser maior
 *     que o no raiz
 * 
 * Para cada no raiz, armazenamos seu menor no esquerdo
 * e seu maior no direito. Se satisfizer 1 e 2, e' ABB
 * 
 * @param AB* Ponteiro para a raiz da arvore AB (TAD AB)
 * @return bool Se ABB, true. Caso contrario, false
*/
bool is_abb(AB *T) {
  if (!ab_existe_(T)) return false;

  bool verificado = true;
  return (verificado = is_abb_aux_(T->raiz));
}
