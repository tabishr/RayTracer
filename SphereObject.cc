#include "SphereObject.hh"
#include <cmath>

SphereObject :: SphereObject(const Vector3F &center, float radius){
  this->center = center;
  this->radius = radius;
}

Vector3F SphereObject :: get_center(void) const{
  return center;
}

float SphereObject :: get_radius(void) const{
  return radius;
}

float SphereObject :: intersection(const Ray &r) const{
  /* Output variables */
  float t1;
  float t2;

  getIntersections(r, t1, t2);

  /* t1 is either "NO_INTERSECTION" or the closest variable */
  return t1;
}

int SphereObject :: getIntersections(const Ray &r, float &t1, float &t2) const{
  Vector3F rayDir = r.get_dir();
  Vector3F rayOrig = r.get_orig();
  int numIntersections = 0;

  /* Quadratic equation coefficients */
  float a = rayDir * rayDir;
  float b = 2 * (rayOrig * rayDir - rayDir * center);
  float c = rayOrig * rayOrig + center * center - 
    2 * (rayOrig * center) - radius * radius;

  float root1 = 0;
  float root2 = 0;
  float discriminant = b*b - 4*a*c;

  if(discriminant > 0){
    root1 = (-b + sqrt(discriminant)) / (2 * a);
    root2 = (-b - sqrt(discriminant)) / (2 * a);

    if(root1 > 0){
      numIntersections++;
    }

    if(root2 > 0){
      numIntersections++;
    }

    /* Smallest root always in t1 */
    if(root1 < root2){
      t1 = root1;
      t2 = root2;
    }else{
      t1 = root2;
      t2 = root1;
    }

    if(t1 < 0){
      t1 = NO_INTERSECTION;
    }

    if(t2 < 0){
      t2 = NO_INTERSECTION;
    }
  }

  return numIntersections;
}

/* 
 * n(X) = (X - C) / |X - C| 
 * Subtrace point from center and then normalize.
 */
Vector3F SphereObject :: surfaceNormal(const Vector3F &point) const{
  Vector3F surfaceNormal = point - center;
  return surfaceNormal.normalize();
}
