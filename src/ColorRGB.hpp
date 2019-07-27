#pragma once

#include <cstdint>
#include <algorithm>

namespace ras {

namespace literals{

constexpr int32_t COLOR_MIN = static_cast<int32_t>(0);
constexpr int32_t COLOR_MAX = static_cast<int32_t>(255);

} // namespace literals

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

  [[nodiscard]] constexpr ColorRGB255 operator*(const double factor) const{
    return ColorRGB255{static_cast<int32_t>(red * factor), static_cast<int32_t>(green * factor), static_cast<int32_t>(blue * factor)};
  }

  [[nodiscard]] constexpr ColorRGB255 operator/(const double factor) const{
    return ColorRGB255{ static_cast<int32_t>(red / factor), static_cast<int32_t>(green / factor), static_cast<int32_t>(blue / factor) };
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

private:
  int32_t red, green, blue;
};

[[nodiscard]] constexpr ColorRGB255 operator*(const double factor, const ColorRGB255& color) {
  using std::clamp;
  return ColorRGB255{ static_cast<int32_t>(color.R() * factor), static_cast<int32_t>(color.G() * factor), static_cast<int32_t>(color.B() * factor) };
}

} //namespace ras