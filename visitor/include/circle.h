#ifndef VISITOR_CIRCLE_H_
#define VISITOR_CIRCLE_H_
// user-defined dependency
#include "shape.h"

// Circle class
//  define circle object
// Example:
//    include "circle.h" and instantiate it
class Circle : public Shape
{
private:
  // reserve the radius of circle
  int _radius;
public:
  // c'tor
  Circle(int radius) : _radius(radius) {}
  // move copy constructor
  //  will be called when create temporary circle on-the-fly
  //  move semantic will hugly boost the efficiency when the object goes huge
  // eg: Circle tmp(Circle(44));
  Circle(Circle&& circle_object) noexcept;
  // move assignment operator
  //  same purpose as move copy constructor
  // eg: Circle tmp(28);
  //     tmp = std::move(original_obj);
  Circle& operator=(Circle&& circle_object) noexcept;
  // d'tor
  // there is no need to explicitly implement it for now
  ~Circle(){}
  
  // Set new radius
  // [Parameter]: radius value you want to set
  // [Return]: None
  void SetRadius(int radius);
  // Get current radius
  // [Parameter]: None
  // [Return]: current radius
  int GetRadius() const;
  // Calculate the area
  // [Parameter]: pointer to concrete circle visitor object
  // [Return]: area value
  int AreaVisitor(Visitor* visitor) override;
};

#endif // VISITOR_CIRCLE_H_