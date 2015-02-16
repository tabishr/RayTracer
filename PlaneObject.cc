#include "PlaneObject.hh"

PlaneObject :: PlaneObject(const Vector3F &surfaceNormal, float distanceFromOrigin){
  this->surfaceNorm = surfaceNormal;
  this->distanceFromOrigin = distanceFromOrigin;
}

Vector3F PlaneObject :: get_surfaceNormal(void) const{
  return surfaceNorm;
}

float PlaneObject :: get_distanceFromOrigin(void) const{
  return distanceFromOrigin;
}

/* Intersection point of a ray is: t = -(P · N + d) / (D · N) */
float PlaneObject :: intersection(const Ray &r) const{
  float intersectionPoint;

  Vector3F rayDir = r.get_dir();
  Vector3F rayOrig = r.get_orig();

  float denominator = rayDir * surfaceNorm;
  float numerator = -((rayOrig * surfaceNorm) + distanceFromOrigin);

  if(denominator == 0){
    intersectionPoint = NO_INTERSECTION;
  }else{
    intersectionPoint = numerator / denominator;

    /* Only values of t >= 0 are considered to be intersections */
    if(intersectionPoint < 0){
      intersectionPoint = 0;
    }
  }

  return intersectionPoint;
}

Vector3F PlaneObject :: surfaceNormal(const Vector3F &point) const{
  return surfaceNorm;
}
