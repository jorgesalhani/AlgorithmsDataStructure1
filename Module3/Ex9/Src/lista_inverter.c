/**
 * @author Jorge Augusto Salgado Salhani
 * @brief Funcao para inverter itens de uma lista encadeada
 * 
 * A funcao principal eh responsavel por inverter recursivamente
 * uma dada lista encadeada. O algoritmo segue:
 * 
 * 1. Armazena um no cursor e seu no anterior.
 * 2. Caso seja o primeiro elemento da lista, seu proximo no eh nulo
 * 3. Caso contrario, faz do no->proximo o no anterior da lista original
 * 4. Repete a reconexao ate que no->proximo seja nulo
*/

// Funcoes auxiliares
// ==================

bool lista_existe_(LISTA* lista) {
  return (lista != NULL) ? true : false;
}

bool no_existe_(NO* no) {
  return (no != NULL) ? true : false;
}

void lista_inverter_recursivo_aux(bool no_inicio, NO* no_anterior, NO* no_cursor) {
  if (!no_existe_(no_anterior) || !no_existe_(no_cursor)) return;

  NO* no_proximo = no_cursor->proximo;
  if (no_inicio) no_anterior->proximo = NULL;
  no_cursor->proximo = no_anterior;

  if (!no_existe_(no_proximo)) return;

  lista_inverter_recursivo_aux(false, no_cursor, no_proximo);
}

// Funcao principal
// ================

bool lista_inverter(LISTA **lista) {
  if (lista == NULL || !lista_existe_(*lista) || lista_vazia(*lista)) return false;
  lista_inverter_recursivo_aux(true, (*lista)->inicio, (*lista)->inicio->proximo);
  NO* no_inicio = (*lista)->inicio;
  (*lista)->inicio = (*lista)->fim;
  (*lista)->fim = no_inicio;
  return true;
}