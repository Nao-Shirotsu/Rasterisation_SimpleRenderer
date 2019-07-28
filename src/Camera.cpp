#include "Camera.hpp"

namespace ras {


Camera::Camera(const Vector3& pos_, const Vector3& upward_, const Vector3& lookAtPos_)
  : pos{ pos_ }
  , forward{ (lookAtPos_ - pos).NormalizedVector() }
  , upward{ Cross(Cross(forward, upward_), forward).NormalizedVector() }
  , lookAtPos{lookAtPos_} {}

void Camera::Translate(const Vector3& amount) {
  pos = pos + amount;
  forward = (lookAtPos - pos).NormalizedVector();
  upward = Cross(Cross(forward, upward), forward).NormalizedVector();
}

void Camera::LookAt(const Vector3& lookAtPos_) {
  lookAtPos = lookAtPos_;
  forward = (lookAtPos - pos).NormalizedVector();
  upward = Cross(Cross(forward, upward), forward).NormalizedVector();
}

} // namespace ras