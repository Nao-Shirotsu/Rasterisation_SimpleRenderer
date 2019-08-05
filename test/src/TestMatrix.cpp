#include "../../src/Matrix.hpp"
#include <gtest/gtest.h>

namespace {

void ASSERT_EQ_MATRIX(const ras::Matrix4& expected, const ras::Matrix4& actual) {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      ASSERT_DOUBLE_EQ(expected[i][j], actual[i][j]);
    }
  }
}

} // anonymous namespace

TEST(Matrix4, Product) {
  constexpr ras::Matrix4 mat1 = {
    0, 1, 2, 3,
    4, 5, 6, 7,
    8, 9, 10, 11,
    12, 13, 14, 15
  };

  constexpr ras::Matrix4 mat2 = {
    -2, -3, -4, -2.5,
    0, 0, 0, 0,
    0.5, 0.5, 0.25, 0.75,
    0, 0, 0, 0
  };

  constexpr ras::Matrix4 expected = {
    1, 1, 0.5, 1.5,
    -5, -9, -14.5, -5.5,
    -11, -19, -29.5, -12.5,
    -17, -29, -44.5, -19.5
  };

  ASSERT_EQ_MATRIX(expected, mat1 * mat2);
}

TEST(Matrix4, ProductWithVector3) {
  constexpr auto vec = ras::Vector3( -1.5, 2.75, 0 );
  constexpr auto trans = ras::Matrix4{
    -2, -3, -4, 0,
    0, 0, 0, 0,
    0.5, 0.5, 0.25, 0,
    -2.5, 0, 0.75, 0
  };

  constexpr auto expected = ras::Vector3{ 0.5, 4.5, 6.75};
  constexpr ras::Vector3 actual = vec * trans;

  EXPECT_DOUBLE_EQ(expected.x, actual.x);
  EXPECT_DOUBLE_EQ(expected.y, actual.y);
  ASSERT_DOUBLE_EQ(expected.z, actual.z);
}