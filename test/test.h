#ifndef __TEST_H_
#define __TEST_H_

#include "assert.h"

void test_create_list(void);
void test_clear_list(void);

void test_add_to_list(void);
void test_add_to_start(void);
void test_insert_in_middle(void);

void test_add_unique(void);

void test_remove_from_start(void);
void test_remove_from_end(void);
void test_remove_at(void);

void test_remove_first_occurrance(void);
void test_remove_all_occurrances(void);

void test_reverse_list(void);

void test_map(void);
void test_filter(void);
void test_reduce(void);
void test_for_each(void);

#endif