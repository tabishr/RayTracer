#include <cassert>
#include <cstring>
#include <cmath>
#include <iostream>

#include "Vector3F.hh"

/* Member functions of class Vector3F */

// "Zero" vector
Vector3F::Vector3F(void){
  memset(elems, 0, sizeof(elems));
}

// Vector initialization
Vector3F::Vector3F(float x, float y, float z){
  elems[0] = x;
  elems[1] = y;
  elems[2] = z;
}

// Vector axis retrieval
float Vector3F::operator()(int axis) const{
  assert(axis >= 0 && axis <= 2);
  return elems[axis];
}

// Vector axis assignment
float & Vector3F::operator()(int axis){
  assert(axis >= 0 && axis <= 2);
  return elems[axis];
}

// Destructive vector addition
Vector3F & Vector3F::operator+=(const Vector3F &Vector3F_RHS){
  elems[0] += Vector3F_RHS(0);
  elems[1] += Vector3F_RHS(1);
  elems[2] += Vector3F_RHS(2);

  return *this;
}

// Destructive vector subtraction
Vector3F & Vector3F::operator-=(const Vector3F &Vector3F_RHS){
  elems[0] -= Vector3F_RHS(0);
  elems[1] -= Vector3F_RHS(1);
  elems[2] -= Vector3F_RHS(2);

  return *this;
}

// Vector addition
const Vector3F Vector3F::operator+(const Vector3F &Vector3F_RHS) const{
  Vector3F result = *this;
  return result += Vector3F_RHS;
}

// Vector subtraction
const Vector3F Vector3F::operator-(const Vector3F &Vector3F_RHS) const{
  Vector3F result = *this;
  return result -= Vector3F_RHS;
}

// Unary negation
const Vector3F Vector3F::operator-(void) const{
  Vector3F result = *this;
  return -1 * result;
}

// Destructive scalar multiplication
Vector3F & Vector3F::operator*=(const float scalar){
  elems[0] *= scalar;
  elems[1] *= scalar;
  elems[2] *= scalar;

  return *this;
}

// Destructive scalar division
Vector3F & Vector3F::operator/=(const float scalar){
  elems[0] /= scalar;
  elems[1] /= scalar;
  elems[2] /= scalar;

  return *this;
}

// Scalar multiplication (vector on LHS, scalar on RHS)
const Vector3F Vector3F::operator*(const float scalar) const{
  Vector3F result = *this;
  return result *= scalar;
}

// Scalar division
const Vector3F Vector3F::operator/(const float scalar) const{
  Vector3F result = *this;
  return result /= scalar;
}

// Dot product
const float Vector3F::operator*(const Vector3F &Vector3F_RHS) const{
  float dotProduct = 0;
  dotProduct = elems[0] * Vector3F_RHS(0) + elems[1] * Vector3F_RHS(1) +
    elems[2] * Vector3F_RHS(2);
  return dotProduct;
}

// Cross product
const Vector3F Vector3F::operator^(const Vector3F &Vector3F_RHS) const{
  float crossProductX = 0;
  float crossProductY = 0;
  float crossProductZ = 0;
  
  crossProductX = elems[1] * Vector3F_RHS(2) - elems[2] * Vector3F_RHS(1);
  crossProductY = elems[2] * Vector3F_RHS(0) - elems[0] * Vector3F_RHS(2);
  crossProductZ = elems[0] * Vector3F_RHS(1) - elems[1] * Vector3F_RHS(0);

  Vector3F crossProduct(crossProductX, crossProductY, crossProductZ);
  return crossProduct;
}

// Magnitude
const float Vector3F::mag(void) const{
  float magnitudeSquared = this->mag2();
  return sqrtf(magnitudeSquared);
}

// Magnitude squared
const float Vector3F::mag2(void) const{
  // Magnitude squared is equal to dot product of itself
  Vector3F temp = *this;
  return temp * temp;
}

// Normalize
const Vector3F Vector3F::normalize(void) const{
  Vector3F temp = *this;
  float mag = temp.mag();

  assert(mag != 0);
  return temp / mag;
}

/* Non-member functions */

// Print vector: (x,y,z)
std::ostream & operator<<(std::ostream &os, const Vector3F &v){
  os << "(" << v(0) << ","
     << v(1) << ","
     << v(2) << ")";

  return os;
}

// Scalar multiplication (scalar on LHS, vector on RHS)
const Vector3F operator*(float scalar, const Vector3F &Vector3F_RHS){
  Vector3F result = Vector3F_RHS;
  return result * scalar;
}
