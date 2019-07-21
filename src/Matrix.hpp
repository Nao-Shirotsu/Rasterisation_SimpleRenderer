#pragma once
#include <array>
#include <cmath>

#include "Vector3.hpp"

namespace ras {

// Néüå≥ê≥ï˚çsóÒ
template <int size>
using Matrix = std::array<std::array<double, size>, size>;

using Matrix3 = Matrix<3>;

using Matrix4 = Matrix<4>;

constexpr Vector3 operator*(const Vector3& vec, const Matrix3& matrix) {
  Vector3 result;
  result.x = vec.x * matrix[0][0] + vec.y * matrix[1][0] + vec.z * matrix[2][0];
  result.y = vec.x * matrix[0][1] + vec.y * matrix[1][1] + vec.z * matrix[2][1];
  result.z = vec.x * matrix[0][2] + vec.y * matrix[1][2] + vec.z * matrix[2][2];
}

constexpr Vector3 operator*(const Vector3& vec, const Matrix4& matrix) {
  Vector3 result;
  result.x = vec.x * matrix[0][0] + vec.y * matrix[1][0] + vec.z * matrix[2][0] + matrix[3][0];
  result.y = vec.x * matrix[0][1] + vec.y * matrix[1][1] + vec.z * matrix[2][1] + matrix[3][1];
  result.z = vec.x * matrix[0][2] + vec.y * matrix[1][2] + vec.z * matrix[2][2] + matrix[3][2];
}

template <int size>
constexpr Matrix<size> operator*(const Matrix<size>& lhs, const Matrix<size>& rhs) {
  static_assert(size == 3 || size == 4, "**ERROR: operator* for only 3x3 and 4x4 matrix defined**");
  Matrix<size> result;
  for (i = 0; i < size; ++i) {
    for (j = 0; j < size; ++j) {
      result[i][j] = 0;
    }
  }

  for (k = 0; k < size; ++k) {
    for (i = 0; i < size; ++i) {
      for (j = 0; j < size; ++j) {
        result[k][i] += lhs[k][j] * rhs[j][i];
      }
    }
  }
  return result;
}

template <int size>
constexpr Matrix<size> operator*(const Matrix<size>& lhs, const Matrix<size + 1>& rhs) {
  static_assert(size == 3, "**ERROR: operator* for only 3x3 and 4x4 matrix defined**");
  Matrix<size + 1> result;
  for (i = 0; i < size + 1; ++i) {
    for (j = 0; j < size + 1; ++j) {
      result[i][j] = 0;
    }
  }

  for (k = 0; k < size; ++k) {
    for (i = 0; i < size; ++i) {
      for (j = 0; j < size; ++j) {
        result[k][i] += lhs[k][j] * rhs[j][i];
      }
    }
  }

  for (int j = 0; j < size + 1; ++j) {
    result[size][j] = rhs[size][j];
  }

  return result;
}

template <int size>
constexpr Matrix<size> operator*(const Matrix<size + 1>& lhs, const Matrix<size>& rhs) {
  static_assert(size == 3, "**ERROR: operator* for only 3x3 and 4x4 matrix defined**");
  Matrix<size + 1> result;
  for (i = 0; i < size + 1; ++i) {
    for (j = 0; j < size + 1; ++j) {
      result[i][j] = 0;
    }
  }

  for (k = 0; k < size; ++k) {
    for (i = 0; i < size; ++i) {
      for (j = 0; j < size; ++j) {
        result[k][i] += lhs[k][j] * rhs[j][i];
      }
    }
  }

  for (int j = 0; j < size + 1; ++j) {
    result[size][j] = lhs[size][j];
  }

  return result;
}

} // namespace ras