/**
 * @author Jorge Augusto Salgado Salhani
 * @brief Funcao para inverter itens de uma lista encadeada
 * 
 * 
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