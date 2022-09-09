#ifndef BOOK_H
  #define BOOK_H
  #include <stdbool.h>
  // #include "scheduling.h"
  typedef struct book_ BOOK;

  BOOK** book_create_shelf(void);

  bool book_insert_in_shelf(BOOK*** ptr_book_shelf, char* author, char* title, int availability);
  bool book_delete_shelf(BOOK*** ptr_book_shelf);

  BOOK* book_get_by_id(BOOK*** ptr_book_shelf, int id);
  BOOK* book_get_by_title(BOOK*** ptr_book_shelf, char* title);
  BOOK* book_get_by_author(BOOK*** ptr_book_shelf, char* author);

  void book_printf(BOOK* book);
  void book_printf_by_id(BOOK*** ptr_book_shelf, int id);

  BOOK* book_borrow_by_author(BOOK*** ptr_book_shelf, char* author, char* requester);
  

#endif