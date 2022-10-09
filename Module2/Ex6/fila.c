#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

typedef struct no_ NO;

struct no_ {
  ITEM* item;
  NO* anterior;
};

struct fila_ {
  int tamanho;
  NO* inicio;
  NO* fim;
};

// Funcoes utils 
// =============

bool _fila_existe(FILA* fila) {
  return fila != NULL ? true : false;
}

bool _no_existe(NO* no) {
  return no != NULL ? true : false;
}

void _fila_vazia_inserir(FILA* fila, NO* no) {
  fila->inicio = no;
  fila->fim = no;
  fila->tamanho++;
  return;
}

// Funcoes de Interface
// ====================

FILA *fila_criar(void) {
  FILA* fila = (FILA*) malloc(sizeof(FILA));
  if (_fila_existe(fila)) fila->tamanho = 0;
  return fila;
}

bool fila_inserir(FILA *fila, ITEM *item) {
  if (!_fila_existe(fila) || fila_cheia(fila) || item == NULL) return false;
  
  NO* novo_no = (NO*) malloc(sizeof(NO));
  if (!_no_existe(novo_no)) return false;
  novo_no->item = item;

  if (fila_vazia(fila)) {
    _fila_vazia_inserir(fila, novo_no);
    return true;
  }

  NO* no_final = fila->fim;
  no_final->anterior = novo_no;
  fila->fim = novo_no;
  fila->tamanho++;
  return true;
}

ITEM *fila_remover(FILA *fila) {
  if (!_fila_existe(fila) || fila_vazia(fila)) return NULL;
  
  NO* no_inicio = fila->inicio;
  fila->inicio = (fila->inicio)->anterior;

  ITEM* item_removido = no_inicio->item;
  
  free(no_inicio);
  no_inicio = NULL;
  fila->tamanho--;
  
  return item_removido;
}

void fila_apagar(FILA **fila) {
  if (fila == NULL || !_fila_existe(*fila)) return;
  if (fila_vazia(*fila)) {
    free(*fila);
    *fila = NULL;
    fila = NULL;
    return;
  }

  ITEM* item_removido = fila_remover(*fila);
  item_apagar(&item_removido);
  item_removido = NULL;
  fila_apagar(fila);
}


ITEM *fila_frente(FILA *fila) {
  if (!_fila_existe(fila) || fila_vazia(fila)) return NULL;
  return (fila->inicio)->item;
}

int fila_tamanho(FILA *fila) {
  return _fila_existe(fila) ? fila->tamanho : ERRO;
}

bool fila_vazia(FILA *fila) {
  return (_fila_existe(fila) && fila->tamanho == 0) ? true : false;
}

bool fila_cheia(FILA *fila) {
  NO* no_temp = (NO*) malloc(sizeof(NO));
  if (_no_existe(no_temp)) {
    free(no_temp);
    return false;
  }
  return true;
}

void fila_imprimir(FILA *fila) {
  if (!_fila_existe(fila) || fila_vazia(fila)) return;
  printf("FILA | %d\n", item_get_chave((fila->inicio)->item));
  return;
}

