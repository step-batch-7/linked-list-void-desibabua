#include "test.h"

int main(void)
{
  test_create_list();
  test_clear_list();
  
  test_add_to_list();
  test_add_to_start();
  test_insert_in_middle();

  return 0;
}