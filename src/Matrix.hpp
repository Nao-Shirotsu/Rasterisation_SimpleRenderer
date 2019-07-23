#pragma once
#include <array>

#include "Vector3.hpp"

namespace ras {

// 4�������s�� �x�N�g���̃A�t�B���ϊ��ɗ��p
class Matrix4 : public std::array<std::array<double, 4>, 4>{
public:

[[nodiscard]] constexpr ras::Matrix4 operator*(const ras::Matrix4& rhs) const{
    constexpr std::array<double, 4> zero = { 0, 0, 0, 0 };
    Matrix4 result = {
      0, 0, 0, 0,
      0, 0, 0, 0,
      0, 0, 0, 0,
      0, 0, 0, 0
    };

  for (int k = 0; k < 4; ++k) {
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        result[k][i] += data()[k][j] * rhs[j][i];
      }
    }
  }
  return result;
}

};

// Vector3��4�����Ɋg������4x4�s��Ƃ̐ς����
[[nodiscard]] constexpr ras::Vector3 operator*(const ras::Vector3& vec, const ras::Matrix4& matrix) {
  ras::Vector3 result;
  result.x = vec.x * matrix[0][0] + vec.y * matrix[1][0] + vec.z * matrix[2][0] + matrix[3][0];
  result.y = vec.x * matrix[0][1] + vec.y * matrix[1][1] + vec.z * matrix[2][1] + matrix[3][1];
  result.z = vec.x * matrix[0][2] + vec.y * matrix[1][2] + vec.z * matrix[2][2] + matrix[3][2];
  return result;
}

} // namespace ras