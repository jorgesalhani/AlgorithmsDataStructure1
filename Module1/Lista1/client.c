#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "book.h"

int main(void) {
  BOOK* book = book_create("Author", "Title", 1);
  book_printf(book);
  bool deleted = book_delete(book);

  return 0;
}