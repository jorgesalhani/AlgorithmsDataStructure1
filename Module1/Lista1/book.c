#include <stdio.h>
#include <stdlib.h>
#include "book.h"

struct book {
  int id;
  char* title;
  char* author;
  int available_amount;
  SCHEDULING* scheduling;
};

// CREATE
BOOK* create_book(char* title, char* author);

// READ
BOOK* get_book_by_id(int id);
int get_book_id(char* title, char* author);
int get_available_amount(int id);
int get_reservation_amount(int id);
int get_scheduling_amount(int id);
SCHEDULING* get_scheduling(int id);

// UPDATE
bool set_title(int id, char* title);
bool set_author(int id, char* author);
bool set_available_amount(int id, int available_amount);
BOOK* borrow_book(char* title, char* author, char* requester);

// DELETE
bool delete_book(int id);