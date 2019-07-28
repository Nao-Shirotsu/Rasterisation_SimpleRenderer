#include "ColorRGB.hpp"
#include "Image.hpp"

int main() {
  int width = 100;
  int height = 100;
  auto image = ras::Image(width, height);
  ras::WritableImage& writableImage = image;
  for (int i = 0; i < writableImage.Height(); ++i) {
    for (int j = 0; j < writableImage.Width(); ++j) {
      writableImage.SetColorAt(i, j, ras::ColorRGB255{ 32, 50 + (i / 20) * 40, 50 + (j / 20) * 40 });
    }
  }
  image.GeneratePPM("test.ppm");
}
