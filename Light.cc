#include "Light.hh"

Light :: Light(Vector3F position, RGBColor color){
  this->position = position;
  this->color = color;
}

Vector3F Light :: get_position(void) const{
  return position;
}

RGBColor Light :: get_color(void) const{
  return color;
}
