#include <stdlib.h>
#include <stdio.h>
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

// Funcoes utilitarias
// ===================

bool lista_existe_(LISTA* lista) {
  return lista != NULL ? true : false;
}

bool no_existe_(NO* no) {
  return no != NULL ? true : false;
}

NO* chave_encontrada_inicio_(LISTA* lista, int chave) {
  if (!lista_existe_(lista) || lista_vazia(lista)) return NULL;
  if (item_get_chave(lista->inicio->item) == chave) return lista->inicio;
  return NULL;
}

NO* lista_busca_no_anterior_(LISTA* lista, NO* proximo_no, int chave) {
  if (!lista_existe_(lista) || lista_vazia(lista) || !no_existe_(proximo_no) ) return NULL;

  if (no_existe_(proximo_no->proximo) && item_get_chave(proximo_no->proximo->item) == chave) {
    return proximo_no;
  }

  lista_busca_no_anterior_(lista, proximo_no->proximo, chave);
}

void lista_imprimir_aux_(NO* no_proximo) {
  if (!no_existe_(no_proximo)) return;
  item_imprimir(no_proximo->item);
  lista_imprimir_aux_(no_proximo->proximo);
  return;
}

void lista_apagar_aux_(LISTA* lista) {
  if (!no_existe_(lista->inicio)) return;
  NO* no = lista->inicio;
  ITEM* item = lista_remover(lista, item_get_chave(lista->inicio->item));
  item_apagar(&item);
  if (no_existe_(lista->inicio)) lista_apagar_aux_(lista);
  return;
}

void busca_rec_aux_(NO* no_proximo, int chave, int* ocorrencias_rec) {
  if (!no_existe_(no_proximo)) return;
  if (item_get_chave(no_proximo->item) == chave) {
    int oc = *ocorrencias_rec;
    oc++;
    *ocorrencias_rec = oc;
  };
  if (!no_existe_(no_proximo->proximo)) return;
  return busca_rec_aux_(no_proximo->proximo, chave, ocorrencias_rec);
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
  NO* no = (NO*) malloc(sizeof(NO));
  no->proximo = NULL;
  no->item = item;

  if (lista->tamanho == 0) {
    lista->inicio = no;
    lista->fim = no;
  } else {
    lista->fim->proximo = no;
    lista->fim = no;
  }

  lista->tamanho++;

  return true;
}

ITEM *lista_remover(LISTA *lista, int chave) {
  if (!lista_existe_(lista) || lista_vazia(lista)) return false;

  NO* no_inicio = chave_encontrada_inicio_(lista, chave);
  ITEM* item = NULL;
  if (no_existe_(no_inicio)) {
    if (no_existe_(no_inicio->proximo)) {
      lista->inicio = no_inicio->proximo;
    } else {
      lista->inicio = NULL;
    }
    item = no_inicio->item;
    free(no_inicio);
    no_inicio = NULL;
    return item;
  }

  NO* no_anterior = lista_busca_no_anterior_(lista, lista->inicio, chave);
  NO* no_cursor = NULL;
  if (no_existe_(no_anterior)) {
    no_cursor = no_anterior->proximo;
    item = no_cursor->item;
    if (no_existe_(no_cursor->proximo)) {
      no_anterior->proximo = no_cursor->proximo;  
    } else {
      no_anterior->proximo = NULL;
    }
    free(no_cursor);
    no_cursor = NULL;
    return item;
  }
  
  return NULL;
}

bool lista_apagar(LISTA **lista) {
  if (lista == NULL || !lista_existe_(*lista)) return false;
  if (!lista_vazia(*lista)) lista_apagar_aux_(*lista);
  free(*lista);
  *lista = NULL;
  lista = NULL;
}

ITEM *lista_busca(LISTA *lista, int chave) {
  if (!lista_existe_(lista) || lista_vazia(lista)) return false;

  NO* no_inicio = chave_encontrada_inicio_(lista, chave);
  ITEM* item = NULL;
  if (no_existe_(no_inicio)) {
    if (no_existe_(no_inicio->proximo)) {
      lista->inicio = no_inicio->proximo;
    } else {
      lista->inicio = NULL;
    }
    item = no_inicio->item;
    return item;
  }

  NO* no_anterior = lista_busca_no_anterior_(lista, lista->inicio, chave);
  NO* no_cursor = NULL;
  if (no_existe_(no_anterior)) {
    no_cursor = no_anterior->proximo;
    item = no_cursor->item;
    return item;
  }
  
  return NULL;
}

int lista_tamanho(LISTA *lista) {
  if (lista_existe_(lista)) return lista->tamanho;
  return -40404;
}

bool lista_vazia(LISTA *lista) {
  if (lista_existe_(lista)) return lista->tamanho == 0 ? true : false;
  return false;
}

bool lista_cheia(LISTA *lista) {
  if (!lista_existe_(lista)) return false;
  NO* no_temp = (NO*) malloc(sizeof(NO));
  if (!no_existe_(no_temp)) return true;
  free(no_temp);
  no_temp = NULL;
  return false;
}

void lista_imprimir(LISTA *lista) {
  if (!lista_existe_(lista) || lista_vazia(lista)) return;
  lista_imprimir_aux_(lista->inicio);
  return; 
}


int busca_rec(LISTA *lista, int chave) {
  if (!lista_existe_(lista) || lista_vazia(lista)) return 0;
  int ocorrencias_rec = 0;
  busca_rec_aux_(lista->inicio, chave, &ocorrencias_rec);
  return ocorrencias_rec;
}
