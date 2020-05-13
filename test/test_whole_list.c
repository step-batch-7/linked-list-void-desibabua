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

  return 0;
}