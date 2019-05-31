#include "string.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define STRING_LENGTH 32

string *new_string() {
  string *s = malloc(sizeof(string));
  s->storage = calloc(STRING_LENGTH, sizeof(char));
  s->index = 0;
  return s;
}

const char* get_chars_from_string(const string *s) {
  return s->storage;
}

size_t get_string_size(const string *s) { return s->index; }

void print_string(const string *s) {
  printf("%s\n", s->storage);
}

void append_chars(string *s, const char *string) {
  size_t len = strlen(string) * sizeof(char);
  if (len < 1) {
    return;
  }
  assert(s->index + len < STRING_LENGTH);
  memcpy(s->storage + s->index, string, len);
  s->index += len;
}

void append_string(string *s, const string *string) {
  append_chars(s, string->storage);
}

void append_int(string *s, const int value) {
  char num[8];
  sprintf(num, "%d", value);
  append_chars(s, num);
}

void destroy_string(string *s) {
  free(s->storage);
  free(s);
}

void reset_string(string *s) {
  memset(s->storage, 0, s->index);
  s->index = 0;
}
