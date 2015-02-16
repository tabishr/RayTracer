#include "Camera.hh"
#include "Vector3F.hh"
#include "Ray.hh"

#include <cmath>

#define PI 3.14159265

Camera :: Camera(Vector3F loc, Vector3F lookAt, Vector3F up, float fieldOfView){
  this->loc = loc;
  
  dir = lookAt - loc;
  dir = dir.normalize();

  cameraRight = dir ^ up;
  cameraRight = cameraRight.normalize();

  cameraUp = cameraRight ^ dir;
  cameraUp = cameraUp.normalize();

  float fieldOfViewRads = fieldOfView*PI / 180;

  distance = 0.5 / tanf(fieldOfViewRads / 2);

  /*
  std::cout << "denom: " << tanf(this->fieldOfView / (float)2) << std::endl;
  std::cout << "distance: " << distance << std::endl;
  std::cout << "loc: " << loc << std::endl;
  std::cout << "lookAt: " << lookAt << std::endl;
  std::cout << "up: " << up << std::endl;
  std::cout << "field of view: " << fieldOfView << std::endl;
  std::cout << "dir: " << dir << std::endl;
  std::cout << "cameraRight: " << cameraRight << std::endl;
  std::cout << "cameraUp: " << cameraUp << std::endl;
  */
}

Ray Camera :: getRayForPixel(int x, int y, int imgSize) const{
  
  Vector3F pixelDir = (distance * dir) + 
    (0.5 - (float)y / (float)(imgSize - 1)) * cameraUp +
    ((float) x / (float)(imgSize - 1) - 0.5) * cameraRight;

  Ray pixelRay(loc, pixelDir);
  return pixelRay;
}
