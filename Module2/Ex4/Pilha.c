#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

struct pilha {
  ITEM* itens[TAM];
  int topo;
};

PILHA *pilha_criar(void) {
  PILHA* pilha = (PILHA*) malloc(sizeof(PILHA));
  if (pilha != NULL) pilha->topo = 0;
  return pilha;
}

void pilha_apagar(PILHA **pilha) {
  if (*pilha == NULL) return;
  if (pilha_vazia(*pilha)) {
    free((*pilha)->itens);
    *pilha = NULL;
    return;
  }
  free(pilha_desempilhar(*pilha));
  pilha_apagar(pilha);
}

bool pilha_vazia(PILHA *pilha) {
  if (pilha == NULL) return false;
  return pilha->topo == 0 ? true : false;
}

bool pilha_cheia(PILHA *pilha) {
  if (pilha == NULL) return false;
  return pilha->topo == TAM ? true : false;
}

int pilha_tamanho(PILHA *pilha) {
  if (pilha == NULL) return 404404;
  return pilha->topo;
}

ITEM *pilha_topo(PILHA *pilha) {
  if (pilha == NULL) return NULL;
  return pilha->itens[pilha->topo - 1];
}

bool pilha_empilhar(PILHA *pilha, ITEM *item) {
  if (pilha == NULL || item == NULL || pilha_cheia(pilha)) return false;
  pilha->itens[pilha->topo] = item;
  pilha->topo++;
  return true;
}

ITEM *pilha_desempilhar(PILHA *pilha) {
  if (pilha == NULL || pilha_vazia(pilha)) return NULL;
  ITEM* item = pilha_topo(pilha);
  pilha->itens[pilha->topo - 1] = NULL;
  pilha->topo--;
  return item;
}

void pilha_print(PILHA *p) {
  if (p == NULL || pilha_vazia(p)) return;
  item_imprimir(pilha_topo(p));
  return;
} 

/**
 * @author Jorge Augusto Salgado Salhani
 * @brief Calcular operacoes aritmeticas utilizando RPN
 * 
 * A estrutura de pilha eh interessante para este problema pois
 * as operecoes que ocorrem ao longo da leitura da esquerda para
 * a direita podem ser realizadas a medida que a sequencia eh lida.
 * 
 * Em outras palavras, como a operacao aritmetica ocorre entre dois
 * números subsequentes (na string original ou decorrente do resultado
 * de dois numeros quaisquer dentro da string sequencia, e esta ultima 
 * sendo motivo principal do uso de pilha) que sao sucedidos por um 
 * operador +,-,*,/ , a estrategia que pode ser adotada 
 * eh a seguinte:
 * 
 * 1. Percorrer a lista sequencia original
 * 2. Empilhar valores (operandos)
 * 3. Reconhecer um operador
 * 4. Desempilhar valores (operandos)
 * 5. Empilhar resultado
 * 
 * @param char* sequencia A sequencia de caracteres
 * @return float O resultado da operacao aritmetica RPN
*/
float rpn(char *sequencia) {
  if (sequencia == NULL) return 404.404;

  // Inicializando variaveis e criando uma pilha
  int i = 1;
  char c = sequencia[0];
  PILHA *pilha = pilha_criar();
  ITEM* item;
  float result;

  while (c != '\0') {

    // Caso seja um operador e a pilha nao esteja vazia
    if (c == '+' || c == '-' || c == '*' || c == '/') {
      if (!pilha_vazia(pilha)) {

        // Resgatar os dois ultimos numeros da pilha
        // e executar a respectiva operacao
        ITEM* item_op2 = pilha_desempilhar(pilha);
        ITEM* item_op1 = pilha_desempilhar(pilha);
        switch (c) {
          case '+':
            result = item_get_chave(item_op1) + item_get_chave(item_op2);
            break;
          case '-':
            result = item_get_chave(item_op1) - item_get_chave(item_op2);
            break;
          case '*':
            result = item_get_chave(item_op1) * item_get_chave(item_op2);
            break;
          case '/':
            result = item_get_chave(item_op1) / item_get_chave(item_op2);
            break;
          
          default:
            break;
        }

        // Empilhar um novo item na pilha contendo o 
        // resultado da operacao
        item = item_criar(result);
        pilha_empilhar(pilha, item);

        // Apagar os itens de operandos extraidos da pilha
        item_apagar(&item_op1);
        item_apagar(&item_op2);
      }
    } else {

      // Empilhar um novo numero lido como char
      item = item_criar(((int)c - 48));
      pilha_empilhar(pilha, item);
    }
    c = sequencia[i++];
  }
  pilha_apagar(&pilha);
}

