#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "fila.h"

typedef struct no_ NO;

struct no_ {
  ITEM* item;
  NO* anterior;
};

struct fila_ {
  int tamanho;
  NO* frente;
  NO* fim;
};

FILA *fila_criar(void) {
  FILA* fila = (FILA*) malloc(sizeof(FILA));
  if (fila != NULL) {
    fila->tamanho = 0;
    fila->frente = NULL;
    fila->fim = NULL;
  }
  return fila;
}

bool fila_inserir(FILA *fila, ITEM *item) {
  if (fila == NULL || item == NULL || fila_cheia(fila)) return false;
  NO* novo_no = (NO*) malloc(sizeof(NO));
  if (novo_no == NULL) return false;
  novo_no->item = item;

  if (fila_vazia(fila)) {
    fila->fim = novo_no;
    fila->frente = novo_no;
  } else {
    NO* no_fim = fila->fim;
    no_fim->anterior = novo_no;
    fila->fim = novo_no;
  }
  fila->tamanho++;
  return true;
}

ITEM *fila_remover(FILA *fila) {
  if (fila == NULL || fila_vazia(fila)) return NULL;
  NO* no_frente = fila->frente;
  fila->frente = no_frente->anterior;
  ITEM* item = no_frente->item;
  free(no_frente);
  no_frente = NULL;
  fila->tamanho--;
  return item;
}

void fila_apagar(FILA **fila) {
  if (fila == NULL || *fila == NULL) return;
  if (!fila_vazia(*fila)) {
    FILA* f = *fila;
    NO* no_frente = f->frente;
    f->frente = no_frente->anterior;
    item_apagar(&(no_frente->item));
    free(no_frente);
    no_frente = NULL;
    f->tamanho--;
    fila_apagar(fila);
    return;
  }
  free(*fila);
  *fila = NULL;
  fila = NULL;
  return;
}


ITEM *fila_frente(FILA *fila) {
  if (fila == NULL || fila_vazia(fila)) return NULL;
  return fila->frente->item;
}

int fila_tamanho(FILA *fila) {
  if (fila == NULL) return ERRO;
  return fila->tamanho;
}

bool fila_vazia(FILA *fila) {
  if (fila == NULL) return false;
  return fila->tamanho == 0 ? true : false;
}

bool fila_cheia(FILA *fila) {
  if (fila == NULL) return false;
  NO* no_aux = (NO*)malloc(sizeof(NO));
  if (no_aux == NULL) return true;
  free(no_aux);
  return false;
}

void fila_imprimir(FILA *fila) {
  if (fila == NULL) return;
  item_imprimir(fila_frente(fila));
  return;  
}

void cartas(int n) {
  FILA* fila = fila_criar();
  FILA* fila_descartes = fila_criar();
  
  ITEM* item;
  for (int i = 1; i <= n; i++) {
    item = item_criar(i);
    fila_inserir(fila, item);
  }

  for (int j = 0; j < n; j++) {
    fila_inserir(fila_descartes, fila_remover(fila));
    fila_inserir(fila, fila_remover(fila));
  }

  printf("Discarded cards: ");
  for (int k = 0; k < n-1; k++) {
    ITEM* item_pop = fila_remover(fila_descartes);
    item_imprimir(item_pop);
    item_apagar(&item_pop);
  }
  ITEM* item_pop_remain = fila_remover(fila_descartes);
  item_imprimir(item_pop_remain);
  item_apagar(&item_pop_remain);
  printf("\n");
  printf("Remaining cards: ");

  for (int k = 0; k < n; k++) {
    ITEM* item_pop2 = fila_remover(fila);
    item_imprimir(item_pop2);
    item_apagar(&item_pop2);
  }
  printf("\n");

  fila_apagar(&fila);
  fila_apagar(&fila_descartes);
  return;
}
