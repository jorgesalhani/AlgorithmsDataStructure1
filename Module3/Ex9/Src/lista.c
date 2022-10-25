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



// Funcoes de interface
// ====================

LISTA *lista_criar(void) {

}

bool lista_inserir(LISTA *lista, ITEM *item) {

}

ITEM *lista_remover(LISTA *lista, int chave) {

}

bool lista_apagar(LISTA **lista) {

}

ITEM *lista_busca(LISTA *lista, int chave) {

}

int lista_tamanho(LISTA *lista) {

}

bool lista_vazia(LISTA *lista) {

}

bool lista_cheia(LISTA *lista) {

}

void lista_imprimir(LISTA *lista) {

}


bool lista_inverter(LISTA **lista) {

}

