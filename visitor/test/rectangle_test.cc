// third-party dependency
#include "gtest/gtest.h"
#include "gmock/gmock.h"
// user-defined dependency
#include "rectangle.h"
#include "area_visitor.h"

namespace {
// test fixture
class RectangleTest : public testing::Test
{
protected:
  // test target
  Rectangle test_obj = Rectangle(3, 4);
};

// test GetLength
TEST_F(RectangleTest, GetLength)
{
  EXPECT_EQ(3, test_obj.GetLength());
}

// test GetWidth
TEST_F(RectangleTest, GetWidth)
{
  EXPECT_EQ(4, test_obj.GetWidth());
}

// test SetLength
TEST_F(RectangleTest, SetLength)
{
  test_obj.SetLength(10);
  EXPECT_EQ(10, test_obj.GetLength());
}

// test SetWidth
TEST_F(RectangleTest, SetWidth)
{
  test_obj.SetWidth(64);
  EXPECT_EQ(64, test_obj.GetWidth());
}

// test move copy c'tor
TEST_F(RectangleTest, MoveCopyCtor)
{
  Rectangle tmp(Rectangle(99, 98));
  EXPECT_EQ(99, tmp.GetLength());
  EXPECT_EQ(98, tmp.GetWidth());
}

// test move assignment operator
TEST_F(RectangleTest, MoveAssignOperator)
{
  Rectangle tmp(12, 13);
  tmp = std::move(test_obj);
  EXPECT_EQ(3, tmp.GetLength());
  EXPECT_EQ(4, tmp.GetWidth());
  EXPECT_EQ(0, test_obj.GetLength());
  EXPECT_EQ(0, test_obj.GetWidth());
}

// test area
TEST_F(RectangleTest, AreaVisitor)
{
  AreaVisitor* tmp = new AreaVisitor();
  EXPECT_EQ(3*4, test_obj.AreaVisitor(tmp));
}

} // namespace