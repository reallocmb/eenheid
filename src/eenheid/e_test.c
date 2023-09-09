#include"eenheid_internal.h"

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define COLOR_DEFAULT "\x1B[0m"
#define COLOR_RED "\x1B[31m"
#define COLOR_GREEN "\x1B[32m"
#define COLOR_WHITE "\x1B[47m"

void eenheid_title_print(void)
{
    const char *TITLE = 
        "\x1B[32m"
        "\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\n"
        "\u258F                    \u2595\n"
        "\u258F     "COLOR_DEFAULT"UNIT TESTS"COLOR_GREEN"     \u2595\n"
        "\u258F     "COLOR_DEFAULT"[eenheid]"COLOR_GREEN"      \u2595\n"
        "\u258F                    \u2595\n"
        "\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\n"
        "\x1B[0m";

    printf("%s", TITLE);
}

void eenheid_assert(EenheidTest *eenheid_test, bool condition, char *file, uint32_t line)
{
    if (condition)
        eenheid_test->status = PASSED;
    else
    {
        eenheid_test->status = FAILED;
        char *message_error = malloc((strlen(file) + 52) * sizeof(*message_error));
        sprintf(message_error, "\nFILE: %s | LINE: %d", file, line);
        eenheid_test->message_error = realloc(eenheid_test->message_error, (eenheid_test->message_error_offset + strlen(message_error) + 1) * sizeof(char));
        strcpy(eenheid_test->message_error + eenheid_test->message_error_offset, message_error);
        eenheid_test->message_error_offset += strlen(message_error);
        free(message_error);
    }
}

void eenheid_assert_char(EenheidTest *eenheid_test, char expected, char received, char *file, uint32_t line)
{
    if (expected == received)
        eenheid_test->status = PASSED;
    else
    {
        eenheid_test->status = FAILED;
        char *message_error = malloc((strlen(file) + 1 + 1 + 11 + 1 + 52) * sizeof(*message_error));
        sprintf(message_error, "\nFILE: %s | LINE: %d -> expected: \"%c\" | received: \"%c\"", file, line, expected, received);
        eenheid_test->message_error = realloc(eenheid_test->message_error, (eenheid_test->message_error_offset + strlen(message_error) + 1) * sizeof(char));
        strcpy(eenheid_test->message_error + eenheid_test->message_error_offset, message_error);
        eenheid_test->message_error_offset += strlen(message_error);
        free(message_error);
    }
}

void eenheid_assert_str(EenheidTest *eenheid_test, char *expected, char *received, char *file, uint32_t line)
{
    if (strcmp(expected, received) == 0)
        eenheid_test->status = PASSED;
    else
    {
        eenheid_test->status = FAILED;
        char *message_error = malloc((strlen(file) + strlen(expected) + strlen(received) + 11 + 1 + 52) * sizeof(*message_error));
        sprintf(message_error, "\nFILE: %s | LINE: %d -> expected: \"%s\" | received: \"%s\"", file, line, expected, received);
        eenheid_test->message_error = realloc(eenheid_test->message_error, (eenheid_test->message_error_offset + strlen(message_error) + 1) * sizeof(char));
        strcpy(eenheid_test->message_error + eenheid_test->message_error_offset, message_error);
        eenheid_test->message_error_offset += strlen(message_error);
        free(message_error);
    }
}

void eenheid_assert_int8(EenheidTest *eenheid_test, int8_t expected, int8_t received, char *file, uint32_t line)
{
    if (expected == received)
        eenheid_test->status = PASSED;
    else
    {
        eenheid_test->status = FAILED;
        char *message_error = malloc((strlen(file) + 11 + 11 + 11 + 1 + 52) * sizeof(*message_error));
        sprintf(message_error, "\nFILE: %s | LINE: %d -> expected: %d | received: %d", file, line, expected, received);
        eenheid_test->message_error = realloc(eenheid_test->message_error, (eenheid_test->message_error_offset + strlen(message_error) + 1) * sizeof(char));
        strcpy(eenheid_test->message_error + eenheid_test->message_error_offset, message_error);
        eenheid_test->message_error_offset += strlen(message_error);
        free(message_error);
    }
}

