#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "book.h"

int ID_CODE = 0;

struct book_ {
  int id;
  char* title;
  char* author;
  int available_amount;
  // SCHEDULING* scheduling;
};

BOOK* book_create(char* title, char* author) {
  BOOK* book = (BOOK*) malloc(sizeof(BOOK));

  if (book != NULL) {
    book->author = author;
    book->title = title;
    book->id = ID_CODE;
    ID_CODE++;
    return book;
  }
  return NULL;
}

bool book_delete(BOOK* book) {
  if (book != NULL) {
    free(book);
    return true;
  }
  return false;
}

void book_printf(BOOK* book) {
  if (book != NULL) {
    printf("BOOK #%d\n", book->id);
    printf("-- Title: %s\n", book->title);
    printf("-- Author: %s\n", book->author);
    printf("==========\n\n");
  }
}

