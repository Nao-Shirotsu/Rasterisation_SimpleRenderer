#include <fstream>
#include <iostream>

#include "Image.hpp"

namespace ras {

Image::Image(const int32_t width_, const int32_t height_)
  : width{ width_ }
  , height{ height_ }
  , pixels{ height, std::vector<ColorRGB255>{ width, ColorRGB255() } } {}

void Image::GeneratePPM(const char* fileName) const {
  std::ofstream ofs(fileName);

  if (!ofs) {
    std::exit(1);
    std::cerr << "ERROR : file open failed." << std::endl;
  }

  ofs << "P3\n"
      << width << " " << height << "\n255\n";
  for (const auto& row : pixels) {
    for (const auto& elem : row) {
      ofs << elem.R() << ' ' << elem.G() << ' ' << elem.B() << std::endl;
    }
  }

  ofs.close();
  std::cout << "Rendering succeeded : written to " << fileName << std::endl;
}

int32_t Image::Width() {
  return width;
}

int32_t Image::Height() {
  return height;
}

void Image::SetColorAt(int32_t y, int32_t x, const ColorRGB255& pixel) {
  pixels[y][x] = pixel;
}

} // namespace ras