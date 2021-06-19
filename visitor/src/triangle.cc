#include "triangle.h"
#include "area_visitor.h"

Triangle::Triangle(Triangle&& triangle_object)
{
  this->_base = triangle_object.GetBase();
  this->_height = triangle_object.GetHeight();
  triangle_object.SetBase(0);
  triangle_object.SetHeight(0);
}

Triangle& Triangle::operator=(Triangle&& triangle_object)
{
  if (this == &triangle_object) return *this;
  this->_base = triangle_object.GetBase();
  this->_height = triangle_object.GetHeight();
  triangle_object.SetBase(0);
  triangle_object.SetHeight(0);
  return *this;
}

void Triangle::SetBase(int base)
{
  _base = base;
}

void Triangle::SetHeight(int height)
{
  _height = height;
}

int Triangle::GetBase() const
{
  return _base;
}

int Triangle::GetHeight() const
{
  return _height;
}

int Triangle::AreaVisitor(Visitor* visitor)
{
  return visitor -> TriangleArea(this);
}