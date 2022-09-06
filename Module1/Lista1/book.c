#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "book.h"

int ID_CODE = 0;

struct book_ {
  int id;
  char* title;
  char* author;
  int available_amount;
  SCHEDULING* scheduling;
};

void _add_book_to_shelf(BOOK** book_shelf, BOOK* book) {
  book_shelf[ID_CODE] = book;
  ID_CODE++;
}

void _fill_book_title(BOOK* book, char* title) {
  char* _title = (char*)malloc(sizeof(char));
  int i = 0;
  while (*title != '\n') {
    _title[i] = *title;
    _title = (char*)realloc(_title, sizeof(char)*(i++));
    title++;
  }
  book->title = _title;
}

void _fill_book_author(BOOK* book, char* author) {
  char* _author = (char*)malloc(sizeof(char));
  int i = 0;
  while (*author != '\n'){
    _author[i] = *author;
    _author = (char*)realloc(_author, sizeof(char)*(i++));
    author++;
  }
  book->author = _author;
}

void _fill_book_default_information(BOOK* book, char* title, char* author) {
  book->title = NULL;
  book->author = NULL;
  if (title != NULL) {
    _fill_book_title(book, title);
  }
  if (author != NULL) {
    _fill_book_author(book, author);
  }
  book->id = ID_CODE;
  book->available_amount = 1;
  book->scheduling = NULL;
  ID_CODE++;
}

// CREATE
BOOK** create_shelf(void) {
  BOOK** book_shelf = NULL;
  book_shelf = (BOOK**)malloc(sizeof(BOOK*));
  *book_shelf = (BOOK*)malloc(sizeof(BOOK));

  if (book_shelf != NULL && *book_shelf != NULL) {
    return book_shelf;
  }
  return NULL;
}

BOOK* create_book(BOOK** book_shelf, char* title, char* author) {
  BOOK* book = NULL;
  book = (BOOK*)malloc(sizeof(BOOK));

  if (book != NULL) {
    _fill_book_default_information(book, title, author);
    _add_book_to_shelf(book_shelf, book);
    return book;
  }

  return NULL;
}

// READ
void printf_book(BOOK** book_shelf, int id) {
  if(book_shelf != NULL && *book_shelf != NULL) {
    if (book_shelf[id] != NULL) {
      printf('BOOK %d\n=========\n', id);
    }
  }
  printf('Empty shelf!\n');
}

void printf_shelf(BOOK** book_shelf) {
  if(*book_shelf != NULL) {
    BOOK** _shelf = *book_shelf;
    for (int i = 0; i < ID_CODE; i++) {
      if (_shelf[i] != NULL) {
        printf_book(book_shelf, i);
      }
    }
  }
  return;
}

BOOK* get_book_by_id(BOOK** BOOK, int id) {

}

int get_book_id(BOOK** book_shelf, char* title, char* author) {

}

int get_available_amount(BOOK** book_shelf, int id) {

}

int get_reservation_amount(BOOK** book_shelf, int id) {

}

int get_scheduling_amount(BOOK** book_shelf, int id) {

}

SCHEDULING* get_scheduling(BOOK** book_shelf, int id) {

}


// UPDATE
bool set_title(BOOK** book_shelf, int id, char* title) {

}

bool set_author(BOOK** book_shelf, int id, char* author) {

}

bool set_available_amount(BOOK** book_shelf, int id, int available_amount) {

}

BOOK* borrow_book(BOOK** book_shelf, char* title, char* author, char* requester) {

}

// DELETE
bool delete_book(BOOK** book_shelf, int id) {
  BOOK* book = book_shelf[id];
  
  if (book_shelf != NULL && book != NULL) {
    if (book->title != NULL) {
      free(book->title);
    }
    if (book->author != NULL) {
      free(book->author);
    }
    if (book->scheduling != NULL) {
      free(book->scheduling);
    }
    free(book);
    return true;
  }
  return false;
}

bool delete_shelf(BOOK** book_shelf) {
  if (book_shelf != NULL) {
    for (int i = 0; i < ID_CODE; i++) {
      if (*book_shelf != NULL && book_shelf[i] != NULL) {
        delete_book(book_shelf, i);
      }
      (*book_shelf)++;
    }
    free(book_shelf);
    return true;
  }
  return false;
}