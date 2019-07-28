#pragma once

#include "Vector3.hpp"

namespace ras {

// �J�����̈ʒu�ƌ��������\����
class Camera {
public:
  constexpr Camera()
    : pos{ 0, 0, -10 }
    , forward{ 0, 0, 1 }
    , upward{ 0, 1, 0 }
    , lookAtPos{0, 0, 0} {}

  Camera(const Vector3& pos_, const Vector3& upward_, const Vector3& lookAt_);

  // ���[���h�ʒu�ړ�
  void Translate(const Vector3& amount);

  // �����_(���[���h�ʒu)�ύX
  void LookAt(const Vector3& lookAtPos_);

  // ��������Đݒ�
  void SetUpward(const Vector3& upward_);

  // getter
  [[nodiscard]] constexpr Vector3 Pos() const {
    return pos;
  }

  [[nodiscard]] constexpr Vector3 Forward() const {
    return forward;
  }

  [[nodiscard]] constexpr Vector3 Upward() const {
    return upward;
  }

private:
  Vector3 pos;     // ���[���h�ʒu
  Vector3 forward; // ���ʕ���(���E)
  Vector3 upward;  // �����
  Vector3 lookAtPos;  // �����_�̃��[���h�ʒu
};

}// namespace ras