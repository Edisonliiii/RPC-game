// system dependency
#include <stdarg.h>
#include <iostream>
// user-defined dependency
#include "area_visitor.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

// use to calculate the area of circle
const double PI = 3.14;

// Utility funciton: use to print necessay information
// [Parameter]: type(string): Circle / Rectangle / Triangle ...
//              area(int): the area value of "type"
//              property_number(int): # type's property
//                                  eg: circle: only radius so property_number = 1
//              ...: for circle: radius, for rectangle: length, width
// [Return]: None
void printer(std::string type, int area, int property_number, ...)
{
  int val;
  va_list vl;
  va_start(vl, property_number);

  std::cout << "Type: " << type << std::endl;
  std::cout << "Data: ";
  // iterate all properties of the current object
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
  int area = ( radius >= 0 ) ? PI*radius*radius : 0;
  printer("Circle", area, 1, radius);
  return area;
}

int AreaVisitor::RectangleArea(Rectangle* rectangle_object) const
{
  int length = rectangle_object->GetLength();
  int width = rectangle_object->GetWidth();
  // return 0 if input is illegal
  int area = ( length >=0 && width >=0 ) ? length * width : 0;
  printer("Rectangle", area, 2, length, width);
  return area;
}

int AreaVisitor::TriangleArea(Triangle* triangle_object) const
{
  int base = triangle_object->GetBase();
  int height = triangle_object->GetHeight();
  // return 0 if input is illegal
  int area = ( base >=0 && height >=0 ) ? base * height / 2 : 0;
  printer("Triangle", area, 2, base, height);
  return area;
}