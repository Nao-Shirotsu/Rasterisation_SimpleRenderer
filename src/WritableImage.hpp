#pragma once

#include <cstdint>
#include <vector>

#include "ColorRGB.hpp"

namespace ras {

// Image�N���X�ւ̏������݂�����interface
class WritableImage {
public:
  inline virtual ~WritableImage() {}
  virtual void SetColorAt(int32_t y, int32_t x, const ColorRGB255& pixel) = 0;
};

} // namespace ras