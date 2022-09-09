#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "book.h"
// #include "scheduling.h"

int ID_CODE = 0;

struct book_ {
  int id;
  char* author;
  char* title;
  int availability;
  // SCHEDULING* scheduling;
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
  book_shelf[ID_CODE]->id = ID_CODE;

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

void book_printf_by_id(BOOK*** ptr_book_shelf, int id) {
  BOOK** book_shelf = *ptr_book_shelf;
  if (book_shelf == NULL) return;
  if (id >= ID_CODE || id < 0) {
    printf("There are %d books stored in shelf. Exiting.\n", ID_CODE-1);
    book_delete_shelf(ptr_book_shelf);
    exit(EXIT_FAILURE);
  }
  printf("\nBOOK #%d\n", id);
  printf("-- Title: %s\n", book_shelf[id]->title);
  printf("-- Author: %s\n", book_shelf[id]->author);
  printf("-- Availability: %d\n", book_shelf[id]->availability);
  printf("==========\n");
  return;
}

BOOK* book_get_by_id(BOOK*** ptr_book_shelf, int id) {
  BOOK** book_shelf = *ptr_book_shelf;
  if (book_shelf == NULL) return NULL;
  if (id >= ID_CODE || id < 0) {
    printf("There are %d books stored in shelf. Exiting.\n", ID_CODE-1);
    book_delete_shelf(ptr_book_shelf);
    exit(EXIT_FAILURE);
  }
  return book_shelf[id];
}

BOOK* book_get_by_title(BOOK*** ptr_book_shelf, char* title) {
  BOOK** book_shelf = *ptr_book_shelf;
  if (book_shelf == NULL) return NULL;
  BOOK* book = NULL;
  for (int i = 0; i < ID_CODE; i++) {
    if (title == book_shelf[i]->title) {
      book = book_shelf[i];
      break;
    }
  }
  return book;
}

BOOK* book_get_by_author(BOOK*** ptr_book_shelf, char* author) {
  BOOK** book_shelf = *ptr_book_shelf;
  if (book_shelf == NULL) return NULL;
  BOOK* book = NULL;
  for (int i = 0; i < ID_CODE; i++) {
    if (author == book_shelf[i]->author) {
      book = book_shelf[i];
      break;
    }
  }
  return book;
}

void book_printf(BOOK* book) {
  if (book == NULL) return;
  printf("\nBOOK #%d\n", book->id);
  printf("-- Title: %s\n", book->title);
  printf("-- Author: %s\n", book->author);
  printf("-- Availability: %d\n", book->availability);
  printf("==========\n");
  return;
}

bool _is_book_available(BOOK* book) {
  return (book->availability > 0) ? true : false;
}

BOOK* book_borrow_by_author(BOOK*** ptr_book_shelf, char* author, char* requester) {
  BOOK* book = book_get_by_author(ptr_book_shelf, author);
  if (book == NULL) return NULL;
  if (!_is_book_available(book)) return NULL;
  book->availability--;
  return book;
}