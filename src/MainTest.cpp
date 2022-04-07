#include <gtest/gtest.h>
#include "ToyRobot/Table/CircularTable.hpp"


TEST(CircularTable, TestCircularTableConstructor)
{
    auto table = Robot::CircularTable(3);

    EXPECT_EQ(2+2, 4);
}

int main()
{
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}
