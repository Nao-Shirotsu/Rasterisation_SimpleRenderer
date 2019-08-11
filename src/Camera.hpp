#pragma once

#include <array>

#include "Vector3.hpp"

namespace ras {

// カメラの位置と向きを持つ構造体
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

  // ワールド位置移動
  void MoveTo(const Vector3& pos_);

  // 注視点(ワールド位置)変更
  void LookAt(const Vector3& lookAtPos_);

  // 上方向を再設定
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

  Vector3 pos;     // ワールド位置
  Vector3 upward;  // 上方向
  Vector3 lookAtPos;  // 注視点のワールド位置
  Vector3 viewCoordZ; // ビュー座標系を成すz軸 (カメラの正面)
  Vector3 viewCoordX; // ビュー座標系を成すx軸
  Vector3 viewCoordY; // ビュー座標系を成すy軸
};

}// namespace ras