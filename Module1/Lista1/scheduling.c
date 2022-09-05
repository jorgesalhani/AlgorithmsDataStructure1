#include <stdio.h>
#include <stdlib.h>
#include "scheduling.h"

struct sheduling {
  int id;
  int book_id;
  char* requester;
  int amount;
  SCHEDULING* next_scheduling;
};

// CREATE
SCHEDULING* new_scheduling(char* requester, int amount) {

}

// READ
SCHEDULING* get_scheduling_by_book_id(int book_id) {

}