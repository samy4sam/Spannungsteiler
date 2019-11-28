#include "gtest/gtest.h"
#include "spannungsteilerlogik.h"

TEST(SpannungsteilerLogikTest, getRes1)
{
    SpannungsteilerLogik stl;
    ASSERT_EQ(stl.getRes1(), 0.0);
}

TEST(SpannungsteilerLogikTest, getRes2)
{
    SpannungsteilerLogik stl;
    ASSERT_EQ(stl.getRes2(), 0.0);
}