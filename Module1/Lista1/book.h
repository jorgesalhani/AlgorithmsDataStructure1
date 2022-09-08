#ifndef BOOK_H
  #define BOOK_H
  #include <stdbool.h>
  typedef struct book_ BOOK;

  BOOK** book_create_shelf(void);
  void book_printf(BOOK* book);
  bool book_insert_in_shelf(BOOK*** ptr_book_shelf, char* author, char* title, int availability);
  bool book_delete_shelf(BOOK*** ptr_book_shelf);

#endif