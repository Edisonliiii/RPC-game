#ifndef VISITOR_SHAPE_H_
#define VISITOR_SHAPE_H_

#include "visitor.h"

class Shape
{
public:
  virtual int AreaVisitor(Visitor* visitor) = 0;
};

#endif // VISITOR_SHAPE_H_