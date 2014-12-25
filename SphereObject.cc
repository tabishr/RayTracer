#include "SphereObject.hh"

SphereObject :: SphereObject(const Vector3F &center, float radius){
  this->center = center;
  this->radius = radius;
}

Vector3F SphereObject :: get_center(void){
  return center;
}

float SphereObject :: get_radius(void){
  return radius;
}
