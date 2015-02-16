#include "Vector3F.hh"
#include <gtest/gtest.h>
#include <cmath>

// Google C++ Testing Framework
using namespace testing;

TEST(Vector3FTest, ConstructorZeros){
  Vector3F v;
  float x = v(0);
  float y = v(1);
  float z = v(2);

  ASSERT_FLOAT_EQ(x, 0);
  ASSERT_FLOAT_EQ(y, 0);
  ASSERT_FLOAT_EQ(z, 0);
}

TEST(Vector3FTest, ConstructorNonZeros){
  Vector3F v(1, 1, 1);
  float x = v(0);
  float y = v(1);
  float z = v(2);

  ASSERT_FLOAT_EQ(x, 1);
  ASSERT_FLOAT_EQ(y, 1);
  ASSERT_FLOAT_EQ(z, 1);
}

TEST(Vector3FTest, OperatorPlusEqual){
  Vector3F v1(1, 1, 1);
  Vector3F v2(2, 0, -2);

  v1 += v2;
 
  float x = v1(0);
  float y = v1(1);
  float z = v1(2);

  ASSERT_FLOAT_EQ(x, 3);
  ASSERT_FLOAT_EQ(y, 1);
  ASSERT_FLOAT_EQ(z, -1);
}

TEST(Vector3FTest, OperatorMinusEqual){
  Vector3F v1(1, 1, 1);
  Vector3F v2(2, 0, -2);

  v1 -= v2;
 
  float x = v1(0);
  float y = v1(1);
  float z = v1(2);

  ASSERT_FLOAT_EQ(x, -1);
  ASSERT_FLOAT_EQ(y, 1);
  ASSERT_FLOAT_EQ(z, 3);
}

TEST(Vector3FTest, OperatorPlus){
  Vector3F v1(1, 1, 1);
  Vector3F v2(2, 0, -2);
  Vector3F result = v1 + v2;
 
  float x = result(0);
  float y = result(1);
  float z = result(2);

  ASSERT_FLOAT_EQ(x, 3);
  ASSERT_FLOAT_EQ(y, 1);
  ASSERT_FLOAT_EQ(z, -1);
}

TEST(Vector3FTest, OperatorMinus){
  Vector3F v1(1, 1, 1);
  Vector3F v2(2, 0, -2);
  Vector3F result = v1 - v2;
 
  float x = result(0);
  float y = result(1);
  float z = result(2);

  ASSERT_FLOAT_EQ(x, -1);
  ASSERT_FLOAT_EQ(y, 1);
  ASSERT_FLOAT_EQ(z, 3);
}

TEST(Vector3FTest, OperatorUnaryNegative){
  Vector3F v1(1, 0, -1);
  Vector3F result = -v1;

  float x = result(0);
  float y = result(1);
  float z = result(2);

  ASSERT_FLOAT_EQ(x, -1);
  ASSERT_FLOAT_EQ(y, 0);
  ASSERT_FLOAT_EQ(z, 1);  
}

TEST(Vector3FTest, OperatorMultEqual){
  Vector3F v1(0, 1, -1);
  v1 *= 2;

  float x = v1(0);
  float y = v1(1);
  float z = v1(2);

  ASSERT_FLOAT_EQ(x, 0);
  ASSERT_FLOAT_EQ(y, 2);
  ASSERT_FLOAT_EQ(z, -2);  
}

TEST(Vector3FTest, OperatorDivEqual){
  Vector3F v1(0, 2, -2);
  v1 /= 2;

  float x = v1(0);
  float y = v1(1);
  float z = v1(2);

  ASSERT_FLOAT_EQ(x, 0);
  ASSERT_FLOAT_EQ(y, 1);
  ASSERT_FLOAT_EQ(z, -1);  
}

TEST(Vector3FTest, OperatorMultRHS){
  Vector3F v1(0, 2, -2);
  Vector3F result = (float)2.0 * v1;

  float x = result(0);
  float y = result(1);
  float z = result(2);

  ASSERT_FLOAT_EQ(x, 0);
  ASSERT_FLOAT_EQ(y, 4);
  ASSERT_FLOAT_EQ(z, -4);  
}

TEST(Vector3FTest, OperatorMultLHS){
  Vector3F v1(0, 2, -2);
  Vector3F result = v1 * (float)2.0;

  float x = result(0);
  float y = result(1);
  float z = result(2);

  ASSERT_FLOAT_EQ(x, 0);
  ASSERT_FLOAT_EQ(y, 4);
  ASSERT_FLOAT_EQ(z, -4);  
}

TEST(Vector3FTest, OperatorDiv){
  Vector3F v1(0, 2, -2);
  Vector3F result = v1 / 2;

  float x = result(0);
  float y = result(1);
  float z = result(2);

  ASSERT_FLOAT_EQ(x, 0);
  ASSERT_FLOAT_EQ(y, 1);
  ASSERT_FLOAT_EQ(z, -1);  
}

TEST(Vector3FTest, DotProduct){
  Vector3F v1(0, 1, 1);
  Vector3F v2(0, -1, 1);

  float result = v1 * v2;

  ASSERT_FLOAT_EQ(result, 0);  
}

TEST(Vector3FTest, Magnitude){
  Vector3F v1(0, 3, 4);
  float result = v1.mag();

  ASSERT_FLOAT_EQ(result, 5.0);
}

TEST(Vector3FTest, Magnitude2){
  Vector3F v1(3, -5, 10);
  float result = v1.mag();
  float check = sqrt(134.0);

  ASSERT_FLOAT_EQ(result, check);
}

TEST(Vector3FTest, Magnitude3){
  Vector3F v1(0, 0, 0);
  float result = v1.mag();

  ASSERT_FLOAT_EQ(result, 0);
}

TEST(Vector3FTest, MagnitudeSquared){
  Vector3F v1(0, 3, 4);
  float result = v1.mag2();

  ASSERT_FLOAT_EQ(result, 25.0);
}

TEST(Vector3FTest, Normalize){
  Vector3F v1(0, 0, 2);

  Vector3F v1Normalized = v1.normalize();
  float v1NormalizedMag = v1Normalized.mag();

  ASSERT_FLOAT_EQ(v1NormalizedMag, 1.0);
}

int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// g++ -Wall -I gtest-1.7.0/include gtest-1.7.0/make/gtest-all.o -pthread Vector3F.cc Vector3F_UnitTest.cc -o Vector3F_UnitTest
