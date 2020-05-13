#include "linkedlist.h"

Node_ptr create_node(Element element)
{
  Node_ptr node = malloc(sizeof(Node));
  node->element = element;
  node->next = NULL;

  return node;
}

List_ptr create_list(void)
{
  List_ptr list = malloc(sizeof(LinkedList));
  list->first = NULL;
  list->last = NULL;
  list->length = 0;
  
  return list;
}

Status add_to_list(List_ptr list,Element element) 
{
  return insert_at(list, element, list->length);
}

Status add_to_start(List_ptr list,Element element) 
{
  return insert_at(list, element, 0);
}

Status insert_at(List_ptr list,Element element, int position) 
{
  if(position < 0 || position > list->length)
  {
    return Failure;
  }

  Node_ptr node = create_node(element);
  Prev_Current_Pair nodes_ptrs;
  nodes_ptrs.prev = NULL;
  nodes_ptrs.current = list->first;

  if (list->length == 0 || list->length == position)
  {
    list->last = node;
  }

  while(position != 0)
  {
    nodes_ptrs.prev = nodes_ptrs.current;
    nodes_ptrs.current = nodes_ptrs.current->next;
    position--;
  }

  Node_ptr *ptr_to_set = &list->first;
  if (nodes_ptrs.prev != NULL)
  {
    ptr_to_set = &nodes_ptrs.prev->next;
  }

  *ptr_to_set = node;
  node->next = nodes_ptrs.current;
  list->length++;
  return Success;
}
