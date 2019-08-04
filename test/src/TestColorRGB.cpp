#include "../../src/ColorRGB.hpp"
#include <gtest/gtest.h>

TEST(ColorRGB255, DefaultConstructor) {
  constexpr auto actual = ras::ColorRGB255();
  ASSERT_EQ(0, actual.R());
  ASSERT_EQ(0, actual.G());
  ASSERT_EQ(0, actual.B());
}

TEST(ColorRGB255, ConversionConstructor) {
  constexpr auto actualInRange = ras::ColorRGB255(0, 45, 255);
  ASSERT_EQ(0, actualInRange.R());
  ASSERT_EQ(45, actualInRange.G());
  ASSERT_EQ(255, actualInRange.B());

  constexpr auto actualOutRange = ras::ColorRGB255(-2333214, 45, 984737);
  ASSERT_EQ(0, actualOutRange.R());
  ASSERT_EQ(45, actualOutRange.G());
  ASSERT_EQ(255, actualOutRange.B());

  constexpr auto actualImplicitCast = ras::ColorRGB255(0.75, 'a', 984737.5);
  ASSERT_EQ(0, actualImplicitCast.R());
  ASSERT_EQ('a', actualImplicitCast.G());
  ASSERT_EQ(255, actualImplicitCast.B());
}

TEST(ColorRGB255, CopyConstructor) {
  constexpr auto color = ras::ColorRGB255(0, 45, 255);
  constexpr auto copy = ras::ColorRGB255(color);
  ASSERT_EQ(color.R(), copy.R());
  ASSERT_EQ(color.G(), copy.G());
  ASSERT_EQ(color.B(), copy.B());
}

TEST(ColorRGB255, OperatorEqual) {
  constexpr auto color = ras::ColorRGB255(0, 45, 255);
  constexpr auto substituted = color;
  ASSERT_EQ(color.R(), substituted.R());
  ASSERT_EQ(color.G(), substituted.G());
  ASSERT_EQ(color.B(), substituted.B());
}

TEST(ColorRGB255, OperatorPlus) {
  constexpr auto color = ras::ColorRGB255(0, 45, 255);
  constexpr auto added = color + ras::ColorRGB255(-3, 4, 5);
  ASSERT_EQ(0, added.R());
  ASSERT_EQ(49, added.G());
  ASSERT_EQ(255, added.B());
}

TEST(ColorRGB255, OperatorMinus) {
  constexpr auto color = ras::ColorRGB255(0, 45, 255);
  constexpr auto subtracted = color - ras::ColorRGB255(3, 4, -5);
  ASSERT_EQ(0, subtracted.R());
  ASSERT_EQ(41, subtracted.G());
  ASSERT_EQ(255, subtracted.B());
}

TEST(ColorRGB255, OperatorProduct) {
  constexpr auto color = ras::ColorRGB255(0, 10, 100);
  constexpr auto multZeroR = color * 0;
  ASSERT_EQ(0, multZeroR.R());
  ASSERT_EQ(0, multZeroR.G());
  ASSERT_EQ(0, multZeroR.B());
  constexpr auto multZeroL = 0 * color;
  ASSERT_EQ(0, multZeroL.R());
  ASSERT_EQ(0, multZeroL.G());
  ASSERT_EQ(0, multZeroL.B());

  constexpr auto multTwoR = color * 2.5;
  ASSERT_EQ(0, multTwoR.R());
  ASSERT_EQ(25, multTwoR.G());
  ASSERT_EQ(250, multTwoR.B());
  constexpr auto multTwoL = 2.5 * color;
  ASSERT_EQ(0, multTwoL.R());
  ASSERT_EQ(25, multTwoL.G());
  ASSERT_EQ(250, multTwoL.B());

  constexpr auto multHalfR = color * 0.5;
  ASSERT_EQ(0, multHalfR.R());
  ASSERT_EQ(5, multHalfR.G());
  ASSERT_EQ(50, multHalfR.B());
  constexpr auto multHalfL = 0.5 * color;
  ASSERT_EQ(0, multHalfL.R());
  ASSERT_EQ(5, multHalfL.G());
  ASSERT_EQ(50, multHalfL.B());
}

TEST(ColorRGB255, OperatorDivision) {
  constexpr auto color = ras::ColorRGB255(0, 100, 250);
  constexpr auto divided2 = color / 2.0;
  ASSERT_EQ(0, divided2.R());
  ASSERT_EQ(50, divided2.G());
  ASSERT_EQ(125, divided2.B());

  constexpr auto dividedHalf = color / 0.5;
  ASSERT_EQ(0, dividedHalf.R());
  ASSERT_EQ(200, dividedHalf.G());
  ASSERT_EQ(255, dividedHalf.B());
}

TEST(ColorRGB255, Setter) {
  auto color = ras::ColorRGB255();
  color.SetR(-5);
  color.SetG(55);
  color.SetB(287);
  ASSERT_EQ(0, color.R());
  ASSERT_EQ(55, color.G());
  ASSERT_EQ(255, color.B());
}