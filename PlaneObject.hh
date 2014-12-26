#ifndef _PLANEOBJECT_HH_
#define _PLANEOBJECT_HH_

#include "SceneObject.hh"
#include "Vector3F.hh"

class PlaneObject : public SceneObject{

  Vector3F surfaceNorm;
  float distanceFromOrigin;

public:
  PlaneObject(const Vector3F &surfaceNorm, float distanceFromOrigin);
  Vector3F get_surfaceNormal(void) const;
  float get_distanceFromOrigin(void) const;

  /* Overriding pure virtual functions */
  float intersection(const Ray &r) const;
  Vector3F surfaceNormal(const Vector3F &point) const;
};

#endif /* _PLANEOBJECT_HH_ */
