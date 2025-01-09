#include"eenheid/eenheid.h"

__EENHEID_INIT__

SUITE(person)
{
    TEST(person_create_code)
    {
        eenheid_assert_str_size("matthiasbrunner", "mattwasauchimmer", 5);
        eenheid_assert_str("brunner", "brunner das auch");
    }
    TEST_END;

    TEST(was_auch_immer())
    {
        eenheid_assert(50 < 60);
        eenheid_assert_int8(60, 70);
    } TEST_END;
}

__EENHEID_END__


