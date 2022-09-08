#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "book.h"

int ID_CODE = 0;

struct book_ {
  int id;
  char* author;
  char* title;
  int availability;
};

BOOK* book_create(char* author, char* title, int availability) {
  BOOK* book = (BOOK*) malloc(sizeof(BOOK));
  if (book == NULL) {
    return NULL;
  }
  book->author = author;
  book->title = title;
  book->availability = availability;
  return book;
}

bool book_delete(BOOK* book) {
  if (book == NULL) {
    return false;
  }
  free(book);
  book = NULL;
  return true;
}

void book_printf(BOOK* book) {
  printf("BOOK\n");
  printf("-- Title: %s\n", book->title);
  printf("-- Author: %s\n", book->author);
  printf("-- Availability: %d\n", book->availability);
  printf("==========\n");
}