#pragma once

#include <array>

#include "Vector3.hpp"

namespace ras {

// �J�����̈ʒu�ƌ��������\����
class Camera {
public:
  constexpr Camera()
    : pos{ 0, 0, -10 }
    , upward{ 0, 1, 0 }
    , lookAtPos{ 0, 0, 0 }
    , viewCoordX{ 1, 0, 0 }
    , viewCoordY{ 0, 1, 0 }
    , viewCoordZ{ 0, 0, 1 } {}

  Camera(const Vector3& pos_, const Vector3& upward_, const Vector3& lookAtPos_);

  // ���[���h�ʒu�ړ�
  void MoveTo(const Vector3& pos_);

  // �����_(���[���h�ʒu)�ύX
  void LookAt(const Vector3& lookAtPos_);

  // ��������Đݒ�
  void SetUpward(const Vector3& upward_);

  void ApplyParallelProjection(Vector3& vertex) const;

  // getter
  [[nodiscard]] constexpr Vector3 Pos() const {
    return pos;
  }

  [[nodiscard]] constexpr Vector3 Forward() const {
    return viewCoordZ;
  }

  [[nodiscard]] constexpr Vector3 Upward() const {
    return upward;
  }

  [[nodiscard]] constexpr std::array<Vector3, 3> CoordSystem() const {
    return { viewCoordX, viewCoordY, viewCoordZ };
  }

private:
  void ApplyViewTransform(Vector3& vertex) const;
  void ReCalcCoordSystem();

  Vector3 pos;     // ���[���h�ʒu
  Vector3 upward;  // �����
  Vector3 lookAtPos;  // �����_�̃��[���h�ʒu
  Vector3 viewCoordZ; // �r���[���W�n�𐬂�z�� (�J�����̐���)
  Vector3 viewCoordX; // �r���[���W�n�𐬂�x��
  Vector3 viewCoordY; // �r���[���W�n�𐬂�y��
};

}// namespace ras