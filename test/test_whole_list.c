#include "test.h"

int main(void)
{
  test_create_list();
  test_clear_list();

  test_add_to_list();
  test_add_to_start();
  test_insert_in_middle();

  test_add_unique();

  test_remove_from_start();
  test_remove_from_end();
  test_remove_at();

  test_remove_first_occurrance();
  test_remove_all_occurrances();

  test_reverse_list();

  test_map();
  test_filter();
  test_reduce();
  test_for_each();

  return 0;
}