#ifndef VISITOR_TRIANGLE_H_
#define VISITOR_TRIANGLE_H_

#include "shape.h"

class Triangle : public Shape
{
private:
  int _base;
  int _height;
public:
  Triangle(int base, int height) : _base(base), _height(height) {}
  Triangle(Triangle&& triangle_object);
  Triangle& operator=(Triangle&& triangle_object);
  ~Triangle(){}

  void SetBase(int base);
  void SetHeight(int height);
  int GetBase() const;
  int GetHeight() const;
  int AreaVisitor(Visitor* visitor) override;
};

#endif // VISITOR_TRIANGLE_H_