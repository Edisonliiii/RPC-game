#include "circle.h"
#include "area_visitor.h"

Circle::Circle(Circle&& circle_object) noexcept
{
  this->_radius = circle_object.GetRadius();
  circle_object.SetRadius(-1);
}

Circle& Circle::operator=(Circle&& circle_object) noexcept
{
  if(this == &circle_object) return *this;
  this->_radius = circle_object.GetRadius();
  circle_object.SetRadius(-1);
  return *this;
}

void Circle::SetRadius(int radius)
{
  _radius = radius;
}

int Circle::GetRadius() const
{
  return _radius;
}

int Circle::AreaVisitor(Visitor* visitor)
{
  return visitor -> CircleArea(this);
}