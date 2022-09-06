/** 
  @file book.h
  @brief Function prototypes for book borrowing and scheduling

  @author Jorge Salhani, 2022
  @bug No known bugs
*/

#ifndef BOOK_H
  #define BOOK_H
  #include <stdbool.h>
  #include "scheduling.h"
  typedef struct book_ BOOK;

  /**
    @brief Create a book ADT array
    @param void
    @return BOOK** ADT
  */
  BOOK** create_shelf(void);

  /**
    @brief Register a new book ADT
    @param book_shelf The book's list memory address
    @param title The book's title
    @param author The book's author
    @return BOOK* ADT
  */
  BOOK* create_book(BOOK** book_shelf, char* title, char* author);

  /**
    @brief Get book ADT by book's ID code
    @param book_shelf The book's list memory address
    @param id The book's ID
    @return BOOK* ADT
  */
  BOOK* get_book_by_id(BOOK** book_shelf, int id);

  /**
    @brief Get book's ID code via book's title and/or book's author
    @param book_shelf The book's list memory address
    @param title The book's title
    @param author The book's author
    @return int id
  */
  int get_book_id(BOOK** book_shelf, char* title, char* author);

  /**
    @brief Get book's available amount to be borrowed
    @param book_shelf The book's list memory address
    @param id The book's ID code
    @return int available amount
  */
  int get_available_amount(BOOK** book_shelf, int id);
  
  /**
    @brief Get scheduling queue attached to a given book by it's ID code
    @param book_shelf The book's list memory address
    @param id The book's ID code
    @return SHCEDULING* ADT
  */    
  SCHEDULING* get_scheduling(BOOK** book_shelf, int id);
  
  /**
    @brief Print formatted all shelf books
    @param book_shelf The book's list memory address
    @return Void
  */   
  void printf_shelf(BOOK** book_shelf);

  /**
    @brief Print formatted book's metadata by it's ID code
    @param book_shelf The book's list memory address
    @param id The book's ID code
    @return Void
  */   
  void printf_book(BOOK** book_shelf, int id);

  /**
    @brief Update book's title
    @param book_shelf The book's list memory address
    @param id The book's ID code
    @param title The book's new title
    @return successfully updated ? true : false
  */  
  bool set_title(BOOK** book_shelf, int id, char* title);
  
  /**
    @brief Update book's author
    @param book_shelf The book's list memory address
    @param id The book's ID code
    @param author The book's new author
    @return successfully updated ? true : false
  */   
  bool set_author(BOOK** book_shelf, int id, char* author);
  
  /**
    @brief Update book's available amount
    @param book_shelf The book's list memory address
    @param id The book's ID code
    @param available_amount The book's available amount
    @return successfully updated ? true : false
  */   
  bool set_available_amount(BOOK** book_shelf, int id, int available_amount);

  /**
    @brief Perform book borrowing by the client (requester)
    @param book_shelf The book's list memory address
    @param title The book's title
    @param author The book's author
    @param requester The client's name (book borrower / requester)
    @return
  */   
  BOOK* borrow_book(BOOK** book_shelf, char* title, char* author, char* requester);

  /**
    @brief Delete book from database (erase from allocated memory)
    @param book_shelf The book's list memory address
    @param id The book's ID code
    @return successfully deleted ? true : false
  */
  bool delete_book(BOOK** book_shelf, int id);

  /**
    @brief Delete shelf and all its books (erase from allocated memory)
    @param book_shelf The book's list memory address
    @return successfully deleted ? true : false
  */
  bool delete_shelf(BOOK** book_shelf);
#endif