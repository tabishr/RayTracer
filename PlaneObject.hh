#ifndef _PLANEOBJECT_HH_
#define _PLANEOBJECT_HH_

#include "SceneObject.hh"
#include "Vector3F.hh"

class PlaneObject: public SceneObject{

  Vector3F surfaceNormal;
  float distanceFromOrigin;

  PlaneObject(const Vector3F &surfaceNormal, float distanceFromOrigin);
  Vector3F get_surfaceNormal(void) const;
  float get_distanceFromOrigin(void) const;

};

#endif /* _PLANEOBJECT_HH_ */
