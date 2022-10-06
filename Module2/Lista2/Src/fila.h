#ifndef FILA_H
  #define FILE_H
  #include "item.h"
  #include <stdbool.h>
  #define MAX_ITENS 5

  typedef struct fila_ FILA;

  FILA* fila_criar(void);
  ITEM* fila_frente(FILA* fila);
  ITEM* fila_remover(FILA* fila);
  bool fila_vazia(FILA* fila);
  bool fila_cheia(FILA* fila);
  bool fila_inserir(FILA* fila, ITEM* item);
  void fila_completa_imprimir(FILA* fila);
  void fila_imprimir(FILA* fila);
  bool fila_apagar(FILA** fila);

#endif
