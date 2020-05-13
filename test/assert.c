#include "assert.h"

Status assert(List_ptr list, int length, void *exp_list_values, Status act_status, Status exp_status, comparer is_equal)
{
  Status status = act_status == exp_status && list->length == length;
    Node_ptr p_walk = list->first;

    int index = 0;
    while (status || p_walk != NULL)
    {
      status = (*is_equal)(p_walk->element, &exp_list_values[index]);
      p_walk = p_walk->next;
      index++;
    }
  return status;
}

void print_message(Status status, char message[])
{
  char *symbol = status ? "✓" : "✘";
  printf("  %s %s\n",symbol, message);
}

Status is_int_ptr_equal(void *num1, void *num2)
{
  return *(int *)num1 == *(int *)num2;
}

Status is_int_equal(int num1, int num2)
{
  return num1 == num2;
}

Status assert_is_eq_ptr(void *ptr1,void *ptr2)
{
  return ptr1 == ptr2;
}

Status assert_is_not_eq_ptr(void *ptr1,void *ptr2)
{
  return ptr1 != ptr2;
}

void describe(char *function_name)
{
  printf("\n # %s\n\n", function_name);
}
