#ifndef _VECTOR3F_HH_
#define _VECTOR3F_HH_

#include <iostream>

// 3D vector representation
class Vector3F{
  // 0: X, 1: Y, 2: Z
  float elems[3];

public:
  Vector3F();
  Vector3F(float x, float y, float z);
  
  float operator()(int axis) const;
  float & operator()(int axis);
  Vector3F & operator+=(const Vector3F &Vector3F_RHS);
  Vector3F & operator-=(const Vector3F &Vector3F_RHS);
  Vector3F & operator*=(const float scalar);
  Vector3F & operator/=(const float scalar);
  const Vector3F operator+(const Vector3F &Vector3F_RHS) const;
  const Vector3F operator-(const Vector3F &Vector3F_RHS) const;
  const Vector3F operator*(const float scalar) const;
  const Vector3F operator/(const float scalar) const;

  // Unary negation
  const Vector3F operator-(void) const;

  // Dot product
  const float operator*(const Vector3F &Vector3F_RHS) const;

  // Cross product
  const Vector3F operator^(const Vector3F &Vector3F_RHS) const;

  // Magnitude and magnitude squared
  const float mag(void) const;
  const float mag2(void) const;

  const Vector3F normalize(void) const;
};

// Allow RHS versions of certain arithmetic operations.
const Vector3F operator*(float scalar, const Vector3F &Vector3F_RHS);
std::ostream & operator<<(std::ostream &os, const Vector3F &v);

#endif /* _VECTOR3F_HH_ */
