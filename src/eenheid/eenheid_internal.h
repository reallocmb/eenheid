#ifndef EENHEID_INTERNAL_H
#define EENHEID_INTERNAL_H

#define EENHEID_VERSION_MAJOR 0
#define EENHEID_VERSION_MINOR 0
#define EENHEID_VERSION_PATCH 0

#include<stdint.h>
#include<stdbool.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

#define EENHEID_TESTS_ALLOC 2

enum { PASSED, FAILED, PENDING };

typedef struct {
    char *suite_old;
    char *test_old;
    char *suite;
    char *test;
    uint8_t status;
    char *status_sign;
    uint32_t passed_count;
    uint32_t failed_count;
    uint32_t pending_count;
    char *message_error;
    uint32_t message_error_offset;
} EenheidTest;

void eenheid_title_print(void);
void eenheid_test_create(EenheidTest *eenheid_test, char *test);
void eenheid_test_clean(EenheidTest *eenheid_test);
void eenheid_stats_print(EenheidTest *eenheid_test);
void eenheid_suite_create(EenheidTest *eenheid_test, char *suite);
void eenheid_suite_clean(EenheidTest *eenheid_test);

void eenheid_assert(EenheidTest *eenheid_test, bool condition, char *file, u32 line);
void eenheid_assert_char(EenheidTest *eenheid_test, char received, char expected, char *file, u32 line);
void eenheid_assert_str(EenheidTest *eenheid_test, char *received, char *expected, char *file, u32 line);
void eenheid_assert_str_size(EenheidTest *eenheid_test, char *received, char *expected, u32 size, char *file, u32 line);
void eenheid_assert_sint(EenheidTest *eenheid_test, s64 received, s64 expected, char *file, u32 liene);
void eenheid_assert_uint(EenheidTest *eenheid_test, u64 received, u64 expected, char *file, u32 liene);

#endif
