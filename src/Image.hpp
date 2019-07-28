#pragma once

#include <cstdint>

#include "WritableImage.hpp"

namespace ras {

// 1枚の画像を表すクラス x*y個のピクセル色を保存
class Image : public WritableImage{
public:
  Image(const int32_t width_, const int32_t height_);

  // PPM形式画像をカレントディレクトリに生成する
  void GeneratePPM(const char* fileName) const;

  // Getter
  int32_t Width() override;
  int32_t Height() override;

private:
  void SetColorAt(int32_t y, int32_t x, const ColorRGB255& pixel) override;
  const int32_t width;
  const int32_t height;
  std::vector<std::vector<ColorRGB255>> pixels;
};

}// namespace ras