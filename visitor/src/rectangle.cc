#include "rectangle.h"
#include "area_visitor.h"

Rectangle::Rectangle(Rectangle&& rectangle_object)
{
  this->_length = rectangle_object.GetLength();
  this->_width = rectangle_object.GetWidth();
  rectangle_object.SetLength(0);
  rectangle_object.SetWidth(0);
}

Rectangle& Rectangle::operator=(Rectangle&& rectangle_object)
{
  if (this == &rectangle_object) return *this;
  this->_length = rectangle_object.GetLength();
  this->_width = rectangle_object.GetWidth();
  rectangle_object.SetLength(0);
  rectangle_object.SetWidth(0);
  return *this;
}

void Rectangle::SetLength(int length)
{
  _length = length;
}

void Rectangle::SetWidth(int width)
{
  _width = width;
}

int Rectangle::GetLength() const
{
  return _length;
}

int Rectangle::GetWidth() const
{
  return _width;
}

int Rectangle::AreaVisitor(Visitor* visitor)
{
  return visitor -> RectangleArea(this);
}