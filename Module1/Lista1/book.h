/** 
  @file book.h
  @brief Function prototypes for book borrowing and scheduling

  @author Jorge Salhani, 2022
  @bug No known bugs
*/

#ifndef BOOK_H
  #define BOOK_H
  #include <stdbool.h>
  // #include "scheduling.h"
  typedef struct book_ BOOK;

  /**
    @brief Create a book ADT array
    @param void
    @return BOOK** ADT
  */
  BOOK** book_create_shelf(void);

  /**
   * @brief Create a book ADT
   * @param book_shelf The memory where all books will be stored
   * @param title The book's title
   * @param author The book's author
   * @return BOOK* ADT
  */
  BOOK* book_create(char* title, char* author);

  /**
   * @brief Delete a book ADT
   * @param book The book's pointer
   * @return successfully deleted ? true : false
  */
  bool book_delete(BOOK* book);

  /**
   * @brief Delete all book shelf
   * @param book_shelf The book's storage shelf
   * @return successfully deleted ? true : false
  */
  bool book_delete_shelf(BOOK** book_shelf);

  /**
   * @brief Print formatted book's metadata
   * @param book The book's memory address
   * @return void
  */
 void book_printf(BOOK* book);

#endif