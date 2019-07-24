#pragma once

#include <cstdint>
#include <algorithm>

namespace ras {

namespace literals{

constexpr uint8_t U8_0 = static_cast<uint8_t>(0);
constexpr uint8_t U8_255 = static_cast<uint8_t>(255);

} // namespace literals

class ColorRGBfloat;

// 0~255で各色を表すRGBカラークラス
class ColorRGB255 {
public:
  constexpr ColorRGB255()
    : red{ 0 }
    , green{ 0 }
    , blue{ 0 } {}

  constexpr ColorRGB255(uint8_t red_, uint8_t green_, uint8_t blue_)
    : red{ std::clamp( red_, literals::U8_0, literals::U8_255) }
    , green{ std::clamp( green_, literals::U8_0, literals::U8_255) }
    , blue{ std::clamp( blue_, literals::U8_0, literals::U8_255) } {}

  constexpr ColorRGB255(const ColorRGB255& other)
    : red{ std::clamp(other.R(), literals::U8_0, literals::U8_255) }
    , green{ std::clamp(other.G(), literals::U8_0, literals::U8_255) }
    , blue{ std::clamp(other.B(), literals::U8_0, literals::U8_255) } {}

  constexpr ColorRGB255(const ColorRGBfloat& other)
    : red{ std::clamp(static_cast<uint8_t>(other.R() * 255), literals::U8_0, literals::U8_255) }
    , green{ std::clamp(static_cast<uint8_t>(other.G() * 255), literals::U8_0, literals::U8_255) }
    , blue{ std::clamp(static_cast<uint8_t>(other.B() * 255), literals::U8_0, literals::U8_255) } {}

  constexpr ColorRGB255& operator=(const ColorRGB255& other){
    using std::clamp;
    red = clamp(other.R(), literals::U8_0, literals::U8_255);
    green = clamp(other.G(), literals::U8_0, literals::U8_255);
    blue = clamp(other.B(), literals::U8_0, literals::U8_255);
    return *this;
  }

  [[nodiscard]] constexpr ColorRGB255 operator+(const ColorRGB255& other) const{
    return ColorRGB255{red + other.R(), green + other.G(), blue + other.B()};
  }

  [[nodiscard]] constexpr ColorRGB255 operator-(const ColorRGB255& other) const{
    return ColorRGB255{ red - other.R(), green - other.G(), blue - other.B() };
  }

  [[nodiscard]] constexpr ColorRGB255 operator*(const uint8_t factor) const{
    return ColorRGB255{red * factor, green * factor, blue * factor};
  }

  [[nodiscard]] constexpr ColorRGB255 operator/(const uint8_t factor) const{
    return ColorRGB255{red / factor, green / factor, blue / factor};
  }

  [[nodiscard]] constexpr uint8_t R() const{
    return red;
  }

  [[nodiscard]] constexpr uint8_t G() const{
    return green;
  }

  [[nodiscard]] constexpr uint8_t B() const{
    return blue;
  }

  constexpr void SetR (const uint8_t red_){
    red = std::clamp(red_, literals::U8_0, literals::U8_255);
  }

  constexpr void SetG(const uint8_t green_) {
    green = std::clamp(green_, literals::U8_0, literals::U8_255);
  }

  constexpr void SetB(const uint8_t blue_) {
    blue = std::clamp(blue_, literals::U8_0, literals::U8_255);
  }

  [[nodiscard]] constexpr ColorRGBfloat ToColorRGBfloat () const{
    return ColorRGBfloat(red / 255.0, green / 255.0, blue/ 255.0);
  }

private:
  uint8_t red, green, blue;
};

[[nodiscard]] constexpr ColorRGB255 operator*(const uint8_t factor, ColorRGB255& color) {
  using std::clamp;
  return ColorRGB255{ clamp(color.R() * factor, 0, 255), clamp(color.G() * factor, 0, 255), clamp(color.B() * factor, 0, 255) };
}

// 0.0~1.0で各色を表すRGBカラークラス
class ColorRGBfloat {
public:
  constexpr ColorRGBfloat()
    : red{ 0 }
    , green{ 0 }
    , blue{ 0 } {}

  constexpr ColorRGBfloat(double red_, double green_, double blue_)
    : red{ std::clamp(red_, 0.0, 1.0) }
    , green{ std::clamp(green_, 0.0, 1.0) }
    , blue{ std::clamp(blue_, 0.0, 1.0) } {}

  constexpr ColorRGBfloat(const ColorRGBfloat& other)
    : red{ std::clamp(other.R(), 0.0, 1.0) }
    , green{ std::clamp(other.G(), 0.0, 1.0) }
    , blue{ std::clamp(other.B(), 0.0, 1.0) } {}

  constexpr ColorRGBfloat(const ColorRGB255& other)
    : red{ std::clamp(other.R() / 255.0, 0.0, 1.0) }
    , green{ std::clamp(other.G() / 255.0, 0.0, 1.0) }
    , blue{ std::clamp(other.B()/ 255.0, 0.0, 1.0)} {}

  constexpr ColorRGBfloat& operator=(const ColorRGBfloat& other) {
    red = other.R();
    green = other.G();
    blue = other.B();
    return *this;
  }

  [[nodiscard]] constexpr ColorRGBfloat operator+(const ColorRGBfloat& other) const{
    return ColorRGBfloat{ red + other.R(), green + other.G(), blue + other.B()};
  }

  [[nodiscard]] constexpr ColorRGBfloat operator-(const ColorRGBfloat& other) const{
    return ColorRGBfloat{ red - other.R(), green - other.G(), blue - other.B() };
  }

  [[nodiscard]] constexpr ColorRGBfloat operator*(const double factor) const{
    return ColorRGBfloat{ red * factor, green * factor, blue * factor };
  }

  [[nodiscard]] constexpr ColorRGBfloat operator/(const double factor) const{
    return ColorRGBfloat{ red / factor, green / factor, blue / factor};
  }

  [[nodiscard]] constexpr double R() const {
    return red;
  }

  [[nodiscard]] constexpr double G() const {
    return green;
  }

  [[nodiscard]] constexpr double B() const {
    return blue;
  }

  constexpr void SetR(const double red_) {
    red = std::clamp(red_, 0.0, 1.0);
  }

  constexpr void SetG(const double green_) {
    green = std::clamp(green_, 0.0, 1.0);
  }

  constexpr void SetB(const double blue_) {
    blue = std::clamp(blue_, 0.0, 1.0);
  }

  [[nodiscard]] constexpr ColorRGB255 ToColorRGB255() const{
    return ColorRGB255(red * 255, green * 255, blue * 255);
  }

private:
  double red, green, blue;
};

[[nodiscard]] constexpr ColorRGBfloat operator*(const double factor, ColorRGBfloat& color) {
  using std::clamp;
  return ColorRGBfloat{ color.R() * factor, color.G() * factor, color.B() * factor };
}

} //namespace ras