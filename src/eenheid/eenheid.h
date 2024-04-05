#ifndef EENHEID_H
#define EENHEID_H

#include"eenheid_internal.h"

#include<stdlib.h>

/* ASSERT Functions */
#define eenheid_assert(condition) eenheid_assert(&eenheid_test, condition, __FILE__, __LINE__)
#define eenheid_assert_char(received, expected) eenheid_assert_char(&eenheid_test, received, expected, __FILE__, __LINE__)
#define eenheid_assert_str(received, expected) eenheid_assert_str(&eenheid_test, received, expected, __FILE__, __LINE__)
#define eenheid_assert_str_size(received, expected, size) eenheid_assert_str_size(&eenheid_test, received, expected, size, __FILE__, __LINE__)
#define eenheid_assert_sint(received, expected) eenheid_assert_sint(&eenheid_test, received, expected, __FILE__, __LINE__)
#define eenheid_assert_uint(received, expected) eenheid_assert_uint(&eenheid_test, received, expected, __FILE__, __LINE__)

#define __EENHEID_INIT__ \
    EenheidTest eenheid_test = { \
        .test = "", \
        .suite = "", \
        .test_old = "", \
        .suite_old = "", \
        .status_sign = "", \
        .message_error_offset = 0, \
    }; \
int main(void) \
{ \
    eenheid_test.message_error = malloc(sizeof(*eenheid_test.message_error)); \
    eenheid_test.message_error[0] = 0; \
    eenheid_title_print(); \

#define SUITE(suite) \
    eenheid_suite_create(&eenheid_test, #suite); \
    eenheid_suite_clean(&eenheid_test); \

#define SUITE_END \
    eenheid_suite_clean(&eenheid_test); \

#define TEST(test) \
    eenheid_test_create(&eenheid_test, #test); \
    eenheid_test.pending_count++; \

#define TEST_END \
    eenheid_test_clean(&eenheid_test); \

#define __EENHEID_END__ \
    eenheid_stats_print(&eenheid_test); \
    return 0; \
} \

#endif
