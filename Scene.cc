#include "Scene.hh"
#include "SceneObject.hh"
#include "algorithm"

#include <cfloat>
#include <vector>
#include <cmath>
#include <cassert>

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
  float tIntersect = NO_INTERSECTION;
  SceneObject* closestSceneObject = findClosestObject(r, tIntersect);

  assert(closestSceneObject);
  assert(tIntersect != NO_INTERSECTION);

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
  }else{
    /* Just crash */
    assert(1 == 0);
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
    assert(intersectTime != NO_INTERSECTION);
    if(intersectTime != NO_INTERSECTION && intersectTime < closestIntersectTime){
      closestIntersectTime = intersectTime;
      closestObject = *it;
    }
  }

  tIntersect = closestIntersectTime;
  return closestObject;
}

void Scene::render(const Camera &camera, int imgSize, std::ostream &outputStream){

  outputStream << "P3" << " " << imgSize << " " << imgSize << " " << MAXRGB << std::endl;
    
  for(int y = 0 ; y < imgSize ; y++){
    for(int x = 0 ; x < imgSize ; x++){
      Ray pixelRay = camera.getRayForPixel(x, y, imgSize);
      RGBColor pixelColor = traceRay(pixelRay);
      
      pixelColor *= MAXRGB;
      pixelColor.clamp(0, MAXRGB);

      outputStream << pixelColor.get_red() << " ";
      outputStream << pixelColor.get_green() << " ";
      outputStream << pixelColor.get_blue() << std::endl;

    }
  }
}
