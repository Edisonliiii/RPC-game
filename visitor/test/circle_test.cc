#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "circle.h"
#include "area_visitor.h"

namespace {

class CircleTest : public testing::Test
{
protected:
  // test target
  Circle test_obj = Circle(10);
};

// test GetRadius
TEST_F(CircleTest, GetRadius)
{
  EXPECT_EQ(10, test_obj.GetRadius());
}

// test SetRadius
TEST_F(CircleTest, SetRadius)
{
  test_obj.SetRadius(100);
  EXPECT_EQ(100, test_obj.GetRadius());
}

// test move copy c'tor
TEST_F(CircleTest, MoveCopyCtor)
{
  Circle tmp(Circle(44));
  EXPECT_EQ(44, tmp.GetRadius());
}

// test move assignment operator
TEST_F(CircleTest, MoveAssignOperator)
{
  Circle tmp(28);
  tmp = std::move(test_obj);
  EXPECT_EQ(10, tmp.GetRadius());
  EXPECT_EQ(-1, test_obj.GetRadius());
}

TEST_F(CircleTest, AreaVisitor)
{
  AreaVisitor* tmp = new AreaVisitor();
  int radius = test_obj.GetRadius();
  EXPECT_EQ(3.14*radius*radius, test_obj.AreaVisitor(tmp));
}
} // namespace
