#pragma once

#include <cstdint>

#include "WritableImage.hpp"

namespace ras {

// 1���̉摜��\���N���X x*y�̃s�N�Z���F��ۑ�
class Image : public WritableImage{
public:
  Image(const int32_t resolusionX_, const int32_t resolusionY_);

  // PPM�`���摜���J�����g�f�B���N�g���ɐ�������
  void GeneratePPM(const char* fileName) const;

private:
  void SetColorAt(int32_t y, int32_t x, const ColorRGB255& pixel) override;
  const int32_t resolusionX;
  const int32_t resolusionY;
  std::vector<std::vector<ColorRGB255>> pixels;
};

}// namespace ras