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

Status clear_list(List_ptr list) {
  Node_ptr p_walk = list->first;
  Node_ptr node_to_remove;

  while (p_walk != NULL) {
    node_to_remove = p_walk;
    p_walk = p_walk->next;
    free(node_to_remove);
  }

  list->first = NULL;
  list->last = NULL;
  list->length = 0;
  return Success;
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

Status is_in_list(List_ptr list,Element element, Matcher matcher) {
  Node_ptr p_walk = list->first;
  while (p_walk != NULL) {
    if((*matcher)(p_walk->element, element)) {
      return Success;
    }
    p_walk = p_walk->next;
  }
  return Failure;
}

Status add_unique(List_ptr list, Element element, Matcher matcher) {
  Node_ptr node;

  if (!is_in_list(list, element, matcher)) {
    return add_to_list(list, element);
  }
  return Failure;
}

Element remove_from_start(List_ptr list) 
{
  return remove_at(list, 0);
}

Element remove_from_end(List_ptr list) 
{
  return remove_at(list, list->length - 1);
}

Element remove_at(List_ptr list, int position) 
{
  if(position >= list->length || position < 0)
  {
    return NULL;
  }

  Prev_Current_Pair node_ptrs;
  node_ptrs.prev = NULL;
  node_ptrs.current = list->first;

  while(position > 0){
    node_ptrs.prev = node_ptrs.current;
    node_ptrs.current = node_ptrs.current->next;
    position--;
  }

  Node_ptr node_to_remove = node_ptrs.current;
  Node_ptr *ptr_to_set = &list->first;

  if (node_ptrs.prev != NULL)
  {
    ptr_to_set = &node_ptrs.prev->next;
  }

  *ptr_to_set = node_ptrs.current->next;

  if(node_ptrs.current->next==NULL){
    list->last = node_ptrs.prev;
  }
  
  list->length--;
  Element removed_element = node_to_remove->element;
  free(node_to_remove);
  return removed_element;
}

Element remove_first_occurrence(List_ptr list, Element element, Matcher matcher) {
  Node_ptr p_walk = list->first;
  int position = 0;

  if(!is_in_list(list,element,matcher)) {
    return NULL;
  }
  while (!(*matcher)(p_walk->element ,element))
  {
    p_walk = p_walk->next;
    position++;
  }

  return remove_at(list, position);
}

List_ptr remove_all_occurrences(List_ptr list, Element element, Matcher matcher) 
{
  List_ptr removed_element_list = create_list();
  Element new_element = remove_first_occurrence(list, element, matcher);

  while (new_element != NULL)
  {
    add_to_list(removed_element_list, new_element);
    new_element = remove_first_occurrence(list, element, matcher);
  }

  return removed_element_list;
}

List_ptr reverse(List_ptr list)
{
  List_ptr reversed_list = create_list();
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    add_to_start(reversed_list, p_walk->element);
    p_walk = p_walk->next;
  }
  return reversed_list;
}

List_ptr map(List_ptr list, Mapper mapper)
{
  List_ptr mapped_list = create_list();
  Node_ptr p_walk = list->first;
  Element element;
  while (p_walk != NULL)
  {
    element = (*mapper)(p_walk->element);
    add_to_list(mapped_list, element);
    p_walk = p_walk->next;
  }
  return mapped_list;
}

List_ptr filter(List_ptr list, Predicate predicate)
{
  List_ptr filtered_list = create_list();
  Node_ptr p_walk = list->first;
  Status status;
  while (p_walk != NULL)
  {
    if((*predicate)(p_walk->element))
    {
      add_to_list(filtered_list, p_walk->element);
    }
    p_walk = p_walk->next;
  }
  return filtered_list;
}