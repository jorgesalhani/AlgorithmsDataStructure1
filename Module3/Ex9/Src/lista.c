#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct no_ NO; 

struct no_{
  ITEM *item;
  NO *proximo;
};

struct lista_{ 
  NO *inicio;
  NO *fim;    
  int tamanho;  /*tamanho da lista*/
};

// Funcoes auxiliares
// ==================

bool lista_existe_(LISTA* lista) {
  return (lista != NULL) ? true : false;
}

bool no_existe_(NO* no) {
  return (no != NULL) ? true : false;
}

NO* lista_buscar_no_anterior_(NO* no, int chave) {
  if (!no_existe_(no->proximo)) return NULL;
  if (item_get_chave(no->proximo->item) == chave) return no;
  lista_buscar_no_anterior_(no->proximo, chave);
}

bool lista_buscar_no_inicio_(NO* no_inicio, int chave) {
  if (!no_existe_(no_inicio)) return false;
  if (item_get_chave(no_inicio->item) == chave) return true;
  return false;
}

void lista_apagar_aux(LISTA* lista) {
  if (lista_vazia(lista)) return;
  lista_remover(lista, item_get_chave(lista->inicio->item));
}

void lista_imprimir_aux(NO* no) {
  if (!no_existe_(no)) return;
  item_imprimir(no->item);
  lista_imprimir_aux(no->proximo);
}

// Funcoes de interface
// ====================

LISTA *lista_criar(void) {
  LISTA* lista = (LISTA*) malloc(sizeof(LISTA));
  if (lista_existe_(lista)) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
  }
  return lista;
}

bool lista_inserir(LISTA *lista, ITEM *item) {
  if (!lista_existe_(lista) || lista_cheia(lista) || item == NULL) return false;
  
  NO* no = (NO*) malloc(sizeof(NO));
  if (!no_existe_(no)) return false;
  
  no->item = item;
  no->proximo = NULL;

  if (lista_vazia(lista)) {
    lista->inicio = no;
    lista->fim = no;
  } else {
    no->proximo = lista->inicio;
    lista->inicio = no;
  }
  lista->tamanho++;

  return true;
}

ITEM *lista_remover(LISTA *lista, int chave) {
  if (!lista_existe_(lista) || lista_vazia(lista)) return NULL;
  
  NO* no_cursor = NULL;
  ITEM* item = NULL;

  bool no_inicio = lista_buscar_no_inicio_(lista->inicio, chave);

  if (no_inicio) {
    no_cursor = lista->inicio;
    lista->inicio->proximo = no_cursor->proximo;
    item = no_cursor->item;
    free(no_cursor);
    no_cursor = NULL;
    return item;
  }
  
  NO* no_anterior = lista_buscar_no_anterior_(lista->inicio, chave);

  if (!no_existe_(no_anterior)) return NULL;

  no_cursor = no_anterior->proximo;
  if (!no_existe_(no_cursor->proximo)) {
    no_anterior->proximo = NULL;
  } else {
    no_anterior->proximo = no_cursor->proximo;
  }

  item = no_cursor->item;
  free(no_cursor);
  no_cursor = NULL;

  return item;
}

bool lista_apagar(LISTA **lista) {
  if (lista == NULL || !lista_existe_(*lista)) return false;
  lista_apagar_aux(*lista);
  free(*lista);
  *lista = NULL;
  lista = NULL;
  return true;
}

ITEM *lista_busca(LISTA *lista, int chave) {

}

int lista_tamanho(LISTA *lista) {
  if (lista_existe_(lista)) return lista->tamanho;
  return -40404;
}

bool lista_vazia(LISTA *lista) {
  if (lista_existe_(lista)) {
    if (lista->tamanho == 0) return true;
  }
  return false;
}

bool lista_cheia(LISTA *lista) {
  if (!lista_existe_(lista)) return false;
  NO* no = (NO*) malloc(sizeof(NO));
  if (no_existe_(no)) {
    free(no);
    no = NULL;
    return false;
  }
  return true;
}

void lista_imprimir(LISTA *lista) {
  if (!lista_existe_(lista)) return;
  lista_imprimir_aux(lista->inicio);
  return;
}


bool lista_inverter(LISTA **lista) {

}

