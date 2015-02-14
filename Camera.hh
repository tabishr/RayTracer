#ifndef _CAMERA_HH_
#define _CAMERA_HH_

#include "Vector3F.hh"
#include "Ray.hh"

#define SIXTY_DEG_TO_RAD 1.04719755

class Camera{

  Vector3F loc;
  Vector3F dir; /* Normalized */
  float fieldOfView; /* In radians */
  Vector3F cameraUp; /* Normalized */
  Vector3F cameraRight; /* Normalized */
  float distance;

public:
  Camera(Vector3F loc, Vector3F lookAt, Vector3F up, float fieldOfView = SIXTY_DEG_TO_RAD);

  Ray getRayForPixel(int x, int y, int imgSize) const;
};


#endif /* _CAMERA_HH_ */
