#include "../../src/Polygon.hpp"
#include <gtest/gtest.h>

void ASSERT_VECTOR3_EQ(const ras::Vector3& expected, const ras::Vector3& actual) {
  ASSERT_DOUBLE_EQ(expected.x, actual.x);
  ASSERT_DOUBLE_EQ(expected.y, actual.y);
  ASSERT_DOUBLE_EQ(expected.y, actual.y);
}

TEST(Polygon, Constructor) {
  constexpr ras::Vector3 vertices[3] = { { -1, 1, 1 }, { 1, 1, 1 }, { 0, -1, 1 } };
  auto poly = ras::Polygon(vertices[0], vertices[1], vertices[2]);

  for (int i = 0; i < 3; ++i) {
    ASSERT_VECTOR3_EQ(poly.Vertex(i), vertices[i]);
  }
}

TEST(Polygon, CopyConstructor) {
  auto poly = ras::Polygon({ -1, 1, 1 }, { 1, 1, 1 }, { 0, -1, 1 });
  auto copy = ras::Polygon(poly);
  for (int i = 0; i < 3; ++i) {
    ASSERT_VECTOR3_EQ(poly.Vertex(i), copy.Vertex(i));
  }
}

TEST (Polygon, Normal){
  auto poly = ras::Polygon({ -1, 1, 1 }, { 1, 1, 1 }, { 0, -1, 1 });
  
  ASSERT_VECTOR3_EQ(ras::Vector3(0, 0, -1), poly.Normal());
}

TEST(Polygon, TranslateInWorld) {
  auto poly = ras::Polygon({ -1, 1, 1 }, { 1, 1, 1 }, { 0, -1, 1 });
  poly.TranslateW({1, -1.5, 0});

  ASSERT_VECTOR3_EQ(ras::Vector3(0, -0.5, 1), poly.Vertex(0));
  ASSERT_VECTOR3_EQ(ras::Vector3(2, -0.5, 1), poly.Vertex(1));
  ASSERT_VECTOR3_EQ(ras::Vector3(1, -2.5, 1), poly.Vertex(2));
}