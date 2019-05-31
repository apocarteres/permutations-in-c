#include "string-list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 128

void add_string(string_list *s, const string *text) {
  assert(s->index < MAX_STRINGS);
  size_t size = get_string_size(text);
  *(s->storage + s->index) = calloc(size, 1);
  memcpy(*(s->storage + s->index), get_chars_from_string(text), size);
  ++s->index;
}

string_list *new_string_list() {
  string_list *s = malloc(sizeof(string_list));
  s->storage = calloc(MAX_STRINGS, sizeof(char *));
  s->index = 0;
  return s;
}

void destroy_string_list(string_list *s) {
  for (int i = 0; i < s->index; ++i) {
    free(*(s->storage + i));
  }
  free(s->storage);
  free(s);
}

void print_string_list(string_list *s) {
  for (int i = 0; i < s->index; ++i) {
    printf("%s\n", (*(s->storage + i)));
  }
}
