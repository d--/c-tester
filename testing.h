#pragma once
#include <stdio.h>

typedef struct {
    char *text;
    int result;
} test;

#define DEF_TEST(S) test _CURRENT_TEST = { S }; \
   _CURRENT_TEST.result = 0;

#define RUN_TEST(T) test test_##T = T(); \
    char* pass_##T = "\033[32mPASS"; \
    char* fail_##T = "\033[31mFAILURE!"; \
    char* status_##T = pass_##T; \
    if (test_##T.result != 0) { \
        status_##T = fail_##T; \
    } \
    printf("%s\033[m -- (%s) %s\n", status_##T, #T, test_##T.text);

#define DO_TEST(A,S) if (!(A)) { \
        _CURRENT_TEST.result = 1; \
        printf("\033[31mFAILED: %s\033[m\n", S); \
    }

#define END_TEST return _CURRENT_TEST

