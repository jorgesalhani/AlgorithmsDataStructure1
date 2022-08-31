#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

struct ponto_ {
  float x; 
  float y;
};

PONTO *ponto_criar(float x, float y) {
  PONTO *ponto;

  ponto = (PONTO*)malloc(sizeof(PONTO));

  if (ponto != NULL) {
    ponto->x = x;
    ponto->y = y;
    return ponto; 
  }
  return(NULL);
}

void ponto_apagar(PONTO **p) {
  PONTO* ponto = *p;
  if (ponto != NULL) {
    free(ponto);
    ponto = NULL;
    return;
  }
  return;
}

bool ponto_set(PONTO *p, float x, float y) {
  if (p != NULL) {
    p->x = x;
    p->y = y;
    return(true);
  }
  return(false);
}

float ponto_get_x(PONTO *p) {
  if (p != NULL) {
    return(p->x);
  }
  exit(1);
}

float ponto_get_y(PONTO *p) {
  if (p != NULL) {
    return(p->y);
  }
  exit(1);
}

void ponto_print(PONTO *p) {
  if (p != NULL) {
    printf("Ponto: (%.2f, %.2f)\n", p->x, p->y);
  }
}