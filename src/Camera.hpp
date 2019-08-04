#pragma once

#include "Vector3.hpp"

namespace ras {

// カメラの位置と向きを持つ構造体
class Camera {
public:
  constexpr Camera()
    : pos{ 0, 0, -10 }
    , forward{ 0, 0, 1 }
    , upward{ 0, 1, 0 }
    , lookAtPos{0, 0, 0} {}

  Camera(const Vector3& pos_, const Vector3& upward_, const Vector3& lookAt_);

  // ワールド位置移動
  void Translate(const Vector3& amount);

  // 注視点(ワールド位置)変更
  void LookAt(const Vector3& lookAtPos_);

  // 上方向を再設定
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
  Vector3 pos;     // ワールド位置
  Vector3 forward; // 正面方向(視界)
  Vector3 upward;  // 上方向
  Vector3 lookAtPos;  // 注視点のワールド位置
};

}// namespace ras