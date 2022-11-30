/**
 * @author Jorge Augusto Salgado Salhani
 * @brief Funcao que verifica se dada AB e' ABB
 * 
 * ABB: 
 *  1. maior no da subarvore esquerda deve ser menor
 *     que o no raiz
 *  2. menor no da subarvore direita deve ser maior
 *     que o no raiz
 * 
 * Para cada no raiz, armazenamos seu menor no esquerdo
 * e seu maior no direito. Se satisfizer 1 e 2, e' ABB
*/

// Funcoes utilitarias
// ===================

// Verifica existencia

bool no_existe_(NO* no) {
  return (no != NULL) ? true : false;
}

bool ab_existe_(AB* ab) {
  return (ab != NULL) ? true : false;
}

// Busca maior item da subarvore esquerda

int abb_max_esq_(NO* raiz) {
  if (!no_existe_(raiz)) return 0;
  
  int max_esq = abb_max_esq_(raiz->esq);
  int max_dir = abb_max_esq_(raiz->dir);

  int max = max_esq;
  if (max_esq < max_dir) max = max_dir;
  if (item_get_chave(raiz->item) > max) max = item_get_chave(raiz->item);

  return max;
}

// Busca menor item da subarvore direita

int abb_min_dir_(NO* raiz) {
  if (!no_existe_(raiz)) return 0;

  int min_esq = abb_min_dir_(raiz->esq);
  int min_dir = abb_min_dir_(raiz->dir);

  int min = item_get_chave(raiz->item);
  if (min_esq != 0 && min_esq < min_dir) min = min_esq;
  if (item_get_chave(raiz->item) < min) min = item_get_chave(raiz->item);

  return min;
}

// Funcoes principais
// ==================

// Funcao is_abb auxiliar recursiva

bool is_abb_aux_(NO* raiz) {
  if (!no_existe_(raiz)) return false;

  int max_esq = abb_max_esq_(raiz->esq);
  int min_dir = abb_min_dir_(raiz->dir);

  if (max_esq > item_get_chave(raiz->item)) return false;
  if (min_dir < item_get_chave(raiz->item)) return false;

  return true;
}

// Funcao de interface

bool is_abb(AB *T) {
  if (!ab_existe_(T)) return false;

  bool verificado = true;
  return (verificado = is_abb_aux_(T->raiz));
}
