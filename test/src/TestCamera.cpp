#include "../../src/Camera.hpp"
#include <cmath>
#include <gtest/gtest.h>

namespace {

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
  const auto camera = ras::Camera({ 1, 1, 1 }, { -1, 1, -1 }, { 0, 0, 0 });

  const auto actualPos = camera.Pos();
  EXPECT_DOUBLE_EQ(1, actualPos.x);
  EXPECT_DOUBLE_EQ(1, actualPos.y);
  ASSERT_DOUBLE_EQ(1, actualPos.z);

  const auto root3 = std::sqrt(3.0);
  const auto expectedForward = ras::Vector3{ -1 / root3, -1 / root3, -1 / root3 }.NormalizedVector();
  const auto actualForward = camera.Forward();
  EXPECT_DOUBLE_EQ(expectedForward.x, actualForward.x);
  EXPECT_DOUBLE_EQ(expectedForward.y, actualForward.y);
  ASSERT_DOUBLE_EQ(expectedForward.z, actualForward.z);

  const auto expectedUpward = ras::Vector3{ -1 / root3, 1 / root3, -1 / root3 }.NormalizedVector();
  const auto actualUpward = camera.Upward();
  EXPECT_DOUBLE_EQ(expectedUpward.x, actualUpward.x);
  EXPECT_DOUBLE_EQ(expectedUpward.y, actualUpward.y);
  ASSERT_DOUBLE_EQ(expectedUpward.z, actualUpward.z);
}

TEST(Camera, ConversionConstructor2) {
  const auto camera = ras::Camera({ -1, 0, 1 }, { -1, -1, -1 }, { 0, -1, 0 });

  const auto actualPos = camera.Pos();
  EXPECT_DOUBLE_EQ(-1, actualPos.x);
  EXPECT_DOUBLE_EQ(0, actualPos.y);
  ASSERT_DOUBLE_EQ(1, actualPos.z);

  const auto root3 = std::sqrt(3.0);
  const auto expectedForward = ras::Vector3{ 1 / root3, -1 / root3, -1 / root3 }.NormalizedVector();
  const auto actualForward = camera.Forward();
  EXPECT_DOUBLE_EQ(expectedForward.x, actualForward.x);
  EXPECT_DOUBLE_EQ(expectedForward.y, actualForward.y);
  ASSERT_DOUBLE_EQ(expectedForward.z, actualForward.z);

  const auto expectedUpward = ras::Vector3{ -1 / root3, -1 / root3, -1 / root3 }.NormalizedVector();
  const auto actualUpward = camera.Upward();
  EXPECT_DOUBLE_EQ(expectedUpward.x, actualUpward.x);
  EXPECT_DOUBLE_EQ(expectedUpward.y, actualUpward.y);
  ASSERT_DOUBLE_EQ(expectedUpward.z, actualUpward.z);
}

TEST(Camera, MoveTo) {
  auto camera = ras::Camera();
  camera.MoveTo({ 5, 0, -5 });

  auto actualPos = camera.Pos();
  EXPECT_DOUBLE_EQ(5, actualPos.x);
  EXPECT_DOUBLE_EQ(0, actualPos.y);
  ASSERT_DOUBLE_EQ(-5, actualPos.z);

  auto expectedForward = ras::Vector3{ -1, 0, 1 }.NormalizedVector();
  auto actualForward = camera.Forward();
  EXPECT_DOUBLE_EQ(expectedForward.x, actualForward.x);
  EXPECT_DOUBLE_EQ(expectedForward.y, actualForward.y);
  ASSERT_DOUBLE_EQ(expectedForward.z, actualForward.z);

  auto expectedUpward = ras::Vector3{ 0, 1, 0 };
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

TEST(Camera, CoordSystem1) {
  auto camera = ras::Camera();
  auto [actualX, actualY, actualZ] = camera.CoordSystem();
  auto expectedX = ras::Vector3{ 1, 0, 0 };
  auto expectedY = ras::Vector3{ 0, 1, 0 };
  auto expectedZ = ras::Vector3{ 0, 0, 1 };
  EXPECT_DOUBLE_EQ(expectedX.x, actualX.x);
  EXPECT_DOUBLE_EQ(expectedX.y, actualX.y);
  ASSERT_DOUBLE_EQ(expectedX.z, actualX.z);
  EXPECT_DOUBLE_EQ(expectedY.x, actualY.x);
  EXPECT_DOUBLE_EQ(expectedY.y, actualY.y);
  ASSERT_DOUBLE_EQ(expectedY.z, actualY.z);
  EXPECT_DOUBLE_EQ(expectedZ.x, actualZ.x);
  EXPECT_DOUBLE_EQ(expectedZ.y, actualZ.y);
  ASSERT_DOUBLE_EQ(expectedZ.z, actualZ.z);
}

TEST(Camera, CoordSystem2) {
  auto camera = ras::Camera{ { -1, 1, 1 }, { 1, 1, -1 }, {0, 0, 0} };
  auto [actualX, actualY, actualZ] = camera.CoordSystem();
  auto expectedX = ras::Vector3{ 1, -1, -1 }.NormalizedVector();
  auto expectedY = ras::Vector3{ -1, 0, -1 }.NormalizedVector();
  auto expectedZ = ras::Vector3{ -1, -2, 1 }.NormalizedVector();
  EXPECT_DOUBLE_EQ(expectedX.x, actualX.x);
  EXPECT_DOUBLE_EQ(expectedX.y, actualX.y);
  ASSERT_DOUBLE_EQ(expectedX.z, actualX.z);
  EXPECT_DOUBLE_EQ(expectedY.x, actualY.x);
  EXPECT_DOUBLE_EQ(expectedY.y, actualY.y);
  ASSERT_DOUBLE_EQ(expectedY.z, actualY.z);
  EXPECT_DOUBLE_EQ(expectedZ.x, actualZ.x);
  EXPECT_DOUBLE_EQ(expectedZ.y, actualZ.y);
  ASSERT_DOUBLE_EQ(expectedZ.z, actualZ.z);
}

TEST(Camera, ApplyParallelProjection) {
  auto camera = ras::Camera();
  auto vertex = ras::Vector3{ 0, 0, 0 };
  camera.ApplyParallelProjection(vertex);
  auto actualPos = vertex;
  auto expectedPos = ras::Vector3{ 0, 0, 0 };
  EXPECT_DOUBLE_EQ(expectedPos.x, actualPos.x);
  EXPECT_DOUBLE_EQ(expectedPos.y, actualPos.y);
  ASSERT_DOUBLE_EQ(expectedPos.z, actualPos.z);

  camera.MoveTo({ -1, 1, 1 });
  camera.SetUpward({ 1, 1, -1 });
  vertex = { -1, -1, -1 };
  camera.ApplyParallelProjection(vertex);
  const double divByRoot2 = 1.0 / std::sqrt(2.0);
  const double divByRoot6 = 1.0 / std::sqrt(6.0);
  actualPos = vertex;
  expectedPos = ras::Vector3{ -2.0 * divByRoot2, -3.0 * divByRoot6, 0 };
  EXPECT_DOUBLE_EQ(expectedPos.x, actualPos.x);
  EXPECT_DOUBLE_EQ(expectedPos.y, actualPos.y);
  ASSERT_DOUBLE_EQ(expectedPos.z, actualPos.z);
}