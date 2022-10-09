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

/**
 * @author Jorge Augusto Salgado Salhani
 * @brief Descartar e modificar ordem de cartas em um baralho
 * 
 * O algoritmo de descarte e modificacao segue:
 * 1. Empilhar n cartas em sequencia, enumeradas 1 -> n
 * 2. Jogar fora a carta do topo da pilha
 * 3. Mover a proxima carta para a base da pilha (final da fila)
 * 
 * O algoritmo utilizado a seguir utiliza duas filas encadeadas.
 * A primeira fila eh responsavel por armazenar todas as n cartas em
 * sequencia. A segunda fila, armazena todas as cartas jogadas fora.
 * 
 * @param int n O numero de cartas que serao inseridas no baralho
 * @return void
*/
void cartas(int n) {

  // Criar duas filas
  FILA* fila = fila_criar();
  FILA* fila_descartes = fila_criar();
  
  // Inserir as n cartas informadas na fila <fila>
  ITEM* item;
  for (int i = 1; i <= n; i++) {
    item = item_criar(i);
    fila_inserir(fila, item);
  }

  // Para cada carta, remove-la da fila original <fila>
  // e inserir na fila de descartes <fila_descartes>
  // Em seguida, remanejar a proxima carta de <fila>
  // para a posicao final
  for (int j = 0; j < n-1; j++) {
    fila_inserir(fila_descartes, fila_remover(fila));
    fila_inserir(fila, fila_remover(fila));
  }

  // Resgatar as cartas de descarte, formatar a impressao
  // e liberar memoria do item (carta) removido
  printf("Discarded cards: ");
  for (int l = 0; l < n-1; l++) {
    ITEM* item_descarte = fila_remover(fila_descartes);
    printf("%d", item_get_chave(item_descarte));
    item_apagar(&item_descarte);
    if (l < n-2) printf(", ");
  }

  // Resgatar a carta remanescente da fila original <fila>
  // liberar a memoria e formatar a impressao
  printf("\nRemaining card: ");
  ITEM* item_pop2 = fila_remover(fila);
  printf("%d", item_get_chave(item_pop2));
  item_apagar(&item_pop2);
  printf("\n");

  // Liberar a memoria das filas vazias
  fila_apagar(&fila);
  fila_apagar(&fila_descartes);
  
  return;
}
