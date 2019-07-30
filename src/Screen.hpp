#pragma once

#include <cstdint>

#include "Vector3.hpp"
#include "Matrix.hpp"

namespace ras {

class Screen {
  constexpr Screen()
    : centerPos{ 0, 0, 0 }
    , normal{ 0, 0, 1 } {}

  constexpr Screen(const Vector3& centerPos_, const Vector3& normal_)
    : centerPos{ centerPos_ }
    , normal{ normal_.NormalizedVector() } {}

  [[nodiscard]] constexpr Matrix4 ParallelProjectionMatrix (){
    return Matrix4{
      1.0 - normal.x * normal.x, -normal.x * normal.y, -normal.x * normal.z, 0,
      -normal.x * normal.y, 1.0 - normal.y * normal.y, -normal.y * normal.z, 0,
      -normal.x * normal.z, -normal.y * normal.z, 1.0 - normal.z * normal.z, 0,
      0, 0, 0, 1
    };
  }

private:
  // 中心点の位置
  Vector3 centerPos;

  // 平面に直交する単位ベクトル
  Vector3 normal;
};

}