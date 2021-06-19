#include "area_visitor.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

#include <stdarg.h>
#include <iostream>

const double PI = 3.14;

void printer(std::string type, int area, int property_number, ...)
{
  int val;
  va_list vl;
  va_start(vl, property_number);

  std::cout << "Type: " << type << std::endl;
  std::cout << "Data: ";
  for(int i=0; i<property_number; ++i)
  {
    val=va_arg(vl, int);
    std::cout << val << " ";
  }
  std::cout << std::endl;
  std::cout << "Area: " << area << std::endl;
}

int AreaVisitor::CircleArea(Circle* circle_object) const
{
  int radius = circle_object->GetRadius();
  int area = PI*radius*radius;
  printer("Circle", area, 1, radius);
  return area;
}

int AreaVisitor::RectangleArea(Rectangle* rectangle_object) const
{
  int length = rectangle_object->GetLength();
  int width = rectangle_object->GetWidth();
  int area = length * width;
  printer("Rectangle", area, 2, length, width);
  return area;
}

int AreaVisitor::TriangleArea(Triangle* triangle_object) const
{
  int base = triangle_object->GetBase();
  int height = triangle_object->GetHeight();
  int area = base * height / 2;
  printer("Triangle", area, 2, base, height);
  return area;
}