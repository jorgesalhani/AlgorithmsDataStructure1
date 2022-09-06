#include "book.h"
#include "scheduling.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  BOOK** book_shelf = create_shelf();
  BOOK* book = create_book(book_shelf, "aaa", "bbb");
  printf_book(book, 0);
  delete_shelf(book_shelf);
  return 0;
}