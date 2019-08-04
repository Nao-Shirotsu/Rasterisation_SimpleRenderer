#pragma once

#include <cstdint>
#include <vector>

#include "ColorRGB.hpp"

namespace ras {

// ImageƒNƒ‰ƒX‚Ö‚Ì‘‚«‚İ‚ğ‹–‚·interface
class WritableImage {
public:
  inline virtual ~WritableImage() {}
  virtual void SetColorAt(int32_t y, int32_t x, const ColorRGB255& pixel) = 0;
  virtual int32_t Width() = 0;
  virtual int32_t Height() = 0;
};

} // namespace ras