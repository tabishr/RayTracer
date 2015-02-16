#ifndef _RGBCOLOR_HH_
#define _RGBCOLOR_HH_

#include <iostream>

#define NUMCOLORS 3
#define MAXRGB 255

// RGB color representation
class RGBColor{
  // 0: red, 1: green, 2: blue
  float colors[NUMCOLORS];

public:
  RGBColor(void);
  RGBColor(float red, float green, float blue);

  float get_red(void) const;
  float get_green(void) const;
  float get_blue(void) const;

  void set_red(const float red);
  void set_green(const float green);
  void set_blue(const float blue);
  
  // Ensure valid colors by clamping
  void clamp(float minVal, float maxVal);

  // Color operations
  const RGBColor operator+(const RGBColor &RGBColor_RHS) const;
  const RGBColor operator-(const RGBColor &RGBColor_RHS) const;
  const RGBColor operator*(const RGBColor &RGBColor_RHS) const;
  RGBColor & operator+=(const RGBColor &RGBColor_RHS);
  RGBColor & operator-=(const RGBColor &RGBColor_RHS);
  RGBColor & operator*=(const RGBColor &RGBColor_RHS);

  // Scalar operations
  const RGBColor operator*(const float scalar) const;
  const RGBColor operator/(const float scalar) const;
  const RGBColor operator*=(const float scalar);
  const RGBColor operator/=(const float scalar);
};

// Allow RHS versions of certain arithmetic operations.
const RGBColor operator*(float scalar, const RGBColor &RGBColor_RHS);
std::ostream & operator<<(std::ostream &os, const RGBColor &c);

#endif /* _RGBCOLOR_HH_ */
