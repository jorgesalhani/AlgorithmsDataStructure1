#ifndef PONTO_H
  #define PONTO_H
  #include <stdbool.h>
  typedef struct ponto_ PONTO;
  PONTO *ponto_criar (float x, float y);
  void ponto_apagar (PONTO **p);
  bool ponto_set (PONTO *p, float x, float y);
  float ponto_get_x (PONTO *p);
  float ponto_get_y (PONTO *p);
  void ponto_print (PONTO *p);

  /**
   * @brief Calcular distancia entre dois pontos dados
   * 
   * A decisao de estabelecer a funcao distancia dentro da interface 
   * do TAD PONTO se da por conta de a distancia ser calculada entre
   * dois pontos dados. Embora o seu uso aconteca entre as coordenadas
   * de um ponto e do centro do TAD CIRCULO, o centro é representado por 
   * um TAD PONTO, que nao necessariamente esta vinculado a um CIRCULO 
   * (caso segundo argumento PONTO *p2 ponto_aux utilizado na main.c)
   * 
   * @param PONTO *p1 Referencia opaca para o ponto 1 do tipo TAD PONTO
   * @param PONTO *p2 Referencia opaca para o ponto 2 do tipo TAD PONTO
   * @return float A distancia euclidiana entre ponto 1 e ponto 2
   * */

  float distancia(PONTO *p1, PONTO *p2);
#endif