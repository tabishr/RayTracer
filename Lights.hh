#ifndef _LIGHTS_HH_
#define _LIGHTS_HH_

#include "Vector3F.hh"
#include "RGBColor"

class Lights{
  Vector3F position;
  RGBColor color;

public:
  Lights(Vector3F position, RGBColor color);
  Vector3F get_position(void) const;
  RGBColor get_color(void) const;
};

#endif /* _LIGHTS_HH_ */
