#pragma once
#include <cmath>

namespace ras {

// 3�����x�N�g�� (�s�x�N�g���ŕ\��)
// �x�N�g�����m�̉����Z,�v�f���Ƃ̐�,�X�J���[���揜�Z,����,�O��,�傫���̌v�Z,���K�����ł���
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

  // �x�N�g�����m�̉��Z
  [[nodiscard]] constexpr Vector3 operator+(const Vector3& rhs) const {
    return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
  }

  // �x�N�g�����m�̌��Z
  [[nodiscard]] constexpr Vector3 operator-(const Vector3& rhs) const {
    return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
  }


  // �X�J���[�揜�Z (v/2 �̂悤�ɉE���ɃX�J���[)
  [[nodiscard]] constexpr Vector3 operator/(const double num) const {
    return Vector3(x / num, y / num, z / num);
  }

  [[nodiscard]] constexpr Vector3 operator*(const double num) const {
    return Vector3(x * num, y * num, z * num);
  }

  // �傫�������߂�
  [[nodiscard]] constexpr double Norm() const {
    return std::sqrt(x * x + y * y + z * z);
  }

  // ���K��
  [[nodiscard]] constexpr Vector3 NormalizedVector() const {
    double norm = Norm();
    return Vector3(x / norm, y / norm, z / norm);
  }

  double x, y, z;
};

// �X�J���[��Z (2v �̂悤�ɍ����ɃX�J���[)
[[nodiscard]] constexpr Vector3 operator*(const double num, const Vector3& rhs) {
  return Vector3(rhs.x * num, rhs.y * num, rhs.z * num);
}

// �x�N�g�����m�̗v�f���Ƃ̐�
[[nodiscard]] constexpr Vector3 Multiply(const Vector3& lhs, const Vector3& rhs) {
  return Vector3(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
}

// �x�N�g���̓���
[[nodiscard]] constexpr double Dot(const Vector3& lhs, const Vector3& rhs) {
  return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

// �x�N�g���̊O��
[[nodiscard]] constexpr Vector3 Cross(const Vector3& lhs, const Vector3& rhs) {
  return Vector3(lhs.y * rhs.z - lhs.z * rhs.y,
                 lhs.z * rhs.x - lhs.x * rhs.z,
                 lhs.x * rhs.y - lhs.y * rhs.x);
}

} // namespace ras