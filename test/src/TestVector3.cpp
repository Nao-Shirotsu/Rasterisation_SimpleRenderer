#include "../../src/Vector3.hpp"
#include "gtest/gtest.h"

TEST(Vector3, Constructors) {
  constexpr auto zero = ras::Vector3();
  ASSERT_EQ(0.0, zero.x);
  ASSERT_EQ(0.0, zero.y);
  ASSERT_EQ(0.0, zero.z);

  constexpr auto vec = ras::Vector3(1.0, 1.5, 4.87);
  ASSERT_EQ(1.0, vec.x);
  ASSERT_EQ(1.5, vec.y);
  ASSERT_EQ(4.87, vec.z);

  constexpr auto copy = ras::Vector3(vec);
  ASSERT_EQ(1.0, copy.x);
  ASSERT_EQ(1.5, copy.y);
  ASSERT_EQ(4.87, copy.z);

  constexpr auto substituted = vec;
  ASSERT_EQ(1.0, substituted.x);
  ASSERT_EQ(1.5, substituted.y);
  ASSERT_EQ(4.87, substituted.z);
}

TEST (Vector3, Operators){
  constexpr auto vec1 = ras::Vector3(1.0, 2.0, 3.0);
  constexpr auto vec2 = ras::Vector3(3.25, 2.75, 1.5);

  constexpr auto equal = vec1;
  ASSERT_EQ(1.0, equal.x);
  ASSERT_EQ(2.0, equal.y);
  ASSERT_EQ(3.0, equal.z);

  constexpr auto plus = vec1 + vec2;
  ASSERT_EQ(4.25, plus.x);
  ASSERT_EQ(4.75, plus.y);
  ASSERT_EQ(4.5, plus.z);

  constexpr auto minus = vec1 - vec2;
  ASSERT_EQ(-2.25, minus.x);
  ASSERT_EQ(-0.75, minus.y);
  ASSERT_EQ(1.5, minus.z);

  constexpr auto vec1Div2 = vec1 / 2.0;
  ASSERT_EQ(0.5, vec1Div2.x);
  ASSERT_EQ(1.0, vec1Div2.y);
  ASSERT_EQ(1.5, vec1Div2.z);

  constexpr auto vec1Mult2 = vec1 * 2.0;
  ASSERT_EQ(2.0, vec1Mult2.x);
  ASSERT_EQ(4.0, vec1Mult2.y);
  ASSERT_EQ(6.0, vec1Mult2.z);

  constexpr auto minus1_5MultVec1 = -1.5 * vec1;
  ASSERT_EQ(-1.5, minus1_5MultVec1.x);
  ASSERT_EQ(-3.0, minus1_5MultVec1.y);
  ASSERT_EQ(-4.5, minus1_5MultVec1.z);

  constexpr auto vec1Mult0 = vec1 * 0.0;
  ASSERT_EQ(0.0, vec1Mult0.x);
  ASSERT_EQ(0.0, vec1Mult0.y);
  ASSERT_EQ(0.0, vec1Mult0.z);

  constexpr auto zeroMultVec1 = 0.0 * vec1;
  ASSERT_EQ(0.0, zeroMultVec1.x);
  ASSERT_EQ(0.0, zeroMultVec1.y);
  ASSERT_EQ(0.0, zeroMultVec1.z);
}

TEST(Vector3, FuncAndMethods) {
  constexpr auto vec1 = ras::Vector3(1.0, 2.0, 3.0);
  constexpr auto vec2 = ras::Vector3(3.25, 2.75, 1.5);

  const auto normVec1 = vec1.Norm();
  const auto root11 = std::sqrt(1 + 4 + 9);
  ASSERT_EQ(root11, normVec1);

  const auto normal = vec1.NormalizedVector();
  const double normalX = 1.0 / root11;
  const double normalY = 2.0 / root11;
  const double normalZ = 3.0 / root11;
  ASSERT_EQ(normalX, normal.x);
  ASSERT_EQ(normalY, normal.y);
  ASSERT_EQ(normalZ, normal.z);
}