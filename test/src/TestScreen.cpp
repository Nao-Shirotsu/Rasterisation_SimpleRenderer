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

TEST(Screen, ParallelProjection2) {
  const auto screen = ras::Screen({ 1, 1, 1 }, { -1, 0, -1 });

  constexpr auto expected = ras::Vector3{ -1.0, 1.0, 1.0 };

  auto actual = ras::Vector3{ 1.0, 2.0, 3.0 };
  screen.ApplyParallelProjection(actual);

  EXPECT_DOUBLE_EQ(expected.x, actual.x);
  EXPECT_DOUBLE_EQ(expected.y, actual.y);
  EXPECT_DOUBLE_EQ(expected.z, actual.z);
}