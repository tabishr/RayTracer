#include "RGBColor.hh"
#include <gtest/gtest.h>

// Google C++ Testing Framework
using namespace testing;

TEST(RGBColor, ConstructorZeros){
  RGBColor c1;
  float red = c1.get_red();
  float green = c1.get_green();
  float blue = c1.get_blue();

  ASSERT_FLOAT_EQ(red, 0);
  ASSERT_FLOAT_EQ(green, 0);
  ASSERT_FLOAT_EQ(blue, 0);
}

TEST(RGBColor, ConstructorNonZeros){
  RGBColor c1(0, 1, 2);
  
  float red = c1.get_red();

  ASSERT_FLOAT_EQ(red, 0);
  
  c1.set_red(2);
  red = c1.get_red();

  ASSERT_FLOAT_EQ(red, 2);
}

TEST(RGBColor, Addition){
  RGBColor c1(0, 1, 2);
  RGBColor c2(3, 4, 5);

  RGBColor result = c1 + c2;

  float red = result.get_red();
  float green = result.get_green();
  float blue = result.get_blue();

  ASSERT_FLOAT_EQ(red, 3);
  ASSERT_FLOAT_EQ(green, 5);
  ASSERT_FLOAT_EQ(blue, 7);
}

TEST(RGBColor, Subtraction){
  RGBColor c1(0, 1, 2);
  RGBColor c2(3, 4, 5);

  RGBColor result = c1 - c2;

  float red = result.get_red();
  float green = result.get_green();
  float blue = result.get_blue();

  ASSERT_FLOAT_EQ(red, -3);
  ASSERT_FLOAT_EQ(green, -3);
  ASSERT_FLOAT_EQ(blue, -3);
}

TEST(RGBColor, Multiplication){
  RGBColor c1(0, 1, 2);
  RGBColor c2(3, 4, 5);

  RGBColor result = c1 * c2;

  float red = result.get_red();
  float green = result.get_green();
  float blue = result.get_blue();

  ASSERT_FLOAT_EQ(red, 0);
  ASSERT_FLOAT_EQ(green, 4);
  ASSERT_FLOAT_EQ(blue, 10);
}

TEST(RGBColor, DestructiveAddition){
  RGBColor c1(0, 1, 2);
  RGBColor c2(3, 4, 5);

  c1 += c2;

  float red = c1.get_red();
  float green = c1.get_green();
  float blue = c1.get_blue();

  ASSERT_FLOAT_EQ(red, 3);
  ASSERT_FLOAT_EQ(green, 5);
  ASSERT_FLOAT_EQ(blue, 7);
}

TEST(RGBColor, DestructiveSubtraction){
  RGBColor c1(0, 1, 2);
  RGBColor c2(3, 4, 5);

  c1 -= c2;

  float red = c1.get_red();
  float green = c1.get_green();
  float blue = c1.get_blue();

  ASSERT_FLOAT_EQ(red, -3);
  ASSERT_FLOAT_EQ(green, -3);
  ASSERT_FLOAT_EQ(blue, -3);
}

TEST(RGBColor, DestructiveMultiplication){
  RGBColor c1(0, 1, 2);
  RGBColor c2(3, 4, 5);

  c1 *= c2;

  float red = c1.get_red();
  float green = c1.get_green();
  float blue = c1.get_blue();

  ASSERT_FLOAT_EQ(red, 0);
  ASSERT_FLOAT_EQ(green, 4);
  ASSERT_FLOAT_EQ(blue, 10);
}

TEST(RGBColor, ScalarMultiplication){
  RGBColor c1(0, 1, 2);

  RGBColor result = c1 * 2;

  float red = result.get_red();
  float green = result.get_green();
  float blue = result.get_blue();

  ASSERT_FLOAT_EQ(red, 0);
  ASSERT_FLOAT_EQ(green, 2);
  ASSERT_FLOAT_EQ(blue, 4);
}

TEST(RGBColor, ScalarDivision){
  RGBColor c1(0, 2, 4);

  RGBColor result = c1 / 2;

  float red = result.get_red();
  float green = result.get_green();
  float blue = result.get_blue();

  ASSERT_FLOAT_EQ(red, 0);
  ASSERT_FLOAT_EQ(green, 1);
  ASSERT_FLOAT_EQ(blue, 2);
}

TEST(RGBColor, DestructiveScalarMultiplication){
  RGBColor c1(0, 1, 2);

  c1 *= 2;

  float red = c1.get_red();
  float green = c1.get_green();
  float blue = c1.get_blue();

  ASSERT_FLOAT_EQ(red, 0);
  ASSERT_FLOAT_EQ(green, 2);
  ASSERT_FLOAT_EQ(blue, 4);
}

TEST(RGBColor, DestructiveScalarDivision){
  RGBColor c1(0, 2, 4);

  c1 /= 2;

  float red = c1.get_red();
  float green = c1.get_green();
  float blue = c1.get_blue();

  ASSERT_FLOAT_EQ(red, 0);
  ASSERT_FLOAT_EQ(green, 1);
  ASSERT_FLOAT_EQ(blue, 2);
}

TEST(RGBColor, ScalarMultiplicationRHS){
  RGBColor c1(0, 1, 2);

  RGBColor result = 2 * c1;

  float red = result.get_red();
  float green = result.get_green();
  float blue = result.get_blue();

  ASSERT_FLOAT_EQ(red, 0);
  ASSERT_FLOAT_EQ(green, 2);
  ASSERT_FLOAT_EQ(blue, 4);  
}

int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// g++ -Wall -I gtest-1.7.0/include gtest-1.7.0/make/gtest-all.o -pthread RGBColor.cc RGBColor_UnitTest.cc -o RGBColor_UnitTest
