/* Example code for Software Systems at Olin College.

Copyright 2017 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "util.h"
#include "minunit.h"

int tests_run = 0;

static char *test1() {
    char * = icmpcode_v4(0)
    char *message = "test1 failed: icmpcode_v4(0) should return network unreachable";
    mu_assert(message, res == "network unreachable");
    return NULL;
}

static char *test2() {
  char * = icmpcode_v4(4)
  char *message = "test1 failed: icmpcode_v4(4) should return fragmentation required but DF bit set";
  mu_assert(message, res == "fragmentation required but DF bit set");
  return NULL;
}

static char *test3() {
  char * = icmpcode_v4(12)
  char *message = "test1 failed: icmpcode_v4(12) should return host unreachable for TOS";
  mu_assert(message, res == "host unreachable for TOS");
  return NULL;
}

static char * all_tests() {
    mu_run_test(test1);
    mu_run_test(test2);
    mu_run_test(test3);
    return NULL;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
