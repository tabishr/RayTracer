#include "Ray.hh"

Ray :: Ray(const Vector3F &orig, const Vector3F &dir, bool normalize){
  this->orig = orig;

  if(normalize == true){
    this->dir = dir.normalize();
  }else{
    this->dir = dir;
  }
}

Vector3F Ray :: get_orig(void) const{
  return orig;
}

Vector3F Ray :: get_dir(void) const{
  return dir;
}

Vector3F Ray::getPointAtT(float t) const{
  return orig + t * dir;
}
