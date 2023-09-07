#ifndef EENHEID_H
#define EENHEID_H

#include"eenheid_internal.h"

#include<stdbool.h>

#define EENHEID_VERSION_MAJOR 0
#define EENHEID_VERSION_MINOR 0
#define EENHEID_VERSION_PATCH 0


void eenheid_assert(EenheidTest *eenheid_test, bool condition, char *file, uint32_t line);
void eenheid_assert_str(EenheidTest *eenheid_test, char *expected, char *received, char *file, int32_t line);
void eenheid_assert_int32(EenheidTest *eenheid_test, int8_t expected, int8_t received, char *file, int32_t line);

#define eenheid_assert(condition) eenheid_assert(&eenheid_test, condition, __FILE__, __LINE__)
#define eenheid_assert_int32(expected, received) eenheid_assert_int32(&eenheid_test, expected, received, __FILE__, __LINE__)
#define eenheid_assert_str(expected, received) eenheid_assert_str(&eenheid_test, expected, received, __FILE__, __LINE__)

void eenheid_title_print(void);
void eenheid_test_create(EenheidTest *eenheid_test, char *suite, char *test);
void eenheid_test_clean(EenheidTest *eenheid_test);
void eenheid_stats_print(EenheidTest *eenheid_test);
void eenheid_suite_create(EenheidTest *eenheid_test, char *suite);
void eenheid_suite_clean(EenheidTest *eenheid_test);

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
    eenheid_title_print(); \

#define SUITE(suite) \
    eenheid_suite_create(&eenheid_test, #suite); \
    eenheid_suite_clean(&eenheid_test); \

#define SUITE_END \
    eenheid_suite_clean(&eenheid_test); \

#define TEST(test) \
    eenheid_test_create(&eenheid_test, "", #test); \
    eenheid_test.pending_count++; \

#define TEST_END \
    eenheid_test_clean(&eenheid_test); \

#define __EENHEID_END__ \
    eenheid_stats_print(&eenheid_test); \
    return 0; \
} \

#endif
