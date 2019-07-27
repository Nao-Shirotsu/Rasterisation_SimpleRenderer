#include "../../src/ColorRGB.hpp"
#include <gtest/gtest.h>

void ASSERT_COLORRGB_EQ(const ras::ColorRGB255& expected, const ras::ColorRGB255& actual) {
  ASSERT_DOUBLE_EQ(expected.R(), actual.R());
  ASSERT_DOUBLE_EQ(expected.G(), actual.G());
  ASSERT_DOUBLE_EQ(expected.B(), actual.B());
}

void ASSERT_COLORRGB_EQ(const ras::ColorRGBfloat& expected, const ras::ColorRGBfloat& actual) {
  ASSERT_DOUBLE_EQ(expected.R(), actual.R());
  ASSERT_DOUBLE_EQ(expected.G(), actual.G());
  ASSERT_DOUBLE_EQ(expected.B(), actual.B());
}

TEST(ColorRGB255, Constructors) {
  constexpr uint8_t expectedR = 0;
  constexpr uint8_t expectedG = 0;
  constexpr uint8_t expectedB = 0;
  constexpr auto actual = ras::ColorRGB255();

  ASSERT_EQ(expectedR, actual.R());
  ASSERT_EQ(expectedG, actual.G());
  ASSERT_EQ(expectedB, actual.B());
}