#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "book.h"

int main(void) {

  BOOK** book_shelf = book_create_shelf();

  book_insert_in_shelf(&book_shelf, "Author", "Title", 1);
  book_insert_in_shelf(&book_shelf, "Author1", "Title1", 1);
  book_insert_in_shelf(&book_shelf, "Author2", "Title2", 1);

  // book_printf_by_id(&book_shelf, 2);

  BOOK* book = book_get_by_id(&book_shelf, 2);
  book_printf(book);

  book = book_borrow_by_author(&book_shelf, "Author2", "Jorge");
  book_printf(book);

  book_delete_shelf(&book_shelf);

  return 0;
}