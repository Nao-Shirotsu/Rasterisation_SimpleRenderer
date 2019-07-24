#pragma once

#include <array>

#include "Matrix.hpp"
#include "Vector3.hpp"

namespace ras {

// ���_��3���|���S���N���X
class Polygon {
public:
  constexpr Polygon(const Vector3& v0, const Vector3& v1, const Vector3& v2)
    : vertices{ v0, v1, v2 }
    , normal{ Cross(vertices[1] - vertices[0], vertices[2] - vertices[0]).NormalizedVector() } {}

  constexpr Polygon(const Polygon& other) 
    : vertices{other.vertices} {}

  [[nodiscard]] constexpr Vector3 Vertex (uint8_t index){// index > 2�̎���΂��ˁH
    return vertices[index];
  }

  [[nodiscard]] constexpr Vector3 Normal () const{
    return normal;
  }

  // ���[���h���W�n��x, y, z�������ɕ��s�ړ�
  void TranslateW (const Vector3& amount){
    for (auto& vertex : vertices) {
      vertex.x += amount.x;
      vertex.y += amount.y;
      vertex.z += amount.z;
    }
  }

private:
  std::array<Vector3, 3> vertices;
  Vector3 normal; // v0->v1->v2�����v����ɂȂ�ʂ�����
};

} // namespace ras