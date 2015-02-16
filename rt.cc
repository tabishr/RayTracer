#include <iostream>

#include "SceneObject.hh"
#include "PlaneObject.hh"
#include "SphereObject.hh"
#include "Vector3F.hh"
#include "RGBColor.hh"
#include "Light.hh"
#include "Camera.hh"
#include "Scene.hh"

#define IMGSIZE 512

int main(void){

  // Configure the plane
  Vector3F planeSurfaceNormal(0, 1, 0);
  RGBColor planeColor(0.5, 0, 0.5);
  PlaneObject* plane = new PlaneObject(planeSurfaceNormal, 0);
  plane->set_surfaceColor(planeColor);

  // Configure the objects (three spheres - red, green and blue)
  /*
  float sphereRadius = 0.5;

  Vector3F rSphereCenter(-1.2, 0.5, 0);
  RGBColor rSphereColor(1, 0, 0);
  SphereObject* rSphere = new SphereObject(rSphereCenter, sphereRadius);
  rSphere->set_surfaceColor(rSphereColor);
  
  Vector3F gSphereCenter(0, 0.5, 0);
  RGBColor gSphereColor(0, 1, 0);
  SphereObject gSphere(gSphereCenter, sphereRadius);
  gSphere.set_surfaceColor(gSphereColor);

  Vector3F bSphereCenter(1.2, 0.5, 0);
  RGBColor bSphereColor(0, 0, 1);
  SphereObject bSphere(bSphereCenter, sphereRadius);
  bSphere.set_surfaceColor(bSphereColor);
  */

  // Configure the light sources (two lights - a and b)
  Vector3F lightAPos(-10, 10, 5);
  RGBColor lightAColor(0.8, 0.8, 0.8);
  Light* lightA = new Light(lightAPos, lightAColor);

  Vector3F lightBPos(5, 3, 5);
  RGBColor lightBColor(0.3, 0.3, 0.3);
  Light* lightB = new Light(lightBPos, lightBColor);

  // Configure the camera
  Vector3F cameraPos(-1.5, 1, 3);
  Vector3F cameraLookAt(-0.3, 0.5, 0);
  Vector3F cameraUp(0, 1, 0);
  Camera camera(cameraPos, cameraLookAt, cameraUp);

  // Configure the scene
  Scene scene;
  scene.addSceneObject(plane);
  /*
  scene.addSceneObject(rSphere);
  scene.addSceneObject(&gSphere);
  scene.addSceneObject(&bSphere);
  */
  scene.addLight(lightA);
  scene.addLight(lightB);
  
  // Render!
  scene.render(camera, IMGSIZE, std::cout);

  return 0;
}

// To compile
// g++ -Wall -Werror -o rt rt.cc SceneObject.cc PlaneObject.cc SphereObject.cc Vector3F.cc RGBColor.cc Light.cc Camera.cc Scene.cc Ray.cc

