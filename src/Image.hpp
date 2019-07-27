#pragma once

#include <cstdint>

#include "WritableImage.hpp"

namespace ras {

// 1枚の画像を表すクラス x*y個のピクセル色を保存
class Image : public WritableImage{
public:
  Image(const int32_t resolusionX_, const int32_t resolusionY_);

  // PPM形式画像をカレントディレクトリに生成する
  void GeneratePPM(const char* fileName) const;

private:
  void SetColorAt(int32_t y, int32_t x, const ColorRGB255& pixel) override;
  const int32_t resolusionX;
  const int32_t resolusionY;
  std::vector<std::vector<ColorRGB255>> pixels;
};

}// namespace ras