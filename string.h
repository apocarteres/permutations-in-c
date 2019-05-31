#pragma once

#include <stdlib.h>

typedef struct _string {
  char *storage;
  size_t index;
} string;

string *new_string();

void append_string(string *, const string *);

void append_chars(string *, const char *);

void append_int(string *, const int);

size_t get_string_size(const string *);

const char* get_chars_from_string(const string *);

void print_string(const string *);

void destroy_string(string *);
