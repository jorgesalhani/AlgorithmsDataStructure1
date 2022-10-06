#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila_ {
  ITEM* itens[MAX_ITENS];
  int tamanho;
  int inicio;
  int fim;
};

FILA* fila_criar() {
  FILA* fila = (FILA*) malloc(sizeof(FILA));
  if (fila != NULL) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
  }
  return fila;
}

bool fila_cheia(FILA* fila) {
  if (fila == NULL) return false;
  return fila->tamanho == MAX_ITENS ? true : false;
}

bool fila_vazia(FILA* fila) {
  if (fila == NULL) return false;
  return fila->tamanho == 0 ? true : false;
}

bool fila_inserir(FILA* fila, ITEM* item) {
  if (fila == NULL || item == NULL || fila_cheia(fila)) return false;
  (fila->itens)[fila->fim] = item;
  fila->tamanho++;
  fila->fim = (fila->fim + 1) % MAX_ITENS;
  return true;
}

ITEM* fila_frente(FILA* fila) {
  if (fila == NULL || fila_vazia(fila)) return NULL;
  return (fila->itens)[fila->inicio];
}

ITEM* fila_remover(FILA* fila) {
  if (fila == NULL || fila_vazia(fila)) return NULL;
  ITEM* item = (fila->itens)[fila->inicio];
  (fila->itens)[fila->inicio] = NULL;
  fila->tamanho--;
  fila->inicio = (fila->inicio + 1) % MAX_ITENS;
  return item;
}

void fila_completa_imprimir(FILA* fila) {
  if (fila == NULL || fila_vazia(fila)) return;
  int frente_i = fila->inicio;
  printf("FILA | <- ");
  do {
    printf("%d ", item_get_chave((fila->itens)[frente_i]));
    frente_i = (frente_i + 1) % MAX_ITENS;
  } while (frente_i != fila->fim);
  printf("\n");
  return;
}

void fila_imprimir(FILA* fila) {
  if (fila == NULL || fila_vazia(fila)) return;
  item_imprimir(fila_frente(fila));
  return;
}

bool fila_apagar(FILA** fila) {
  if (*fila == NULL) return false;
  if (!fila_vazia(*fila)) {
    free(fila_remover(*fila));
    fila_apagar(fila);
  } else {
    free(*fila);
    *fila = NULL;
    fila = NULL;
  }
  return true;
}
