#include"unicki/unicki.h"
#include<stddef.h>

int sum(int x, int y)
{
    return x + y;
}

TEST_INIT;

TEST(calculation, sum)
{
    int s = sum(8, 7);
    unicki_assert((s == 15));
}

TEST(calculation, genau)
{
    unicki_assert(15 == 15);
    unicki_assert(20 == 19);
}

TEST(test_und_so, ganzorke)
{
    unicki_assert(17 == 18);
}

TEST_END;
