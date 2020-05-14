#include "assert.h"
#include "../linkedlist.h"

void test_reverse_list(void)
{
  describe("reverse_list");

  List_ptr list = create_list();

  Element element_1 = malloc(sizeof(int));
  *(int *)element_1 = 4;
  Element element_2 = malloc(sizeof(int));
  *(int *)element_2 = 3;
  Element element_3 = malloc(sizeof(int));
  *(int *)element_3 = 5;

  Element act_values[] = {element_1, element_2, element_3};
  Element exp_values[] = {element_3, element_2, element_1};

  List_ptr reversed_list = reverse(list);
  Status status = assert(list, 0, act_values, Success, Success, &is_int_ptr_equal);
  print_message(status, "shouldn't do anything to an empty list");

  status = assert(reversed_list, 0, exp_values, Success, Success, &is_int_ptr_equal);
  print_message(status, "should return an empty list when the actual list was empty");

  add_to_list(list, element_1);
  add_to_list(list, element_2);
  add_to_list(list, element_3);

  reversed_list = reverse(list);
  status = assert(list, 3, act_values, Success, Success, &is_int_ptr_equal);
  print_message(status, "shouldn't do anything to the given list");

  status = assert(reversed_list, 3, exp_values, Success, Success, &is_int_ptr_equal);
  print_message(status, "should return an reversed list of actual list");

  clear_list(list);
  clear_list(reversed_list);
}

Element get_double(Element element)
{
  Element doubled_element = malloc(sizeof(int));
  *((int *)doubled_element) = *(int *)element * 2;
  return doubled_element;
}

void test_map(void)
{
  describe("map_list");

  List_ptr list = create_list();

  Element element_1 = malloc(sizeof(int));
  *(int *)element_1 = 4;
  Element element_2 = malloc(sizeof(int));
  *(int *)element_2 = 3;
  Element element_3 = malloc(sizeof(int));
  *(int *)element_3 = 5;

  Element exp_1 = malloc(sizeof(int));
  *(int *)exp_1 = 8;
  Element exp_2 = malloc(sizeof(int));
  *(int *)exp_2 = 6;
  Element exp_3 = malloc(sizeof(int));
  *(int *)exp_3 = 10;

  Element act_values[] = {element_1, element_2, element_3};
  Element exp_values[] = {exp_1, exp_2, exp_3};

  List_ptr mapped_list = map(list, &get_double);
  Status status = assert(list, 0, act_values, Success, Success, &is_int_ptr_equal);
  print_message(status, "shouldn't do anything to an empty list");

  status = assert(mapped_list, 0, exp_values, Success, Success, &is_int_ptr_equal);
  print_message(status, "should return an empty list when the actual list was empty");

  add_to_list(list, element_1);
  add_to_list(list, element_2);
  add_to_list(list, element_3);

  mapped_list = map(list, &get_double);
  status = assert(list, 3, act_values, Success, Success, &is_int_ptr_equal);
  print_message(status, "shouldn't do anything to the given list");

  status = assert(mapped_list, 3, exp_values, Success, Success, &is_int_ptr_equal);
  print_message(status, "should return an mapped list of actual list");

  clear_list(list);
  clear_list(mapped_list);
}