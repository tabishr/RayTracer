#include "Scene.hh"
#include "SceneObject.hh"
#include "algorithm"

#include <cfloat>
#include <vector>
#include <cmath>

void Scene :: addSceneObject(SceneObject* newSceneObject){
  sceneObjects.push_back(newSceneObject);
}

void Scene :: addLight(Light* newLight){
  lights.push_back(newLight);
}

Scene :: ~Scene(void){
  std::for_each(sceneObjects.begin(), sceneObjects.end(), DeleteObject());
  std::for_each(lights.begin(), lights.end(), DeleteObject());
}

RGBColor Scene :: traceRay(const Ray &r) const{
  float tIntersect;
  SceneObject* closestSceneObject = findClosestObject(r, tIntersect);

  Vector3F intersectLoc;
  Vector3F intersectNorm;
  Vector3F distance;

  /* Default background: black */
  RGBColor rayColor(0, 0, 0);

  /* There is an intersection */
  if(closestSceneObject){
    std::vector<Light*>::const_iterator it;
    for(it = lights.begin(); it != lights.end(); it++){
      intersectLoc = r.getPointAtT(tIntersect);

      distance = (*it)->get_position() - intersectLoc;
      distance = distance.normalize();

      intersectNorm = closestSceneObject->surfaceNormal(intersectLoc);

      rayColor += (*it)->get_color() * 
	closestSceneObject->get_surfaceColor() * 
	fmaxf(distance * intersectNorm, 0);
    }
  }
  
  return rayColor;
}


SceneObject* Scene::findClosestObject(const Ray &r, float &tIntersect) const{
  /* Assume there is no intersection. */
  SceneObject* closestObject = 0;
  float closestIntersectTime = FLT_MAX;
  float intersectTime;

  std::vector<SceneObject*>::const_iterator it;
  for(it = sceneObjects.begin(); it != sceneObjects.end(); it++){
    intersectTime = (*it)->intersection(r);
    if(intersectTime != NO_INTERSECTION && intersectTime < closestIntersectTime){
      closestIntersectTime = intersectTime;
      closestObject = *it;
    }
  }

  tIntersect = closestIntersectTime;
  return closestObject;
}
