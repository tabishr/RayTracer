#ifndef _SPHEREOBJECT_HH_
#define _SPHEREOBJECT_HH_

#include "SceneObject.hh"
#include "Vector3F.hh"

class SphereObject : public SceneObject{

  Vector3F center;
  float radius;

public:
  SphereObject(const Vector3F &center, float radius);
  Vector3F get_center(void) const;
  float get_radius(void) const;
  int getIntersections(const Ray &r, float &t1, float &t2) const;

  /* Overriding pure virtual functions */
  float intersection(const Ray &r) const;
  Vector3F surfaceNormal(const Vector3F &point) const;
};

#endif /* _SPHEREOBJECT_HH_ */
