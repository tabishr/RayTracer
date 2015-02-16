#ifndef _CAMERA_HH_
#define _CAMERA_HH_

#include "Vector3F.hh"
#include "Ray.hh"

class Camera{

  Vector3F loc;
  Vector3F dir; /* Normalized */
  float fieldOfView; /* In radians */
  Vector3F cameraUp; /* Normalized */
  Vector3F cameraRight; /* Normalized */
  float distance;

public:
  Camera(Vector3F loc, Vector3F lookAt, Vector3F up, float fieldOfView = 60);

  Ray getRayForPixel(int x, int y, int imgSize) const;
};


#endif /* _CAMERA_HH_ */
