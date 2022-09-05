#ifndef SCHEDULING_H
  #define SCHEDULING_H
  typedef struct scheduling_ SCHEDULING;
    // CREATE
    SCHEDULING* scheduling(char* requester, int amount);

    // READ
    SCHEDULING* get_scheduling_by_book_id(int id);
#endif