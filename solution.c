#include "string-list.h"
#include "string.h"
#include <assert.h>
#include <stdio.h>

#define SAMPLE_LENGTH 3

int calc(const int remainder, int index, const int nums[SAMPLE_LENGTH],
         const string *root, string_list *list) {
  if (remainder == 0) {
    add_string(list, root);
    return 1;
  }
  if (remainder < 0) {
    return 0;
  }
  int count = 0;
  for (int i = 0; i < SAMPLE_LENGTH; ++i) {
    string *s = new_string();
    append_string(s, root);
    append_int(s, nums[i]);
    count += calc(remainder - nums[i], i, nums, s, list);
    destroy_string(s);
  }
  return count;
}

void readNum(const char *msg, int *value) {
  printf("%s[1-10]: ", msg);
  scanf("%d", value);
  assert(*value >= 1 && *value < 10);
}

void calcAndPrint(int n, int a, int b, int c) {
  const int nums[SAMPLE_LENGTH] = {a, b, c};
  string_list *list = new_string_list();
  string *s = new_string();
  printf("for n=%d the answer is %d\n", n, calc(n, 0, nums, s, list));
  print_string_list(list);
  destroy_string_list(list);
  destroy_string(s);
}

int main(int argc, char **argv) {
  int a, b, c, n;
  printf("please input your numbers:\n");
  printf("n: ");
  scanf("%d", &n);
  assert(n > 0);
  readNum("a", &a);
  readNum("b", &b);
  readNum("c", &c);

  calcAndPrint(n, a, b, c);
}
