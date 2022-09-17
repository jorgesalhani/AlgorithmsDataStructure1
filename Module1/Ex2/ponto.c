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
    printf("Ponto: (%.1f, %.1f)\n", p->x, p->y);
  }
}

float _calcular_sqrt_iterativo_(float x) {
  float temp = 0;
  float sqrt_it = x / 2;
  while (sqrt_it != temp) {
    temp = sqrt_it;
    sqrt_it = (x/temp + temp) / 2;
  }
  return sqrt_it;
}

float distancia(PONTO *p1, PONTO *p2) {
  if (p1 != NULL && p2 != NULL) {
    float x1 = p1->x, x2 = p2->x, y1 = p1->y, y2 = p2->y;
    float dist = _calcular_sqrt_iterativo_(((y2 - y1)*(y2 - y1) + (x2-x1)*(x2-x1)));
    return dist;
  }
  return -1;
}