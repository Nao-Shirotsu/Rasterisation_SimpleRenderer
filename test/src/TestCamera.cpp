#include "../../src/Camera.hpp"
#include <gtest/gtest.h>

namespace{

void ASSERT_VECTOR3_EQ(const ras::Vector3& expected, const ras::Vector3& actual) {
  EXPECT_DOUBLE_EQ(expected.x, actual.x);
  EXPECT_DOUBLE_EQ(expected.y, actual.y);
  ASSERT_DOUBLE_EQ(expected.z, actual.z);
}

} // anonymous namespace

TEST(Camera, DefaultConstructor) {
  constexpr auto camera = ras::Camera();

  constexpr auto actualPos = camera.Pos();
  EXPECT_DOUBLE_EQ(0, actualPos.x);
  EXPECT_DOUBLE_EQ(0, actualPos.y);
  ASSERT_DOUBLE_EQ(-10, actualPos.z);

  constexpr auto actualForward = camera.Forward();
  EXPECT_DOUBLE_EQ(0, actualForward.x);
  EXPECT_DOUBLE_EQ(0, actualForward.y);
  ASSERT_DOUBLE_EQ(1, actualForward.z);

  constexpr auto actualUpward = camera.Upward();
  EXPECT_DOUBLE_EQ(0, actualUpward.x);
  EXPECT_DOUBLE_EQ(1, actualUpward.y);
  ASSERT_DOUBLE_EQ(0, actualUpward.z);
}

TEST(Camera, ConversionConstructor1) {
  auto camera = ras::Camera({ 1, 1, 1 }, { -1, 1, 1 }, {0, 0, 0});

  auto actualPos = camera.Pos();
  EXPECT_DOUBLE_EQ(1, actualPos.x);
  EXPECT_DOUBLE_EQ(1, actualPos.y);
  ASSERT_DOUBLE_EQ(1, actualPos.z);

  auto expectedForward = ras::Vector3{ -1, -1, -1 }.NormalizedVector();
  auto actualForward = camera.Forward();
  EXPECT_DOUBLE_EQ(expectedForward.x, actualForward.x);
  EXPECT_DOUBLE_EQ(expectedForward.y, actualForward.y);
  ASSERT_DOUBLE_EQ(expectedForward.z, actualForward.z);

  auto expectedUpward = ras::Vector3{ -1, 1, 1 }.NormalizedVector();
  auto actualUpward = camera.Upward();
  EXPECT_DOUBLE_EQ(expectedUpward.x, actualUpward.x);
  EXPECT_DOUBLE_EQ(expectedUpward.y, actualUpward.y);
  ASSERT_DOUBLE_EQ(expectedUpward.z, actualUpward.z);
}

TEST(Camera, ConversionConstructor2) {
  auto camera = ras::Camera({ -1, 0, 1 }, { -1, -1, -1 }, { 0, -1, 0 });

  auto actualPos = camera.Pos();
  EXPECT_DOUBLE_EQ(-1, actualPos.x);
  EXPECT_DOUBLE_EQ(0, actualPos.y);
  ASSERT_DOUBLE_EQ(1, actualPos.z);

  auto expectedForward = ras::Vector3{ 1, -1, -1 }.NormalizedVector();
  auto actualForward = camera.Forward();
  EXPECT_DOUBLE_EQ(expectedForward.x, actualForward.x);
  EXPECT_DOUBLE_EQ(expectedForward.y, actualForward.y);
  ASSERT_DOUBLE_EQ(expectedForward.z, actualForward.z);

  auto expectedUpward = ras::Vector3{ -1, -1, -1 }.NormalizedVector();
  auto actualUpward = camera.Upward();
  EXPECT_DOUBLE_EQ(expectedUpward.x, actualUpward.x);
  EXPECT_DOUBLE_EQ(expectedUpward.y, actualUpward.y);
  ASSERT_DOUBLE_EQ(expectedUpward.z, actualUpward.z);
}

TEST(Camera, Translate) {
  auto camera = ras::Camera();
  camera.Translate({ 1, 1, 11 });
  camera.SetUpward({ -1, 1, 1 });

  auto actualPos = camera.Pos();
  EXPECT_DOUBLE_EQ(1, actualPos.x);
  EXPECT_DOUBLE_EQ(1, actualPos.y);
  ASSERT_DOUBLE_EQ(1, actualPos.z);

  auto expectedForward = ras::Vector3{ -1, -1, -1 }.NormalizedVector();
  auto actualForward = camera.Forward();
  EXPECT_DOUBLE_EQ(expectedForward.x, actualForward.x);
  EXPECT_DOUBLE_EQ(expectedForward.y, actualForward.y);
  ASSERT_DOUBLE_EQ(expectedForward.z, actualForward.z);

  auto expectedUpward = ras::Vector3{ -1, 1, 1 }.NormalizedVector();
  auto actualUpward = camera.Upward();
  EXPECT_DOUBLE_EQ(expectedUpward.x, actualUpward.x);
  EXPECT_DOUBLE_EQ(expectedUpward.y, actualUpward.y);
  ASSERT_DOUBLE_EQ(expectedUpward.z, actualUpward.z);
}

TEST(Camera, LookAt) {
  auto camera = ras::Camera();
  camera.LookAt({ 10, 0, 0 });

  auto actualPos = camera.Pos();
  EXPECT_DOUBLE_EQ(0, actualPos.x);
  EXPECT_DOUBLE_EQ(0, actualPos.y);
  ASSERT_DOUBLE_EQ(-10, actualPos.z);

  auto expectedForward = ras::Vector3{ 1, 0, 1 }.NormalizedVector();
  auto actualForward = camera.Forward();
  EXPECT_DOUBLE_EQ(expectedForward.x, actualForward.x);
  EXPECT_DOUBLE_EQ(expectedForward.y, actualForward.y);
  ASSERT_DOUBLE_EQ(expectedForward.z, actualForward.z);

  auto expectedUpward = ras::Vector3{ 0, 1, 0 }.NormalizedVector();
  auto actualUpward = camera.Upward();
  EXPECT_DOUBLE_EQ(expectedUpward.x, actualUpward.x);
  EXPECT_DOUBLE_EQ(expectedUpward.y, actualUpward.y);
  ASSERT_DOUBLE_EQ(expectedUpward.z, actualUpward.z);
}