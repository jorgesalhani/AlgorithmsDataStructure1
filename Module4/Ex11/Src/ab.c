#include <stdio.h>
#include <stdlib.h>
#include "ab.h"

struct ab_;

AB *ab_criar(void);
bool ab_inserir(AB *T, ITEM *item, int lado, int chave);
bool ab_remover(AB *T, int chave);
void ab_apagar_arvore(AB **T);
bool is_abb(AB *T);