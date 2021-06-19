#ifndef VISITOR_AREA_VISITOR_H_
#define VISITOR_AREA_VISITOR_H_

#include "visitor.h"

class AreaVisitor : public Visitor
{
public:
  int CircleArea(Circle* circle_object) const override;
  int RectangleArea(Rectangle* rectangle_object) const override;
  int TriangleArea(Triangle* triangle_object) const override;
};

#endif // VISITOR_AREA_VISITOR_H_