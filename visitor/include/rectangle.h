#ifndef VISITOR_RECTANGLE_H_
#define VISITOR_RECTANGLE_H_
// user-defined dependency
#include "shape.h"

// Rectangle class
//  define Rectangle object
// Example:
//    include "rectangle.h" and instantiate it
class Rectangle : public Shape
{
private:
  // reserve length and width
  int _length;
  int _width;
public:
  // c'tor
  Rectangle(int length, int width) : _length(length), _width(width) {}
  // move copy constructor
  //  will be called when create temporary rectangle on-the-fly
  //  move semantic will hugly boost the efficiency when the object goes huge
  // eg: Rectangle tmp(Rectangle(1,2));
  Rectangle(Rectangle&& rectangle_object);
  // move assignment constructor
  //  same purpose as move copy constructor
  // eg: Rectangle tmp(2,8);
  //     tmp = std::move(original_obj);
  Rectangle& operator=(Rectangle&& rectangle_object);
  // d'tor
  // there is no need to explicitly implement it for now
  ~Rectangle(){}
  
  // Set new Length
  // [Parameter]: length value you want to set
  // [Return]: None
  void SetLength(int length);
  // Set new Wdith
  // [Parameter]: width value you want to set
  // [Return]: None
  void SetWidth(int width);
  // Get new Length
  // [Parameter]: None
  // [Return]: current length
  int GetLength() const;
  // Get new Width
  // [Parameter]: None
  // [Return]: current Width
  int GetWidth() const;
  // Calculate the area
  // [Parameter]: pointer to concrete rectangle visitor object
  // [Return]: area value
  int AreaVisitor(Visitor* visitor) override;
};

#endif // VISITOR_RECTANGLE_H_