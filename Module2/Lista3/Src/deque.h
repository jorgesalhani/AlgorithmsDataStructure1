#ifndef DEQUE_H
  #define DEQUE_H

  #include <stdbool.h>
  #include "item.h"

  typedef struct deque_ DEQUE;

  DEQUE* deque_criar(void);
  bool deque_apagar(DEQUE** deque);

  bool deque_inserir_fim(DEQUE* deque, ITEM* item);
  bool deque_inserir_inicio(DEQUE* deque, ITEM* item);
  ITEM* deque_remover_fim(DEQUE* deque);
  ITEM* deque_remover_inicio(DEQUE* deque);
  void deque_imprimir_inicio(DEQUE* deque);
  void deque_imprimir_fim(DEQUE* deque);
  bool deque_vazio(DEQUE* deque);
  bool deque_cheio(DEQUE* deque);
  int deque_tamanho(DEQUE* deque);
  void deque_inverter_extremos(DEQUE* deque);
  
#endif