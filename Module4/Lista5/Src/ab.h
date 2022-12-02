#ifndef ARVORE_BINARIA_H
  #define ARVORE_BINARIA_H

  #include "item.h"

  #define DESC_ESQ 0
  #define DESC_DIR 1

  typedef struct ab_ AB;

  AB* ab_criar();
  bool ab_inserir(AB* T, ITEM* item, int lado, int chave);
  bool ab_apagar_arvore(AB** T);

  int ab_profundidade(AB* T);
  int ab_soma_conteudo(AB* T);
  int ab_total_nos(AB* T);
  bool ab_estrita(AB* T);

#endif