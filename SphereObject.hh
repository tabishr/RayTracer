#ifndef _SPHEREOBJECT_HH_
#define _SPHEREOBJECT_HH_

#include "SceneObject.hh"
#include "Vector3F.hh"

class SphereObject: public SceneObject{

  Vector3F center;
  float radius;

  SphereObject(const Vector3F &center, float radius);
  Vector3F get_center(void);
  float get_radius(void);
};

#endif /* _SPHEREOBJECT_HH_ */
