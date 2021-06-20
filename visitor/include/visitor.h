#ifndef VISITOR_VISITOR_H_
#define VISITOR_VISITOR_H_

// forwarding declaration
class Circle;
class Rectangle;
class Triangle;

// Visitor interface
// Example:
//    include "visitor.h" and implement it
class Visitor
{
public:
  virtual int CircleArea(Circle* circle_object) const = 0;
  virtual int RectangleArea(Rectangle* rectangle_object) const = 0;
  virtual int TriangleArea(Triangle* triangle_object) const = 0;
};

#endif // VISITOR_VISITOR_H_