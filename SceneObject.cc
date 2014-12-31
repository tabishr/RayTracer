#include "SceneObject.hh"
#include "RGBColor.hh"

SceneObject :: SceneObject(void){
  surfaceColor = RGBColor(0.5, 0.5, 0.5);
}

RGBColor SceneObject :: get_surfaceColor(void) const{
  return surfaceColor;
}

void SceneObject :: set_surfaceColor(const RGBColor &color){
  surfaceColor = color;
}

RGBColor SceneObject :: surfaceColorAtPoint(const Vector3F &point) const{
  /* Simple implementation for now; will add textures later */
  return surfaceColor;
}

SceneObject :: ~SceneObject(void){ }
