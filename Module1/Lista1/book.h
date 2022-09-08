#ifndef BOOK_H
  #define BOOK_H
  typedef struct book_ BOOK;

  BOOK* book_create(char* author, char* title, int availability);
  bool book_delete(BOOK* book);
  void book_printf(BOOK* book);


#endif