#include "Camera.hh"
#include "Vector3F.hh"

#include <cmath>

Camera :: Camera(Vector3F loc, Vector3F lookAt, Vector3F up, float fieldOfView){
  this->loc = loc;
  
  this->dir = lookAt - loc;
  this->dir = this->dir.normalize();

  this->cameraRight = this->dir ^ up;
  this->cameraUp = this->cameraRight ^ this->dir;

  this->distance = 0.5 / tanf(this->fieldOfView / 2);
}
