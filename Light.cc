#include "Lights.hh"

Lights :: Lights(Vector3F position, RGBColor color){
  this->position = position;
  this->color = color;
}

Vector3F get_position(void) const{
  return position;
}

RGBColor get_color(void) const{
  return RGBColor;
}
