#include "assert.h"

void test_create_list(void)
{
  describe("create_list");
  Status status = Success;
  List_ptr list = create_list();
  status &= assert_is_eq_ptr(list->first, NULL);
  status &= assert_is_eq_ptr(list->last, NULL);
  status &= is_int_equal(list->length, 0);
  print_message(status, "should create a empty list");
}
