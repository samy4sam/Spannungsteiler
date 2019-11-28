/**
 * @file SpannungsteilerLogikTest.cpp
 * @author Philip Zellweger (philip.zellweger@hsr.ch)
 * @brief Unittests for class SpannungsteilerLogik
 * @version 1.0
 * @date 2019-11-28
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "gtest/gtest.h"
#include "spannungsteilerlogik.h"

/**
 * @brief Construct a new TEST object for getRes1 function
 * 
 */
TEST(SpannungsteilerLogikTest, getRes1)
{
    SpannungsteilerLogik stl;
    ASSERT_EQ(stl.getRes1(), 0.0);
}

/**
 * @brief Construct a new TEST object for getRes2 function
 * 
 */
TEST(SpannungsteilerLogikTest, getRes2)
{
    SpannungsteilerLogik stl;
    ASSERT_EQ(stl.getRes2(), 0.0);
}

/**
 * @brief Construct a new TEST object for calcSerieValue function
 * 
 */
TEST(SpannungsteilerLogikTest, calcSerieValue)
{
    SpannungsteilerLogik stl;
    stl.setSerie(serieList::E3);
    ASSERT_EQ(stl.calcSerieValue(0), 1.0);
    ASSERT_EQ(stl.calcSerieValue(1), 2.2);
    ASSERT_EQ(stl.calcSerieValue(2), 4.7);
}

/**
 * @brief Construct a new TEST object for selectResistor function
 * 
 */
TEST(SpannungsteilerLogikTest, selectResistor)
{
    SpannungsteilerLogik stl;
    stl.setSerie(serieList::E3);
    ASSERT_EQ(stl.selectResistor(15.99), 10.0);
    ASSERT_EQ(stl.selectResistor(16.0), 22.0);
    ASSERT_EQ(stl.selectResistor(34.49), 22.0);
    ASSERT_EQ(stl.selectResistor(34.5), 47.0);
}