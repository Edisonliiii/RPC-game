#ifndef VISITOR_AREA_VISITOR_H_
#define VISITOR_AREA_VISITOR_H_
// user-defined dependency
#include "visitor.h"

// AreaVisitor class
// Example:
//    include "area_visitor.h" and implement it
class AreaVisitor : public Visitor
{
public:
  // Calculate the area of circles
  // [Parameter]: rectangle_object(Circle*): pointing to circle object
  // [Return]: int: the area value of the rectangle_object
  int CircleArea(Circle* rectangle_object) const override;
  // Calculate the area of rectangles
  // [Parameter]: rectangle_object(Rectangle*): pointing to rectangle object
  // [Return]: int: the area value of the rectangle_object
  int RectangleArea(Rectangle* rectangle_object) const override;
  // Calculate the area of triangles
  // [Parameter]: triangle_object(Triangle*): pointing to triangle object
  // [Return]: int: the area value of the triangle_object
  int TriangleArea(Triangle* triangle_object) const override;
};

#endif // VISITOR_AREA_VISITOR_H_