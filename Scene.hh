#ifndef _SCENE_HH_
#define _SCENE_HH_

#include "SceneObject.hh"
#include "Light.hh"
#include "RGBColor.hh"

#include <vector>

struct DeleteObject{
  template<typename T>
  void operator()(const T *ptr) const{
    delete ptr;
  }
};

class Scene{

  std::vector<SceneObject*> sceneObjects;
  std::vector<Light*> lights;
  SceneObject* findClosestObject(const Ray &r, float &tIntersect) const;

public:
  void addSceneObject(SceneObject* newSceneObject);
  void addLight(Light* newLight);
  RGBColor traceRay(const Ray &r) const;
  ~Scene(void);
};

#endif /* _SCENE_HH_ */
