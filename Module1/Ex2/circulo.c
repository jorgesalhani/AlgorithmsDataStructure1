#include <stdlib.h>
#include <stdio.h>
#include "circulo.h"

struct circulo_ {
  PONTO* ponto;
  float raio;
};

CIRCULO *circulo_criar (PONTO *p, float raio) {
  CIRCULO* circulo;
  circulo = (CIRCULO*) malloc(sizeof(CIRCULO));

  if (circulo != NULL && p != NULL) {
    circulo->ponto = p;
    circulo->raio = raio;
    return circulo;
  }
  return NULL;
}

bool circulo_set_ponto (CIRCULO *c,PONTO *p) {
  if (c != NULL && p != NULL) {
    c->ponto = p;
    return true;
  }
  return false;
}

bool circulo_set_raio (CIRCULO *c, int raio) {
  if (c != NULL) {
    c->raio = raio;
    return true;
  }
  return false;
}

PONTO *circulo_get_ponto (CIRCULO *c) {
  if (c != NULL) {
    return c->ponto;
  }
  exit(1);
}

int circulo_get_raio (CIRCULO *c) {
  if (c != NULL) {
    return c->raio;
  }
  exit(1);
}

void circulo_apagar (CIRCULO **circulo) {
  CIRCULO* c = *circulo;
  if (c != NULL ) {
    free(c);
    return;
  }
  return;
}