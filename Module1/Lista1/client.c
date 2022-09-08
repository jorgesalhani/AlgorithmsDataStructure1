#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "book.h"

int main(void) {

  BOOK** book_shelf = book_create_shelf();

  book_insert_in_shelf(&book_shelf, "Author", "Title", 1);
  book_insert_in_shelf(&book_shelf, "Author1", "Title1", 1);
  book_insert_in_shelf(&book_shelf, "Author2", "Title2", 1);

  book_printf(book_shelf[1]);

  book_delete_shelf(&book_shelf);

  return 0;
}