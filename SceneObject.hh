#ifndef _SCENEOBJECT_HH_
#define _SCENEOBJECT_HH_

#include "RGBColor.hh"
#include "Ray.hh"
#include "Vector3F.hh"

#define NO_INTERSECTION -1

class SceneObject{

  RGBColor surfaceColor;

public:
  SceneObject(void);
  RGBColor get_surfaceColor(void) const;
  void set_surfaceColor(const RGBColor &color);
  RGBColor surfaceColorAtPoint(const Vector3F &point) const;
  virtual float intersection(const Ray &r) const = 0;
  virtual Vector3F surfaceNormal(const Vector3F &point) const = 0;
  virtual ~SceneObject(void);
};

#endif /* _SCENEOBJECT_HH_ */