void eenheid_assert_int32(EenheidTest *eenheid_test, int32_t expected, int32_t received, char *file, uint32_t line)
{
    if (expected == received)
        eenheid_test->status = PASSED;
    else
    {
        eenheid_test->status = FAILED;
        char *message_error = malloc((strlen(file) + 11 + 11 + 11 + 1 + 52) * sizeof(*message_error));
        sprintf(message_error, "\nFILE: %s | LINE: %d -> expected: %d | received: %d", file, line, expected, received);
        eenheid_test->message_error = realloc(eenheid_test->message_error, (eenheid_test->message_error_offset + strlen(message_error) + 1) * sizeof(char));
        strcpy(eenheid_test->message_error + eenheid_test->message_error_offset, message_error);
        eenheid_test->message_error_offset += strlen(message_error);
        free(message_error);
    }
}

void eenheid_assert_int64(EenheidTest *eenheid_test, int64_t expected, int64_t received, char *file, uint32_t line)
{
    if (expected == received)
        eenheid_test->status = PASSED;
    else
    {
        eenheid_test->status = FAILED;
        char *message_error = malloc((strlen(file) + 11 + 11 + 11 + 1 + 52) * sizeof(*message_error));
        sprintf(message_error, "\nFILE: %s | LINE: %d -> expected: %ld | received: %ld", file, line, expected, received);
        eenheid_test->message_error = realloc(eenheid_test->message_error, (eenheid_test->message_error_offset + strlen(message_error) + 1) * sizeof(char));
        strcpy(eenheid_test->message_error + eenheid_test->message_error_offset, message_error);
        eenheid_test->message_error_offset += strlen(message_error);
        free(message_error);
    }
}

void ennheid_assert_uint32(EenheidTest *eenheid_test, uint32_t expected, uint32_t received, char *file, uint32_t line)
{
    if (expected == received)
        eenheid_test->status = PASSED;
    else
    {
        eenheid_test->status = FAILED;
        char *message_error = malloc((strlen(file) + 11 + 11 + 11 + 1 + 52) * sizeof(*message_error));
        sprintf(message_error, "\nFILE: %s | LINE: %u -> expected: %u | received: %u", file, line, expected, received);
        eenheid_test->message_error = realloc(eenheid_test->message_error, (eenheid_test->message_error_offset + strlen(message_error) + 1) * sizeof(char));
        strcpy(eenheid_test->message_error + eenheid_test->message_error_offset, message_error);
        eenheid_test->message_error_offset += strlen(message_error);
        free(message_error);
    }
}

void eenheid_test_create(EenheidTest *eenheid_test, char *suite, char *test)
{
    eenheid_test->test_old = eenheid_test->test;
    eenheid_test->test = test;
    eenheid_test->status = PENDING;
}

void eenheid_test_clean(EenheidTest *eenheid_test)
{
    if (eenheid_test->test[0] != 0)
    {
        if (eenheid_test->status == PASSED)
        {
            eenheid_test->status_sign = "\x1b[32m\u2714\x1b[0m";
            eenheid_test->passed_count++;
        }
        else if (eenheid_test->status == FAILED)
        {
            eenheid_test->status_sign = "\x1b[31m\u2718\x1b[0m";
            eenheid_test->failed_count++;
        }
        else
            eenheid_test->status_sign = "-";

        printf("%s %s" COLOR_RED "%s" COLOR_DEFAULT, eenheid_test->status_sign, eenheid_test->test, eenheid_test->message_error);
        putchar('\n');
        eenheid_test->test_old = eenheid_test->test;
        eenheid_test->message_error_offset = 0;
    }
}

void eenheid_suite_create(EenheidTest *eenheid_test, char *suite)
{
    eenheid_test->suite_old = eenheid_test->suite;
    eenheid_test->suite = suite;
}

void eenheid_suite_clean(EenheidTest *eenheid_test)
{
    if (strcmp(eenheid_test->suite_old, eenheid_test->suite) != 0)
    {
        printf("%s\n", eenheid_test->suite);
    }
}

void eenheid_stats_print(EenheidTest *eenheid_test)
{
    putchar('\n');
    printf(COLOR_GREEN "PASSED: %5d\n", eenheid_test->passed_count);
    printf(COLOR_RED "FAILED: %5d\n", eenheid_test->failed_count);
    printf(COLOR_DEFAULT "PENDING: %4d\n", eenheid_test->pending_count - (eenheid_test->passed_count + eenheid_test->failed_count));
}
