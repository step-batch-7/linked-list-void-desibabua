#include "assert.h"

void describe(char *function_name)
{
  printf("\n # %s\n\n", function_name);
}

void it(char *message, Status status)
{
  char *symbol = status ? "✓" : "✘";
  printf("  %s %s\n",symbol, message);
}