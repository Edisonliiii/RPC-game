#ifndef VISITOR_CIRCLE_H_
#define VISITOR_CIRCLE_H_

#include "shape.h"

class Circle : public Shape
{
private:
  int _radius;
public:
  Circle(int radius) : _radius(radius) {}
  Circle(Circle&& circle_object) noexcept;
  Circle& operator=(Circle&& circle_object) noexcept;
  ~Circle(){}

  void SetRadius(int radius);
  int GetRadius() const;
  int AreaVisitor(Visitor* visitor) override;
};

#endif // VISITOR_CIRCLE_H_