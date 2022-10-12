#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

typedef struct no_ NO;

struct no_ {
  ITEM* item;
  NO* no_anterior;
  NO* no_proximo;
};

struct deque_ {
  NO* inicio;
  NO* fim;
  int tamanho;
};

// Fucnoes utilitarias
// ===================

bool deque_existe_(DEQUE* deque) {
  return (deque != NULL) ? true : false;
}

bool no_existe_(NO* no) {
  return (no != NULL) ? true : false;
}

NO* no_criar_(ITEM* item) {
  NO* no = (NO*) malloc(sizeof(NO));
  if (item != NULL && no_existe_(no)) no->item = item;
  return no; 
}

bool inserir_primeiro_no_(DEQUE* deque, NO* no) {
  deque->fim = no;
  deque->inicio = no;
  deque->tamanho++;
  return true;
}

// Funcoes de interface
// ====================

DEQUE* deque_criar(void) {
  DEQUE* deque = (DEQUE*) malloc(sizeof(DEQUE));
  if (deque_existe_(deque)) {
    deque->tamanho = 0;
    deque->inicio = NULL;
    deque->fim = NULL;
  }
  return deque;
}

bool deque_apagar(DEQUE** deque) {
  if (deque == NULL || !deque_existe_(*deque)) return false;
  
  if (deque_vazio(*deque)) {
    free(*deque);
    *deque = NULL;
    deque = NULL;
    return true;
  }

  ITEM* item_removido = deque_remover_inicio(*deque);
  item_apagar(&item_removido);
  return deque_apagar(deque);
}

bool deque_inserir_fim(DEQUE* deque, ITEM* item) {
  if (!deque_existe_(deque) || item == NULL || deque_cheio(deque)) return false;

  NO* novo_no = no_criar_(item);
  if (!no_existe_(novo_no)) return false;

  if (deque_vazio(deque)) {
    return inserir_primeiro_no_(deque, novo_no);
  }

  novo_no->no_anterior = deque->fim;
  deque->fim->no_proximo = novo_no;
  deque->fim = novo_no;

  deque->tamanho++;
}

bool deque_inserir_inicio(DEQUE* deque, ITEM* item) {
  if (!deque_existe_(deque) || item == NULL || deque_cheio(deque)) return false;

  NO* novo_no = no_criar_(item);
  if (!no_existe_(novo_no)) return false;

  if (deque_vazio(deque)) {
    return inserir_primeiro_no_(deque, novo_no);
  }

  novo_no->no_proximo = deque->inicio;
  deque->inicio->no_anterior = novo_no;
  deque->inicio = novo_no;

  deque->tamanho++;
}

ITEM* deque_remover_fim(DEQUE* deque) {
  if (!deque_existe_(deque) || deque_vazio(deque)) return NULL;

  NO* no_removido = deque->fim;
  deque->fim = no_removido->no_anterior;
  no_removido->no_anterior = NULL;
  deque->fim->no_proximo = NULL;

  ITEM* item = no_removido->item;
  free(no_removido);
  no_removido = NULL;

  deque->tamanho--;

  return item;
                                          }

ITEM* deque_remover_inicio(DEQUE* deque) {
  if (!deque_existe_(deque) || deque_vazio(deque)) return NULL;

  NO* no_removido = deque->inicio;
  ITEM* item = no_removido->item;

  if (deque->inicio != deque->fim) {
    deque->inicio = no_removido->no_proximo;
    no_removido->no_proximo = NULL;
    deque->inicio->no_anterior = NULL;

    item = no_removido->item;
  }

  free(no_removido);
  no_removido = NULL;

  deque->tamanho--;

  return item;
}

void deque_imprimir_inicio(DEQUE* deque) {
  if (!deque_existe_(deque) || deque_vazio(deque)) return;
  printf("DEQUE inicio || %d", item_get_chave(deque->inicio->item));
  return;
}

void deque_imprimir_fim(DEQUE* deque) {
  if (!deque_existe_(deque) || deque_vazio(deque)) return;
  printf("%d || fim DEQUE", item_get_chave(deque->fim->item));
  return;
}

bool deque_vazio(DEQUE* deque) {
  return (deque_existe_(deque) && deque->tamanho == 0) ? true : false;
}

bool deque_cheio(DEQUE* deque) {
  if (!deque_existe_(deque)) return false;
  
  bool cheio = false;

  ITEM* item_temp = item_criar(0);
  NO* no_temp = no_criar_(item_temp);

  if (!no_existe_(no_temp)) cheio = true;

  item_apagar(&item_temp);
  free(no_temp);
  return cheio;
}

int deque_tamanho(DEQUE* deque) {
  return (deque_existe_(deque)) ? deque->tamanho : ERRO;
}

void deque_inverter_extremos(DEQUE* deque) {
  if (!deque_existe_(deque) || deque_vazio(deque)) return;
  NO* no_inicio_temp = deque->inicio;
  deque->fim->no_anterior->no_proximo = no_inicio_temp;
  no_inicio_temp->no_anterior = deque->fim->no_anterior;
  deque->fim->no_proximo = deque->inicio->no_proximo;
  deque->inicio->no_proximo->no_anterior = deque->fim;
  deque->inicio = deque->fim;
  deque->fim = no_inicio_temp;
  deque->fim->no_proximo = NULL;
  deque->inicio->no_anterior = NULL;
  return;
}