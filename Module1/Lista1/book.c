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

BOOK** book_create_shelf(void) {
  BOOK** book_shelf = (BOOK**) malloc(sizeof(BOOK*));
  
  if (book_shelf == NULL) return NULL;
  return book_shelf;
}

bool book_insert_in_shelf(BOOK*** ptr_book_shelf, char* author, char* title, int availability) {
  BOOK** book_shelf = *ptr_book_shelf;
  if (book_shelf == NULL) return false;

  book_shelf = (BOOK**) realloc(book_shelf, sizeof(BOOK**)*(ID_CODE+1));
  if (book_shelf == NULL) return false;

  book_shelf[ID_CODE] = (BOOK*) malloc(sizeof(BOOK));
  book_shelf[ID_CODE]->author = author;
  book_shelf[ID_CODE]->title = title;
  book_shelf[ID_CODE]->availability = availability;

  *ptr_book_shelf = book_shelf;
  ID_CODE++;
  return true;
}

bool book_delete_shelf(BOOK*** ptr_book_shelf) {
  BOOK** book_shelf = *ptr_book_shelf;

  if (book_shelf == NULL) return false;
  for (int i = 0; i < ID_CODE; i++) {
    if (book_shelf[i] == NULL) break;
    free(book_shelf[i]);
  }
  free(book_shelf);
  return true;
}

void book_printf(BOOK* book) {
  printf("BOOK\n");
  printf("-- Title: %s\n", book->title);
  printf("-- Author: %s\n", book->author);
  printf("-- Availability: %d\n", book->availability);
  printf("==========\n");
}