#include "assert.h"
#include "../linkedlist.h"


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

void test_add_to_list(void)
{
  describe("add_to_list");

  List_ptr list = create_list();
  Element element = malloc(sizeof(int));
  *(int *)element = 4;

  Status act_status = add_to_list(list, element);
  int exp_values[] = {4};

  Status status = assert(list, 1, exp_values, act_status, Success, &is_int_ptr_equal);
  print_message(status, "should add element at the end of list");
}

void test_add_to_start(void)
{
  describe("add_to_start");

  List_ptr list = create_list();
  Element element = malloc(sizeof(int));
  *(int *)element = 3;

  Status act_status = add_to_start(list, element);
  int exp_values[] = {3};
  
  Status status = assert(list, 1, exp_values, act_status, Success, &is_int_ptr_equal);
  print_message(status, "should add element at the start of list");
}