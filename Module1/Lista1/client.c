#include <stdio.h>
#include <stdlib.h>
#include "book.h"

int main(void) {
  BOOK* book = book_create("Title", "Author");
  book_printf(book);
  book_delete(book);
  return 0;
}