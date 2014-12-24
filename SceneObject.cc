#include "SceneObject.hh"

SceneObject :: SceneObject(void){
  surfaceColor = RGBColor(0.5, 0.5, 0.5);
}

SceneObject :: RGBColor get_surfaceColor(void) const{
  return surfaceColor;
}

SceneObject :: void set_surfaceColor(const RGBColor &color){
  surfaceColor = color;
}

SceneObject :: RGBColor surfaceColorAtPoint(const Vector3F &point) const{
  /* Simple implementation for now; will add textures later */
  return surfaceColor;
}

