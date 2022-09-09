/**
  @file scheduling.h
  @brief Function prototypes for book scheduling 

  @author Jorge Salhani, 2022
  @bug No known bugs
*/

#ifndef SCHEDULING_H
  #define SCHEDULING_H
  #include "book.h"
  typedef struct scheduling_ SCHEDULING;

  /**
    @brief Create a scheduling ADT to be attached to a given book
    @param requester The name from requester
    @param amount The book amount requested to be borrowed
    @return SCHEDULING* ADT
  */
  SCHEDULING* new_scheduling(BOOK*** ptr_book_shelf, int book_id, char* requester);

  /**
    @brief Retrieve the schedule queue attached to a given book
    @param book_id The book ID code
    @return SCHEDULING* ADT
  */
  SCHEDULING* get_scheduling_by_book_id(BOOK*** ptr_book_shelf, int book_id);
#endif