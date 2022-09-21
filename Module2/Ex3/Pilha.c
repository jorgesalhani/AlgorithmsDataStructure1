#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "Pilha.h"

struct pilha {
  ITEM *item[TAM];
  int tamanho;
};

PILHA* pilha_criar(void) {
  PILHA *pilha = (PILHA*) malloc(sizeof(PILHA));
  if (pilha == NULL) return NULL;
  pilha->tamanho = 0;
  return pilha;
}

void pilha_apagar(PILHA** pilha) {
  PILHA* p = *pilha;
  if (p == NULL) return;
  if (pilha_vazia(p)) {
    free(p->item);
    return;
  }
  free(pilha_desempilhar(p));
  pilha_apagar(pilha);
}

bool pilha_vazia(PILHA* pilha) {
  if (pilha == NULL) return false;
  return (pilha->tamanho == 0) ? true : false;
}

bool pilha_cheia(PILHA* pilha) {
  if (pilha == NULL) return false;
  return (pilha->tamanho == TAM) ? true : false;
}

int pilha_tamanho(PILHA* pilha) {
  if (pilha == NULL) return ERRO;
  return pilha->tamanho;
}

ITEM* pilha_topo(PILHA* pilha) {
  if (pilha == NULL) return NULL;
  return (pilha->item)[pilha->tamanho - 1];
}

bool pilha_empilhar(PILHA* pilha, ITEM* item) {
  if (pilha == NULL || item == NULL || pilha_cheia(pilha)) return false;
  (pilha->item)[pilha->tamanho] = item;
  pilha->tamanho++;
  return true;
}

ITEM* pilha_desempilhar(PILHA* pilha) {
  if (pilha == NULL || pilha_vazia(pilha)) return NULL;
  ITEM* item = pilha_topo(pilha);
  (pilha->item)[pilha->tamanho - 1] = NULL;
  pilha->tamanho--;
  return item;
}

void pilha_print(PILHA* p) {
  if (p == NULL || pilha_vazia(p)) return;
  item_imprimir(pilha_topo(p));
}

bool balanceada(char *sequencia) {
  char c = sequencia[0];
  int i = 1;
  PILHA *pilha_parenteses = pilha_criar();
  PILHA *pilha_colchetes = pilha_criar();
  PILHA *pilha_chaves = pilha_criar();
  while (c != '\0') {
    ITEM *item = item_criar(c);
    switch (c) {
      case '(':
        pilha_empilhar(pilha_parenteses, item);
        pilha_print(pilha_parenteses);
        break;
      case ')':
        pilha_desempilhar(pilha_parenteses);
        pilha_print(pilha_parenteses);
        break;
      case '[':
        pilha_empilhar(pilha_colchetes, item);
        pilha_print(pilha_colchetes);
        break;
      case ']':
        pilha_desempilhar(pilha_colchetes);
        pilha_print(pilha_colchetes);
        break;
      case '{':
        pilha_empilhar(pilha_chaves, item);
        pilha_print(pilha_chaves);
        break;
      case '}':
        pilha_desempilhar(pilha_chaves);
        pilha_print(pilha_chaves);
        break;
    }
    item_apagar(&item);
    c = sequencia[i];
    i++;
  }
  pilha_tamanho(pilha_parenteses);
  pilha_tamanho(pilha_colchetes);
  pilha_tamanho(pilha_chaves);
  pilha_apagar(&pilha_parenteses);
  pilha_apagar(&pilha_colchetes);
  pilha_apagar(&pilha_chaves);
  return true;
}
