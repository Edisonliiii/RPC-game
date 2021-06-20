// third-party dependency
#include "gtest/gtest.h"
#include "gmock/gmock.h"
// user-defined dependency
#include "triangle.h"
#include "area_visitor.h"

namespace {
// test fixture
class TriangleTest : public testing::Test
{
protected:
  // test target
  Triangle test_obj = Triangle(3, 4);
};

// test GetBase
TEST_F(TriangleTest, GetBase)
{
  EXPECT_EQ(3, test_obj.GetBase());
}

// test GetHeight
TEST_F(TriangleTest, GetHeight)
{
  EXPECT_EQ(4, test_obj.GetHeight());
}

// test SetBase
TEST_F(TriangleTest, SetBase)
{
  test_obj.SetBase(10);
  EXPECT_EQ(10, test_obj.GetBase());
}

// test SetHeight
TEST_F(TriangleTest, SetHeight)
{
  test_obj.SetHeight(64);
  EXPECT_EQ(64, test_obj.GetHeight());
}

// test move copy c'tor
TEST_F(TriangleTest, MoveCopyCtor)
{
  Triangle tmp(Triangle(99, 98));
  EXPECT_EQ(99, tmp.GetBase());
  EXPECT_EQ(98, tmp.GetHeight());
}

// test move assignment operator
TEST_F(TriangleTest, MoveAssignOperator)
{
  Triangle tmp(12, 13);
  tmp = std::move(test_obj);
  EXPECT_EQ(3, tmp.GetBase());
  EXPECT_EQ(4, tmp.GetHeight());
  EXPECT_EQ(0, test_obj.GetBase());
  EXPECT_EQ(0, test_obj.GetHeight());
}

// test area
TEST_F(TriangleTest, AreaVisitor)
{
  AreaVisitor* tmp = new AreaVisitor();
  EXPECT_EQ(3*4/2, test_obj.AreaVisitor(tmp));
}

} // namespace