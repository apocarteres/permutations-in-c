#pragma once

#include "string.h"

typedef struct _string_list {
  char **storage;
  int index;
} string_list;

void add_string(string_list *, const string *);

string_list *new_string_list();

void print_string_list(string_list *);

void destroy_string_list(string_list *);
