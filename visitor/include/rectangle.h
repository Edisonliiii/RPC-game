#ifndef VISITOR_RECTANGLE_H_
#define VISITOR_RECTANGLE_H_

#include "shape.h"

class Rectangle : public Shape
{
private:
  int _length;
  int _width;
public:
  Rectangle(int length, int width) : _length(length), _width(width) {}
  Rectangle(Rectangle&& rectangle_object);
  Rectangle& operator=(Rectangle&& rectangle_object);
  ~Rectangle(){}

  void SetLength(int length);
  void SetWidth(int width);
  int GetLength() const;
  int GetWidth() const;
  int AreaVisitor(Visitor* visitor) override;
};

#endif // VISITOR_RECTANGLE_H_