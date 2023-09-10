#include"eenheid/eenheid.h"

__EENHEID_INIT__

SUITE(person)
{
    TEST(person_create_code)
    {
        eenheid_assert_int32(-1, 15);
        eenheid_assert_str_size("matthiasbrunner", "mattwasauchimmer", 5);
        TEST_END
    }
}

__EENHEID_END__


