#ifndef VISITOR_TRIANGLE_H_
#define VISITOR_TRIANGLE_H_
// user-defined dependency
#include "shape.h"

// Triangle class
//  define Triangle object
// Example:
//    include "triangle.h" and instantiate it
class Triangle : public Shape
{
private:
  // reserve base and height
  int _base;
  int _height;
public:
  // c'tor
  Triangle(int base, int height) : _base(base), _height(height) {}
  // move copy constructor
  //  will be called when create temporary Triangle on-the-fly
  //  move semantic will hugly boost the efficiency when the object goes huge
  // eg: Triangle tmp(Triangle(1,2));
  Triangle(Triangle&& triangle_object);
  // move assignment constructor
  //  same purpose as move copy constructor
  // eg: Triangle tmp(2,1);
  //     tmp = std::move(original_obj);
  Triangle& operator=(Triangle&& triangle_object);
  // d'tor
  ~Triangle(){}
  
  // Set new Base
  // [Parameter]: base value you want to set
  // [Return]: None
  void SetBase(int base);
  // Set new Height
  // [Parameter]: Height value you want to set
  // [Return]: None
  void SetHeight(int height);
  // Get new Base
  // [Parameter]: None
  // [Return]: current Base
  int GetBase() const;
  // Get new Height
  // [Parameter]: None
  // [Return]: current Height
  int GetHeight() const;
  // Calculate the area
  // [Parameter]: pointer to concrete triangle visitor object
  // [Return]: area value
  int AreaVisitor(Visitor* visitor) override;
};

#endif // VISITOR_TRIANGLE_H_