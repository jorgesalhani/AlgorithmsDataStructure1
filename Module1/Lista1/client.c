#include "shelf.h"
#include "scheduling.h"

int main(void) {
  SHELF** shelf = create_shelf();
  BOOK* book = create_book(&shelf, "aaa", "bbb");
  delete_shelf(&shelf);
  return 0;
}