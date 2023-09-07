#include"eenheid/eenheid.h"
#include<stddef.h>

int sum(int x, int y)
{
    return x + y;
}

__EENHEID_INIT__

SUITE(calculation sum)
{
    TEST(add)
    {
        int s = sum(17, 18);
        eenheid_assert_int32(36, s);
        eenheid_assert_int32(35, s);
        eenheid_assert_int32(6, s);
        TEST_END
    }
    TEST(max int)
    {
        eenheid_assert_str("matthias", "mattihas1");
        TEST_END
    }
}

__EENHEID_END__


