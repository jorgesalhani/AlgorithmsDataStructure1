#include <stdio.h>
#include <stdlib.h>
#include "scheduling.h"

int ID_CODE = 0;

struct scheduling_ {
  int id;
  int book_id;
  char* requester;
  SCHEDULING* next_scheduling;
};

// CREATE
SCHEDULING* new_scheduling(BOOK*** ptr_book_shelf, int book_id, char* requester) {
  BOOK** book_shelf = *ptr_book_shelf;
  if (book_shelf == NULL) return NULL;
  SCHEDULING* scheduling = (SCHEDULING*) malloc(sizeof(SCHEDULING));
  BOOK* book = book_shelf[book_id];
  return;
}

// READ
SCHEDULING* get_scheduling_by_book_id(BOOK*** ptr_book_shelf, int book_id) {
  return;
}