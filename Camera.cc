#include "Camera.hh"
#include "Vector3F.hh"
#include "Ray.hh"

#include <cmath>

Camera :: Camera(Vector3F loc, Vector3F lookAt, Vector3F up, float fieldOfView){
  this->loc = loc;
  
  this->dir = lookAt - loc;
  this->dir = this->dir.normalize();

  this->cameraRight = this->dir ^ up;
  this->cameraUp = this->cameraRight ^ this->dir;

  this->distance = 0.5 / tanf(this->fieldOfView / 2.0);
}

Ray Camera :: getRayForPixel(int x, int y, int imgSize) const{
  
  Vector3F pixelDir = this->distance * this->dir + 
    (0.5 - (float)y / (float)(imgSize - 1)) * this->cameraUp +
    ((float) x / (float)(imgSize - 1) - 0.5) * this->cameraRight;

  Ray pixelRay(this->loc, pixelDir);
  return pixelRay;
}
