#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include "circulo.h"

void read_input(float* in_ponto_x, float* in_ponto_y, float* in_centro_x, float* in_centro_y, float* in_raio) {
  fscanf(stdin, "%f", in_ponto_x);
  fscanf(stdin, "%f", in_ponto_y);
  fscanf(stdin, "%f", in_centro_x);
  fscanf(stdin, "%f", in_centro_y);
  fscanf(stdin, "%f", in_raio);
}

int main(void) {
  PONTO* ponto;

  float in_ponto_x, in_ponto_y, in_centro_x, in_centro_y, in_raio;

  read_input(&in_ponto_x, &in_ponto_y, &in_centro_x, &in_centro_y, &in_raio);

  ponto = ponto_criar(in_ponto_x, in_ponto_y);
  ponto_print(ponto);

  CIRCULO* circulo;
  PONTO* p_centro;

  p_centro = ponto_criar(in_centro_x, in_centro_y);

  circulo = circulo_criar(p_centro, in_raio);
  float r = circulo_get_raio(circulo);
  PONTO* p = circulo_get_ponto(circulo);
  float x = ponto_get_x(p);
  float y = ponto_get_y(p);

  printf("Circulo: Centro (%.1f, %.1f), Raio = %.1f\n", x, y, r);

  ponto_apagar(&ponto);
  ponto_apagar(&p_centro);
  circulo_apagar(&circulo);

  return 0;
}