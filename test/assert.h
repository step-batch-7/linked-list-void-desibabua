#ifndef __ASSERT_H_
#define __ASSERT_H_

#include <stdio.h> 
#include "../linkedlist.h"

typedef Status (*is_equal)(void *,void *);

void describe(char *function_name);
void it(char *message, Status status);

#endif