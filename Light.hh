#ifndef _LIGHT_HH_
#define _LIGHT_HH_

#include "Vector3F.hh"
#include "RGBColor.hh"

class Light{
  Vector3F position;
  RGBColor color;

public:
  Light(Vector3F position, RGBColor color);
  Vector3F get_position(void) const;
  RGBColor get_color(void) const;
};

#endif /* _LIGHT_HH_ */
