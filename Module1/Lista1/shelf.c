#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "shelf.h"

int ID_CODE = 0;

struct shelf_ {
  BOOK** shelf;
};

struct book_ {
  int id;
  char* title;
  char* author;
  int available_amount;
  SCHEDULING* scheduling;
};

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
SHELF** create_shelf(void) {
  SHELF** shelf;
  shelf = (SHELF**)malloc(sizeof(SHELF*));
  *shelf = (BOOK*)malloc(sizeof(BOOK*));

  if (shelf != NULL) {
    *shelf = NULL;
    return shelf;
  }

  return NULL;
}

BOOK* create_book(SHELF*** shelf, char* title, char* author) {
  BOOK* book;
  book = (BOOK*)malloc(sizeof(BOOK));

  if (book != NULL) {
    _fill_book_default_information(book, title, author);
    return book;
  }

  return NULL;
}

// READ

void printf_book(SHELF*** shelf, int id) {
  // if(*shelf != NULL) {
  //   SHELF** _shelf = *shelf;
  //   if (_shelf[id] != NULL) {
  //     printf('BOOK %d\n=========\n', id);
  //   }
  // }
  printf('Empty shelf!\n');
}

void printf_shelf(SHELF*** shelf) {
  if(*shelf != NULL) {
    SHELF** _shelf = *shelf;
    for (int i = 0; i < ID_CODE; i++) {
      if (_shelf[i] != NULL) {
        printf_book(shelf, i);
      }
    }
  }
  return;
}

BOOK* get_book_by_id(SHELF*** shelf, int id) {

}

int get_book_id(SHELF*** shelf, char* title, char* author) {

}

int get_available_amount(SHELF*** shelf, int id) {

}

int get_reservation_amount(SHELF*** shelf, int id) {

}

int get_scheduling_amount(SHELF*** shelf, int id) {

}

SCHEDULING* get_scheduling(SHELF*** shelf, int id) {

}


// UPDATE
bool set_title(SHELF*** shelf, int id, char* title) {

}

bool set_author(SHELF*** shelf, int id, char* author) {

}

bool set_available_amount(SHELF*** shelf, int id, int available_amount) {

}

BOOK* borrow_book(SHELF*** shelf, char* title, char* author, char* requester) {

}

// DELETE
bool delete_book(SHELF*** shelf, int id) {
  SHELF** book_shelf = *shelf;
  BOOK* chosen_book = book_shelf[id];
  
  if (shelf != NULL && chosen_book != NULL) {
    if (chosen_book->title != NULL) {
      free(chosen_book->title);
    }
    if (chosen_book->author != NULL) {
      free(chosen_book->author);
    }
    if (chosen_book->scheduling != NULL) {
      free(chosen_book->scheduling);
    }
    free(chosen_book);
    return true;
  }
  return false;
}

bool delete_shelf(SHELF*** shelf) {
  if (shelf != NULL) {
    // for (int i = 0; i < ID_CODE; i++) {
    //   if (*shelf != NULL) {
    //     delete_book(shelf, i);
    //   }
    //   free(*shelf);
    //   (*shelf)++;
    // }
    free(*shelf);
    free(shelf);
    return true;
  }
  return false;
}