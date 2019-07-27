#pragma once

#include <cstdint>
#include <algorithm>

namespace ras {

namespace literals{

constexpr int32_t COLOR_MIN = static_cast<int32_t>(0);
constexpr int32_t COLOR_MAX = static_cast<int32_t>(255);
constexpr double COLORF_MIN = 0.0;
constexpr double COLORF_MAX = 1.0;


} // namespace literals

class ColorRGBfloat;

// 0~255で各色を表すRGBカラークラス
class ColorRGB255 {
public:
  constexpr ColorRGB255()
    : red{ literals::COLOR_MIN }
    , green{ literals::COLOR_MIN }
    , blue{ literals::COLOR_MIN } {}

  constexpr ColorRGB255(int32_t red_, int32_t green_, int32_t blue_)
    : red{ std::clamp( red_, literals::COLOR_MIN, literals::COLOR_MAX) }
    , green{ std::clamp( green_, literals::COLOR_MIN, literals::COLOR_MAX) }
    , blue{ std::clamp( blue_, literals::COLOR_MIN, literals::COLOR_MAX) } {}

  constexpr ColorRGB255(const ColorRGB255& other)
    : red{ other.R() }
    , green{ other.G() }
    , blue{ other.B() } {}

  constexpr ColorRGB255(const ColorRGBfloat& other)
    : red{ std::clamp(static_cast<int32_t>(other.R() * literals::COLOR_MAX), literals::COLOR_MIN, literals::COLOR_MAX) }
    , green{ std::clamp(static_cast<int32_t>(other.G() * literals::COLOR_MAX), literals::COLOR_MIN, literals::COLOR_MAX) }
    , blue{ std::clamp(static_cast<int32_t>(other.B() * literals::COLOR_MAX), literals::COLOR_MIN, literals::COLOR_MAX) } {}

  constexpr ColorRGB255& operator=(const ColorRGB255& other){
    red = other.R();
    green = other.G();
    blue = other.B();
    return *this;
  }

  [[nodiscard]] constexpr ColorRGB255 operator+(const ColorRGB255& other) const{
    return ColorRGB255{red + other.R(), green + other.G(), blue + other.B()};
  }

  [[nodiscard]] constexpr ColorRGB255 operator-(const ColorRGB255& other) const{
    return ColorRGB255{ red - other.R(), green - other.G(), blue - other.B() };
  }

  [[nodiscard]] constexpr ColorRGB255 operator*(const int32_t factor) const{
    return ColorRGB255{red * factor, green * factor, blue * factor};
  }

  [[nodiscard]] constexpr ColorRGB255 operator/(const int32_t factor) const{
    return ColorRGB255{red / factor, green / factor, blue / factor};
  }

  [[nodiscard]] constexpr int32_t R() const{
    return red;
  }

  [[nodiscard]] constexpr int32_t G() const{
    return green;
  }

  [[nodiscard]] constexpr int32_t B() const{
    return blue;
  }

  constexpr void SetR (const int32_t red_){
    red = std::clamp(red_, literals::COLOR_MIN, literals::COLOR_MAX);
  }

  constexpr void SetG(const int32_t green_) {
    green = std::clamp(green_, literals::COLOR_MIN, literals::COLOR_MAX);
  }

  constexpr void SetB(const int32_t blue_) {
    blue = std::clamp(blue_, literals::COLOR_MIN, literals::COLOR_MAX);
  }

  /*[[nodiscard]] constexpr ColorRGBfloat ToColorRGBfloat () const{
    return ColorRGBfloat(static_cast<double>(red) / literals::COLOR_MAX
                         , static_cast<double>(green) / literals::COLOR_MAX
                         , static_cast<double>(blue) / literals::COLOR_MAX);
  }*/

private:
  int32_t red, green, blue;
};

[[nodiscard]] constexpr ColorRGB255 operator*(const int32_t factor, ColorRGB255& color) {
  using std::clamp;
  return ColorRGB255{ color.R() * factor, color.G() * factor, color.B() * factor};
}

// 0.0~1.0で各色を表すRGBカラークラス
class ColorRGBfloat {
public:
  constexpr ColorRGBfloat()
    : red{ literals::COLORF_MIN }
    , green{ literals::COLORF_MIN }
    , blue{ literals::COLORF_MIN } {}

  constexpr ColorRGBfloat(double red_, double green_, double blue_)
    : red{ std::clamp(red_, literals::COLORF_MIN, literals::COLORF_MAX) }
    , green{ std::clamp(green_, literals::COLORF_MIN, literals::COLORF_MAX) }
    , blue{ std::clamp(blue_, literals::COLORF_MIN, literals::COLORF_MAX) } {}

  constexpr ColorRGBfloat(const ColorRGBfloat& other)
    : red{ std::clamp(other.R(), literals::COLORF_MIN, literals::COLORF_MAX) }
    , green{ std::clamp(other.G(), literals::COLORF_MIN, literals::COLORF_MAX) }
    , blue{ std::clamp(other.B(), literals::COLORF_MIN, literals::COLORF_MAX) } {}

  constexpr ColorRGBfloat(const ColorRGB255& other)
    : red{ std::clamp(static_cast<decltype(red)>(other.R()) / literals::COLOR_MAX, literals::COLORF_MIN, literals::COLORF_MAX) }
    , green{ std::clamp(static_cast<decltype(red)>(other.G()) / literals::COLOR_MAX, literals::COLORF_MIN, literals::COLORF_MAX) }
    , blue{ std::clamp(static_cast<decltype(red)>(other.B()) / literals::COLOR_MAX, literals::COLORF_MIN, literals::COLORF_MAX)} {}

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
    red = std::clamp(red_, literals::COLORF_MIN, literals::COLORF_MAX);
  }

  constexpr void SetG(const double green_) {
    green = std::clamp(green_, literals::COLORF_MIN, literals::COLORF_MAX);
  }

  constexpr void SetB(const double blue_) {
    blue = std::clamp(blue_, literals::COLORF_MIN, literals::COLORF_MAX);
  }

  /*[[nodiscard]] constexpr ColorRGB255 ToColorRGB255() const{
    return ColorRGB255(red * literals::COLOR_MAX, green * literals::COLOR_MAX, blue * literals::COLOR_MAX);
  }*/

private:
  double red, green, blue;
};

[[nodiscard]] constexpr ColorRGBfloat operator*(const double factor, ColorRGBfloat& color) {
  using std::clamp;
  return ColorRGBfloat{ color.R() * factor, color.G() * factor, color.B() * factor };
}

} //namespace ras