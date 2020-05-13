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
  Element element_1 = malloc(sizeof(int));
  *(int *)element_1 = 4;

  Status act_status = add_to_list(list, element_1);

  Element exp_values_1[] = {element_1};
  Status status = assert(list, 1, exp_values_1, act_status, Success, &is_int_ptr_equal);
  print_message(status, "should add element at the end in an empty list");

  Element element_2 = malloc(sizeof(int));
  *(int *)element_2 = 3;
  act_status = add_to_list(list, element_2);

  Element exp_values_2[] = {element_1, element_2};
  status = assert(list, 2, exp_values_2, act_status, Success, &is_int_ptr_equal);
  print_message(status, "should add element at the end in a non-empty list");
}

void test_add_to_start(void)
{
  describe("add_to_start");

  List_ptr list = create_list();
  Element element_1 = malloc(sizeof(int));
  *(int *)element_1 = 3;

  Status act_status = add_to_start(list, element_1);
  Element exp_values[] = {element_1};
  
  Status status = assert(list, 1, exp_values, act_status, Success, &is_int_ptr_equal);
  print_message(status, "should add element at the start in an empty list");

  Element element_2 = malloc(sizeof(int));
  *(int *)element_2 = 5;
  act_status = add_to_start(list, element_2);

  Element exp_values_2[] = {element_2, element_1};
  status = assert(list, 2, exp_values_2, act_status, Success, &is_int_ptr_equal);
  print_message(status, "should add element at the start in a non - empty list");
}