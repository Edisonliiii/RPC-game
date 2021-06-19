#include "area_visitor.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include <iostream>

int main(int argc, char const *argv[])
{
  Circle* c_ptr = new Circle(10);
  Rectangle* r_ptr = new Rectangle(10, 20);
  Triangle* t_ptr = new Triangle(3, 4);
  AreaVisitor* v = new AreaVisitor();
  
  std::cout<<c_ptr->AreaVisitor(v)<<std::endl;
  std::cout<<r_ptr->AreaVisitor(v)<<std::endl;
  std::cout<<t_ptr->AreaVisitor(v)<<std::endl;
  return 0;
}