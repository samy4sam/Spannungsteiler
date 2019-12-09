#include <gtest/gtest.h>
#include "../../src/SpannungsteilerLogik.h"

TEST(SpannungsteilerLogikTest, ctor_test)
{
  SpannungsteilerLogik* sptlr = new SpannungsteilerLogik();
  delete sptlr;
}

TEST(SpannungsteilerLogikTest, getRes1)
{
  SpannungsteilerLogik sptlr;
  EXPECT_EQ(sptlr.getRes1(), 0.0);
}

TEST(SpannungsteilerLogikTest, getRes2)
{
  SpannungsteilerLogik sptlr;
  EXPECT_EQ(sptlr.getRes2(), 0.0);
}

TEST(SpannungsteilerLogikTest, doCalc_iec)
{
  SpannungsteilerLogik sptlr;
  sptlr.setVol1(10);
  sptlr.setVol2(20);
  sptlr.setCur(1);
  sptlr.setSerie(SpannungsteilerLogik::serieList::E3);

  EXPECT_DEATH(
      sptlr.doCalc(),
      ".*SpannungsteilerLogik::doCalc.*Assertion `vol1 > vol2' failed.*");
}

TEST(SpannungsteilerLogikTest, doCalc_vec)
{
  SpannungsteilerLogik sptlr;
  sptlr.setVol1(12.00);
  sptlr.setVol2(4.00);
  sptlr.setCur(2.00);
  sptlr.setSerie(SpannungsteilerLogik::serieList::E3);
  sptlr.doCalc();

  EXPECT_EQ(sptlr.getRes1(), 4.70);
  EXPECT_EQ(sptlr.getRes2(), 2.20);
}
