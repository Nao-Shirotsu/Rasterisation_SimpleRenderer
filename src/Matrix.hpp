#pragma once
#include <array>

#include "Vector3.hpp"

namespace ras {

// 4次正方行列 ベクトルのアフィン変換に利用
using Matrix4 = std::array<std::array<double, 4>, 4>;

} // namespace ras

// Vector3を4次元に拡張して4x4行列との積を取る
constexpr ras::Vector3 operator*(const ras::Vector3& vec, const ras::Matrix4& matrix) {
  ras::Vector3 result;
  result.x = vec.x * matrix[0][0] + vec.y * matrix[1][0] + vec.z * matrix[2][0] + matrix[3][0];
  result.y = vec.x * matrix[0][1] + vec.y * matrix[1][1] + vec.z * matrix[2][1] + matrix[3][1];
  result.z = vec.x * matrix[0][2] + vec.y * matrix[1][2] + vec.z * matrix[2][2] + matrix[3][2];
  return result;
}

constexpr ras::Matrix4 operator*(const ras::Matrix4& lhs, const ras::Matrix4& rhs) {
  ras::Matrix4 result = {
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0
  };

  for (int k = 0; k < 4; ++k) {
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        result[k][i] += lhs[k][j] * rhs[j][i];
      }
    }
  }
  return result;
}