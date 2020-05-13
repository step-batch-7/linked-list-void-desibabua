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

void test_clear_list(void)
{
  describe("clear_list");

  List_ptr list = create_list();

  Element element_1 = malloc(sizeof(int));
  *(int *)element_1 = 4;
  Element element_2 = malloc(sizeof(int));
  *(int *)element_2 = 3;

  Element exp_values[] = {};
  add_to_list(list, element_1);
  add_to_list(list, element_2);

  Status act_status = clear_list(list);

  Status status = assert(list, 0, exp_values, act_status, Success, &is_int_ptr_equal);
  print_message(status, "should clear the least elements");

  status = assert_is_eq_ptr(list->first, NULL);
  print_message(status, "should set list's first to null");

  status = assert_is_eq_ptr(list->last, NULL);
  print_message(status, "should set list's last to null");

  status = is_int_equal(list->length, 0);
  print_message(status, "should reset list's length");
}

void test_add_to_list(void)
{
  describe("add_to_list");

  List_ptr list = create_list();

  Element element_1 = malloc(sizeof(int));
  *(int *)element_1 = 4;
  Element element_2 = malloc(sizeof(int));
  *(int *)element_2 = 3;

  Element exp_values[] = {element_1, element_2};
  Status act_status = add_to_list(list, element_1);

  Status status = assert(list, 1, exp_values, act_status, Success, &is_int_ptr_equal);
  print_message(status, "should add element at the end in an empty list");

  act_status = add_to_list(list, element_2);

  status = assert(list, 2, exp_values, act_status, Success, &is_int_ptr_equal);
  print_message(status, "should add element at the end in a non-empty list");

  clear_list(list);
}

void test_add_to_start(void)
{
  describe("add_to_start");

  List_ptr list = create_list();

  Element element_1 = malloc(sizeof(int));
  *(int *)element_1 = 3;
  Element element_2 = malloc(sizeof(int));
  *(int *)element_2 = 5;

  Element exp_values_1[] = {element_1};
  Element exp_values_2[] = {element_2, element_1};

  Status act_status = add_to_start(list, element_1);
  
  Status status = assert(list, 1, exp_values_1, act_status, Success, &is_int_ptr_equal);
  print_message(status, "should add element at the start in an empty list");

  act_status = add_to_start(list, element_2);

  status = assert(list, 2, exp_values_2, act_status, Success, &is_int_ptr_equal);
  print_message(status, "should add element at the start in a non - empty list");

  clear_list(list);
}

void test_insert_in_middle(void)
{
  describe("add_to_middle");

  List_ptr list = create_list();

  Element element_1 = malloc(sizeof(int));
  *(int *)element_1 = 3;
  Element element_2 = malloc(sizeof(int));
  *(int *)element_2 = 5;
  Element element_3 = malloc(sizeof(int));
  *(int *)element_3 = 4;

  Element exp_values_1[] = {};
  Element exp_values_2[] = {element_1, element_3, element_2};

  Status act_status = insert_at(list, element_1, -1);

  Status status = assert(list, 0, exp_values_1, act_status, Failure, &is_int_ptr_equal);
  print_message(status, "should not add for an invalid position");

  status = assert(list, 0, exp_values_1, act_status, Failure, &is_int_ptr_equal);
  print_message(status, "should not add for a position greater than length");

  add_to_list(list, element_1);
  add_to_list(list, element_2);
  act_status = insert_at(list, element_3, 1);

  status = assert(list, 3, exp_values_2, act_status, Success, &is_int_ptr_equal);
  print_message(status, "should add element in between two elements of list");

  clear_list(list);
}

void test_add_unique(void)
{
  describe("add_unique_list");

  List_ptr list = create_list();

  Element element_1 = malloc(sizeof(int));
  *(int *)element_1 = 4;
  Element element_2 = malloc(sizeof(int));
  *(int *)element_2 = 3;

  Element exp_values[] = {element_1, element_2};

  Status act_status = add_unique(list, element_1, &is_int_ptr_equal);
  Status status = assert(list, 1, exp_values, act_status, Success, &is_int_ptr_equal);
  print_message(status, "should always add element in an empty list");

  act_status = add_unique(list, element_2, &is_int_ptr_equal);
  status = assert(list, 2, exp_values, act_status, Success, &is_int_ptr_equal);
  print_message(status, "should add element in list if not present");

  act_status = add_unique(list, element_2, &is_int_ptr_equal);
  status = assert(list, 2, exp_values, act_status, Failure, &is_int_ptr_equal);
  print_message(status, "should not add element in list if not present");

  clear_list(list);
}

void test_remove_from_start(void)
{
  describe("remove_from_start");

  List_ptr list = create_list();

  Element element_1 = malloc(sizeof(int));
  *(int *)element_1 = 4;
  Element element_2 = malloc(sizeof(int));
  *(int *)element_2 = 3;

  Element exp_values[] = { element_2 };

  Element removed_element = remove_from_start(list);
  Status status = assert(list, 0, exp_values, Success, Success, &is_int_ptr_equal);
  print_message(status, "should not remove the element from an list");

  status = assert_is_eq_ptr(removed_element, NULL);
  print_message(status, "should return null when asked to remove from empty list");

  add_to_list(list, element_1);
  add_to_list(list, element_2);

  removed_element = remove_from_start(list);
  status = assert(list, 1, exp_values, Success, Success, &is_int_ptr_equal);
  print_message(status, "should remove the element from list");

  status = is_int_ptr_equal(removed_element, element_1);
  print_message(status, "function should return the removed element");

  removed_element = remove_from_start(list);
  
  status &= assert_is_eq_ptr(list->first, NULL);
  status &= assert_is_eq_ptr(list->last, NULL);
  status &= is_int_equal(list->length, 0);
  print_message(status, "should reset all the values when list has nothing left");

  clear_list(list);
}
