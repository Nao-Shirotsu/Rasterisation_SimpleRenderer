#include "Camera.hpp"
#include "Matrix.hpp"

namespace ras {

Camera::Camera(const Vector3& pos_, const Vector3& upward_, const Vector3& lookAtPos_)
  : pos{ pos_ }
  , forward{ (lookAtPos_ - pos).NormalizedVector() }
  , upward{ upward_.NormalizedVector() }
  , lookAtPos{lookAtPos_} {}

void Camera::Translate(const Vector3& amount) {
  pos = pos + amount;
  forward = (lookAtPos - pos).NormalizedVector();
}

void Camera::LookAt(const Vector3& lookAtPos_) {
  lookAtPos = lookAtPos_;
  forward = (lookAtPos - pos).NormalizedVector();
}

void Camera::SetUpward(const Vector3& upward_) {
  upward = upward_.NormalizedVector();
}

} // namespace ras