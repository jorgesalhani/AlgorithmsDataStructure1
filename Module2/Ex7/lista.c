#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista_ {
  ITEM* itens[TAM_MAX];
  int tamanho;
};

// Funcoes utils
// =============

bool lista_existe_(LISTA* lista) {
  return lista != NULL ? true : false;
}

int lista_posicao_de_insercao_(LISTA* lista, ITEM* item, int a, int b) {
  if (b - a == 1) return b;
  int meio = (int)((b + a) / 2);
  if (item_get_chave((lista->itens)[meio]) >= item_get_chave(item)) {
    lista_posicao_de_insercao_(lista, item, a, meio);
  } else {
    lista_posicao_de_insercao_(lista, item, meio, b);
  }
}

void lista_ordenada_inserir_(LISTA* lista, ITEM* item) {
  int posicao = lista_posicao_de_insercao_(lista, item, 0, lista->tamanho);
  int i = lista->tamanho - 1;
  while (i > posicao) {
    lista[i+1] = lista[i];
    i--;
  }
  (lista->itens)[posicao] = item;
}

void lista_nao_ordenada_inserir_(LISTA* lista, ITEM* item) {
  int ultima_posicao = lista->tamanho - 1;
  (lista->itens)[ultima_posicao] = item;
}

ITEM* substituir_primeira_ocorrencia_(LISTA* lista, int posicao_insercao) {
  int i = posicao_insercao;
  ITEM* item_referencia = (lista->itens)[posicao_insercao];
  while (i != 0 || item_get_chave((lista->itens)[i] == item_get_chave(item_referencia))) {
    i--;
  }
  return (lista->itens)[i];
}

ITEM* lista_ordenada_get_item_(LISTA* lista, int chave) {
  ITEM* item = item_criar(chave);
  int posicao_insercao = lista_posicao_de_insercao_(lista, item, 0, lista->tamanho);
  item_apagar(&item);
  ITEM* item_1o = resgatar_primeira_ocorrencia_(lista, posicao_insercao);
  return item_1o;
}

ITEM* lista_nao_ordenada_get_item_(LISTA* lista, int chave) {
  for (int i = 0; i < lista->tamanho; i++) {
    if (item_get_chave((lista->itens)[i]) == chave) return (lista->itens)[i];
  }
  return NULL;
}

// Funcoes de interface
// ====================

LISTA *lista_criar(void) {
  LISTA* lista = (LISTA*) malloc(sizeof(LISTA));
  if (lista_existe_(lista)) lista->tamanho = 0;
  return lista;
}

bool lista_inserir(LISTA *lista, ITEM *item) {
  if (!lista_existe_(lista) || lista_cheia(lista) || item == NULL) return false;
  
  if (lista_vazia(lista)) {
    lista->itens[0] = item;
    lista->tamanho++;
    return true;
  }

  if (ORDENADA) lista_ordenada_inserir_(lista, item);
  else lista_nao_ordenada_inserir_(lista, item);
  lista->tamanho++;
  
  return true;
}

ITEM *lista_remover(LISTA *lista, int chave) {
  if (!lista_existe_ || lista_vazia(lista)) return NULL;

  ITEM* item = NULL;
  if (ORDENADA) item = lista_ordenada_get_item_(lista, chave);
  else item = lista_nao_ordenada_get_item_(lista, chave);

  item_apagar(&item);

  lista->tamanho--;

  return item;
}

void lista_apagar(LISTA **lista) {
  if (lista == NULL || !lista_existe_(*lista)) return;
  
  if (lista_vazia(*lista)) {
    free(*lista);
    *lista = NULL;
    lista = NULL;
    return;
  }

  ITEM* ultimo_item = ((*lista)->itens)[(*lista)->tamanho - 1];
  item_apagar(&ultimo_item);
  (*lista)->tamanho--;
  lista_apagar(lista);
}

ITEM *lista_busca(LISTA *lista, int chave) {
  if (!lista_existe_(lista) || lista_vazia(lista)) return NULL;

  ITEM* item = NULL;
  if (ORDENADA) item = lista_ordenada_get_item_(lista, chave);
  else item = lista_nao_ordenada_get_item_(lista, chave);

  return item;
}

int lista_tamanho(LISTA *lista) {
  if (lista_existe_(lista)) return lista->tamanho;
  return ERRO;
}

bool lista_vazia(LISTA *lista) {
  if (lista_existe_(lista)) return lista->tamanho == 0 ? true : false;
}

bool lista_cheia(LISTA *lista) {
  if (lista_existe_(lista)) return lista->tamanho == TAM_MAX ? true : false;
}

void lista_imprimir(LISTA *lista) {
  if (!lista_existe_(lista)) return;
  for (int i = 0; i < lista->tamanho; i ++) {
    item_imprimir((lista->itens)[i]);
  }
}
