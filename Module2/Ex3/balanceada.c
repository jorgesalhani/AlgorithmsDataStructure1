bool balanceada(char *sequencia) {
  char c = sequencia[0];
  int i = 1;

  PILHA *pilha_aberta = pilha_criar();

  ITEM *item;
  ITEM *it;
  while (c != '\0') {
    if (c == '(' || c == '[' || c == '{') {
      item = item_criar(c);
      pilha_empilhar(pilha_aberta, item);
    } else {
      it = pilha_topo(pilha_aberta);
      if (c == ')' && item_get_chave(it) == '(') {
        it = pilha_desempilhar(pilha_aberta);
        item_apagar(&it);
      } else
      if (c == ']' && item_get_chave(it) == '[') {
        it = pilha_desempilhar(pilha_aberta);
        item_apagar(&it);
      } else
      if (c == '}' && item_get_chave(it) == '{') {
        it = pilha_desempilhar(pilha_aberta);
        item_apagar(&it);
      } else {
        item = item_criar(c);
        pilha_empilhar(pilha_aberta, item);
        break;
      }
    }
    
    c = sequencia[i];
    i++;
  }
  bool str_balanceada = true;
  if (pilha_tamanho(pilha_aberta) != 0) str_balanceada = false;
  pilha_apagar(&pilha_aberta);
  return str_balanceada;
}
