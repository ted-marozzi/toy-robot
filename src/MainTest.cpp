#include <gtest/gtest.h>
#include "ToyRobot/Table/CircularTable.hpp"


TEST(CircularTable, TestCircularTableConstructor)
{
    auto table = Robot::CircularTable(3);

    EXPECT_EQ(table.IsValidPosition(2, 2), true);
    EXPECT_EQ(table.IsValidPosition(0, 0), false);
}

int main()
{
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}
