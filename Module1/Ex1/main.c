#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main(void) {
  PONTO* ponto;

  ponto = ponto_criar(4.0, 3.0);
  ponto_print(ponto);
  float x = ponto_get_x(ponto);
  float y = ponto_get_y(ponto);
  printf("%.2f %.2f\n", x, y);
  ponto_apagar(&ponto);

  return 0;
}