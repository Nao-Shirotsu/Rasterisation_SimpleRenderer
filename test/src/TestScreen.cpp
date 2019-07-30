#include "../../src/Screen.hpp"
#include <gtest/gtest.h>
#include <cmath>

TEST(Screen, ParallelProjection1) {
  constexpr auto screen = ras::Screen();

  constexpr auto expected = ras::Vector3{ 1.0, 2.0, 0.0 };
 
  auto actual = ras::Vector3{ 1.0, 2.0, 3.0 };
  screen.ApplyParallelProjection(actual);
  
  EXPECT_DOUBLE_EQ(expected.x, actual.x);
  EXPECT_DOUBLE_EQ(expected.y, actual.y);
  EXPECT_DOUBLE_EQ(expected.z, actual.z);
}

//TEST(Screen, ParallelProjection2) {
//  const auto screen = ras::Screen({1, 1, 1}, {-1, 0, -1} );
//
//  //ASSERT_DOUBLE_EQ(-1.0 / sqrt(2), screen.normal.x);
//  //ASSERT_DOUBLE_EQ(0, screen.normal.y);
//  //ASSERT_DOUBLE_EQ(-1.0 / sqrt(2), screen.normal.z);
//
//  constexpr ras::Matrix4 expected = {
//    0.5, 0, 0.5, 0,
//    0, 1, 0, 0,
//    0.5, 0, 0.5, 0,
//    0, 0, 0, 1
//  };
//
//  const auto actual = screen.ParallelProjectionMatrix();
//
//  EXPECT_DOUBLE_EQ(expected[0][0], actual[0][0]);
//  EXPECT_DOUBLE_EQ(expected[0][1], actual[0][1]);
//  EXPECT_DOUBLE_EQ(expected[0][2], actual[0][2]);
//  EXPECT_DOUBLE_EQ(expected[1][0], actual[1][0]);
//  EXPECT_DOUBLE_EQ(expected[1][1], actual[1][1]);
//  EXPECT_DOUBLE_EQ(expected[1][2], actual[1][2]);
//  EXPECT_DOUBLE_EQ(expected[2][0], actual[2][0]);
//  EXPECT_DOUBLE_EQ(expected[2][1], actual[2][1]);
//  ASSERT_DOUBLE_EQ(expected[2][2], actual[2][2]);
//}

//TEST(Screen, ProjectedVector) {
//  const auto screen = ras::Screen({ 1, 1, 1 }, { -1, 0, -1 });
//  constexpr auto vec = ras::Vector3{ -1, 0, -1 };
//  auto actual = vec * screen.ParallelProjectionMatrix();
//  constexpr auto expected = ras::Vector3{ -1, 0, -1 };
//
//  ASSERT_DOUBLE_EQ(expected.x, actual.x);
//  ASSERT_DOUBLE_EQ(expected.y, actual.y);
//  ASSERT_DOUBLE_EQ(expected.z, actual.z);
//}