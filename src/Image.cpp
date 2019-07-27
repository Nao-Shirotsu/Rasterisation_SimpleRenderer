#include <fstream>
#include <iostream>

#include "Image.hpp"

namespace ras {

Image::Image(const int32_t resolusionX_, const int32_t resolusionY_)
  : resolusionX{ resolusionX_ }
  , resolusionY{ resolusionY_ }
  , pixels{ resolusionY, std::vector<ColorRGB255>{ resolusionX, ColorRGB255() } } {}

void Image::GeneratePPM(const char* fileName) const {
  std::ofstream ofs(fileName);

  if (!ofs) {
    std::exit(1);
    std::cerr << "ERROR : file open failed." << std::endl;
  }

  ofs << "P3\n"
      << resolusionX << " " << resolusionY << "\n255\n";
  for (const auto& row : pixels) {
    for (const auto& elem : row) {
      ofs << elem.R() << ' ' << elem.G() << ' ' << elem.B() << std::endl;
    }
  }

  ofs.close();
  std::cout << "Rendering succeeded : written to " << fileName << std::endl;
}

void Image::SetColorAt(int32_t y, int32_t x, const ColorRGB255& pixel) {
  pixels[y][x] = pixel;
}

} // namespace ras