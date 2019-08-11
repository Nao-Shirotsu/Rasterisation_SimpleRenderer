#include "Camera.hpp"
#include "Matrix.hpp"

namespace ras {

Camera::Camera(const Vector3& pos_, const Vector3& upward_, const Vector3& lookAtPos_)
  : pos{ pos_ }
  , upward{ upward_.NormalizedVector() }
  , lookAtPos{ lookAtPos_ }
  , viewCoordZ{ (lookAtPos_ - pos_).NormalizedVector() }
  , viewCoordX{ Cross(upward_, viewCoordZ).NormalizedVector() }
  , viewCoordY{ Cross(viewCoordZ, viewCoordX).NormalizedVector() } {}

void Camera::MoveTo(const Vector3& pos_) {
  pos = pos_;
  ReCalcCoordSystem();
}

void Camera::LookAt(const Vector3& lookAtPos_) {
  lookAtPos = lookAtPos_;
  ReCalcCoordSystem();
}

void Camera::SetUpward(const Vector3& upward_) {
  upward = upward_.NormalizedVector();
  ReCalcCoordSystem();
}

void Camera::ApplyParallelProjection(Vector3& vertex) const {
  ApplyViewTransform(vertex);
  vertex.z = 0.0;
}

void Camera::ApplyViewTransform(Vector3& vertex) const {
  vertex = vertex - pos;
  const auto trans = Matrix4{
    viewCoordX.x, viewCoordY.x, 0, 0,
    viewCoordX.y, viewCoordY.y, 0, 0,
    viewCoordX.z, viewCoordY.z, 0, 0,
    0, 0, 0, 1
  };
  vertex = vertex * trans;
}
void Camera::ReCalcCoordSystem() {
  viewCoordZ = (lookAtPos - pos).NormalizedVector();
  viewCoordX = Cross(upward, viewCoordZ).NormalizedVector();
  viewCoordY = Cross(viewCoordZ, viewCoordX).NormalizedVector();
}
} // namespace ras