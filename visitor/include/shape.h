#ifndef VISITOR_SHAPE_H_
#define VISITOR_SHAPE_H_
// user-defined dependency
#include "visitor.h"

// Shape interface
// Example:
//    include "shape.h" and implement new shape you want
// But you have to implement AreaVisitor if you want to use it
class Shape
{
public:
  virtual int AreaVisitor(Visitor* visitor) = 0;
};

#endif // VISITOR_SHAPE_H_