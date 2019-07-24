#pragma once
#include <cmath>

namespace ras {

// 3次元ベクトル (行ベクトルで表現)
// ベクトル同士の加減算,要素ごとの積,スカラーを乗除算,内積,外積,大きさの計算,正規化ができる
class Vector3 {
public:
  constexpr Vector3()
    : x(0)
    , y(0)
    , z(0) {}

  constexpr Vector3(const double x_, const double y_, const double z_)
    : x(x_)
    , y(y_)
    , z(z_) {}

  constexpr Vector3(const Vector3& other)
    : x(other.x)
    , y(other.y)
    , z(other.z) {}

  ~Vector3() = default;

  constexpr Vector3& operator=(const Vector3& rhs) {
    if (this != &rhs) {
      x = rhs.x;
      y = rhs.y;
      z = rhs.z;
    }
    return *this;
  }

  // ベクトル同士の加算
  [[nodiscard]] constexpr Vector3 operator+(const Vector3& rhs) const {
    return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
  }

  // ベクトル同士の減算
  [[nodiscard]] constexpr Vector3 operator-(const Vector3& rhs) const {
    return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
  }


  // スカラー乗除算 (v/2 のように右側にスカラー)
  [[nodiscard]] constexpr Vector3 operator/(const double num) const {
    return Vector3(x / num, y / num, z / num);
  }

  [[nodiscard]] constexpr Vector3 operator*(const double num) const {
    return Vector3(x * num, y * num, z * num);
  }

  // 大きさを求める
  [[nodiscard]] constexpr double Norm() const {
    return std::sqrt(x * x + y * y + z * z);
  }

  // 正規化
  [[nodiscard]] constexpr Vector3 NormalizedVector() const {
    double norm = Norm();
    return Vector3(x / norm, y / norm, z / norm);
  }

  double x, y, z;
};

// スカラー乗算 (2v のように左側にスカラー)
[[nodiscard]] constexpr Vector3 operator*(const double num, const Vector3& rhs) {
  return Vector3(rhs.x * num, rhs.y * num, rhs.z * num);
}

// ベクトル同士の要素ごとの積
[[nodiscard]] constexpr Vector3 Multiply(const Vector3& lhs, const Vector3& rhs) {
  return Vector3(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
}

// ベクトルの内積
[[nodiscard]] constexpr double Dot(const Vector3& lhs, const Vector3& rhs) {
  return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

// ベクトルの外積
[[nodiscard]] constexpr Vector3 Cross(const Vector3& lhs, const Vector3& rhs) {
  return Vector3(lhs.y * rhs.z - lhs.z * rhs.y,
                 lhs.z * rhs.x - lhs.x * rhs.z,
                 lhs.x * rhs.y - lhs.y * rhs.x);
}

} // namespace ras