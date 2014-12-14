#include "RGBColor.hh"

RGBColor::RGBColor(void){
  colors[0] = 0;
  colors[1] = 0;
  colors[2] = 0;
}

RGBColor::RGBColor(float red, float green, float blue){
  colors[0] = red;
  colors[1] = green;
  colors[2] = blue;
}

float RGBColor::get_red(void) const{
  return colors[0];
}

float RGBColor::get_green(void) const{
  return colors[1];
}

float RGBColor::get_blue(void) const{
  return colors[2];
}

void RGBColor::set_red(const float red){
  colors[0] = red;
}

void RGBColor::set_green(const float green){
  colors[1] = green;
}

void RGBColor::set_blue(const float blue){
  colors[2] = blue;
}

const RGBColor RGBColor::operator+(const RGBColor &RGBColor_RHS) const{
  RGBColor temp = *this;
  return temp += RGBColor_RHS;
}

const RGBColor RGBColor::operator-(const RGBColor &RGBColor_RHS) const{
  RGBColor temp = *this;
  return temp -= RGBColor_RHS;
}

const RGBColor RGBColor::operator*(const RGBColor &RGBColor_RHS) const{
  RGBColor temp = *this;
  return temp *= RGBColor_RHS;
}

RGBColor & RGBColor::operator+=(const RGBColor &RGBColor_RHS){
  colors[0] += RGBColor_RHS.get_red();
  colors[1] += RGBColor_RHS.get_green();
  colors[2] += RGBColor_RHS.get_blue();

  return *this;
}

RGBColor & RGBColor::operator-=(const RGBColor &RGBColor_RHS){
  colors[0] -= RGBColor_RHS.get_red();
  colors[1] -= RGBColor_RHS.get_green();
  colors[2] -= RGBColor_RHS.get_blue();

  return *this;
}

RGBColor & RGBColor::operator*=(const RGBColor &RGBColor_RHS){
  colors[0] *= RGBColor_RHS.get_red();
  colors[1] *= RGBColor_RHS.get_green();
  colors[2] *= RGBColor_RHS.get_blue();

  return *this;
}

const RGBColor RGBColor::operator*(const float scalar) const{
  RGBColor temp = *this;
  return temp *= scalar;
}

const RGBColor RGBColor::operator/(const float scalar) const{
  RGBColor temp = *this;
  return temp /= scalar;
}

const RGBColor RGBColor::operator*=(const float scalar){
  colors[0] *= scalar;
  colors[1] *= scalar;
  colors[2] *= scalar;

  return *this;
}

const RGBColor RGBColor::operator/=(const float scalar){
  colors[0] /= scalar;
  colors[1] /= scalar;
  colors[2] /= scalar;

  return *this;
}

const RGBColor operator*(float scalar, const RGBColor &RGBColor_RHS){
  return RGBColor_RHS * scalar;
}

std::ostream & operator<<(std::ostream &os, const RGBColor &c){
  os << "(" << c.get_red() << ","
     << c.get_green() << ","
     << c.get_blue() << ")";

  return os;
}
