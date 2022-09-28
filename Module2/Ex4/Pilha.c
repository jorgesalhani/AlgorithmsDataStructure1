#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

struct pilha {
  ITEM* itens[TAM];
  int topo;
};

PILHA *pilha_criar(void) {
  PILHA* pilha = (PILHA*) malloc(sizeof(PILHA));
  if (pilha != NULL) pilha->topo = 0;
  return pilha;
}

void pilha_apagar(PILHA **pilha) {
  if (*pilha == NULL) return;
  if (pilha_vazia(*pilha)) {
    free((*pilha)->itens);
    *pilha = NULL;
    return;
  }
  free(pilha_desempilhar(*pilha));
  pilha_apagar(pilha);
}

bool pilha_vazia(PILHA *pilha) {
  if (pilha == NULL) return false;
  return pilha->topo == 0 ? true : false;
}

bool pilha_cheia(PILHA *pilha) {
  if (pilha == NULL) return false;
  return pilha->topo == TAM ? true : false;
}

int pilha_tamanho(PILHA *pilha) {
  if (pilha == NULL) return 404404;
  return pilha->topo;
}

ITEM *pilha_topo(PILHA *pilha) {
  if (pilha == NULL) return NULL;
  return pilha->itens[pilha->topo - 1];
}

bool pilha_empilhar(PILHA *pilha, ITEM *item) {
  if (pilha == NULL || item == NULL || pilha_cheia(pilha)) return false;
  pilha->itens[pilha->topo] = item;
  pilha->topo++;
  return true;
}

ITEM *pilha_desempilhar(PILHA *pilha) {
  if (pilha == NULL || pilha_vazia(pilha)) return NULL;
  ITEM* item = pilha_topo(pilha);
  pilha->itens[pilha->topo - 1] = NULL;
  pilha->topo--;
  return item;
}

void pilha_print(PILHA *p) {
  if (p == NULL || pilha_vazia(p)) return;
  item_imprimir(pilha_topo(p));
  return;
} 

float rpn(char *sequencia) {

}

