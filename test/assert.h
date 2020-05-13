#ifndef __ASSERT_H_
#define __ASSERT_H_

#include <stdio.h> 
#include "../linkedlist.h"

typedef Status (*comparer)(Element, Element);

Status assert(List_ptr list, int length, Element exp_list_values[], Status act_status, Status exp_status, comparer);

Status is_int_ptr_equal(Element num1, Element num2);
Status is_int_equal(int num1, int num2);

Status assert_is_eq_ptr(Element ptr1, Element ptr2);
Status assert_is_not_eq_ptr(Element ptr1, Element ptr2);

void describe(char *function_name);
void print_message(Status status, char message[]);

#endif