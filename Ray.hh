#include "Vector3F.hh"

class Ray{
  
  Vector3F orig;
  Vector3F dir;

public:
  Ray(const Vector3F &orig, const Vector3F &dir, bool normalize = true);
  Vector3F get_orig(void) const;
  Vector3F get_dir(void) const;
  Vector3F getPointAtT(float t) const;
};
