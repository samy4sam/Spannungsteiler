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

TEST(SpannungsteilerLogikTest, calcSerieValue)
{
    SpannungsteilerLogik stl;
    stl.setSerie(serieList::E3);
    ASSERT_EQ(stl.calcSerieValue(0), 1.0);
    ASSERT_EQ(stl.calcSerieValue(1), 2.2);
    ASSERT_EQ(stl.calcSerieValue(2), 4.7);
}

