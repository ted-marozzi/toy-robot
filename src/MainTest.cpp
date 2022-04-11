#include <gtest/gtest.h>
#include "ToyRobot/Table/CircularTable.hpp"
#include "ToyRobot/Table/RectangularTable.hpp"

// Tests the constructor and IsValidPosition
TEST(CircularTable, IsValidPosition)
{
    auto tableOne = Robot::CircularTable{0};
    EXPECT_EQ(tableOne.IsValidPosition(0, 0), false);
    EXPECT_EQ(tableOne.IsValidPosition(-1, 0), false);
    EXPECT_EQ(tableOne.IsValidPosition(1, 0), false);
    EXPECT_EQ(tableOne.IsValidPosition(0, 1), false);
    EXPECT_EQ(tableOne.IsValidPosition(0, 2), false);
    EXPECT_EQ(tableOne.IsValidPosition(0, 3), false);

    auto tableTwo = Robot::CircularTable{1};
    EXPECT_EQ(tableTwo.IsValidPosition(0, 0), true);
    EXPECT_EQ(tableTwo.IsValidPosition(-1, 0), false);
    EXPECT_EQ(tableTwo.IsValidPosition(1, 0), false);
    EXPECT_EQ(tableTwo.IsValidPosition(0, 1), false);
    EXPECT_EQ(tableTwo.IsValidPosition(0, 2), false);
    EXPECT_EQ(tableTwo.IsValidPosition(0, 3), false);

    auto tableThree = Robot::CircularTable{4};
    EXPECT_EQ(tableThree.IsValidPosition(0, 0), false);
    EXPECT_EQ(tableThree.IsValidPosition(-1, 0), false);
    EXPECT_EQ(tableThree.IsValidPosition(1, 0), true);
    EXPECT_EQ(tableThree.IsValidPosition(2, 0), true);
    EXPECT_EQ(tableThree.IsValidPosition(3, 0), false);
    EXPECT_EQ(tableThree.IsValidPosition(0, 1), true);
    EXPECT_EQ(tableThree.IsValidPosition(0, 2), true);
    EXPECT_EQ(tableThree.IsValidPosition(0, 3), false);
    EXPECT_EQ(tableThree.IsValidPosition(2, 3), true);
    EXPECT_EQ(tableThree.IsValidPosition(2, 2), true);
    EXPECT_EQ(tableThree.IsValidPosition(3, 3), false);

    auto tableFour = Robot::CircularTable{5};

    EXPECT_EQ(tableFour.IsValidPosition(-1, -1), false);
    EXPECT_EQ(tableFour.IsValidPosition(0, -1), false);
    EXPECT_EQ(tableFour.IsValidPosition(1, -1), false);
    EXPECT_EQ(tableFour.IsValidPosition(2, -1), false);
    EXPECT_EQ(tableFour.IsValidPosition(3, -1), false);
    EXPECT_EQ(tableFour.IsValidPosition(4, -1), false);
    EXPECT_EQ(tableFour.IsValidPosition(5, -1), false);
    EXPECT_EQ(tableFour.IsValidPosition(6, -1), false);

    EXPECT_EQ(tableFour.IsValidPosition(-1, 0), false);
    EXPECT_EQ(tableFour.IsValidPosition(0, 0), false);
    EXPECT_EQ(tableFour.IsValidPosition(1, 0), true);
    EXPECT_EQ(tableFour.IsValidPosition(2, 0), true);
    EXPECT_EQ(tableFour.IsValidPosition(3, 0), true);
    EXPECT_EQ(tableFour.IsValidPosition(4, 0), false);
    EXPECT_EQ(tableFour.IsValidPosition(5, 0), false);
    EXPECT_EQ(tableFour.IsValidPosition(6, 0), false);

    EXPECT_EQ(tableFour.IsValidPosition(-1, 1), false);
    EXPECT_EQ(tableFour.IsValidPosition(0, 1), true);
    EXPECT_EQ(tableFour.IsValidPosition(1, 1), true);
    EXPECT_EQ(tableFour.IsValidPosition(2, 1), true);
    EXPECT_EQ(tableFour.IsValidPosition(3, 1), true);
    EXPECT_EQ(tableFour.IsValidPosition(4, 1), true);
    EXPECT_EQ(tableFour.IsValidPosition(5, 1), false);
    EXPECT_EQ(tableFour.IsValidPosition(6, 1), false);

    EXPECT_EQ(tableFour.IsValidPosition(-1, 2), false);
    EXPECT_EQ(tableFour.IsValidPosition(0, 2), true);
    EXPECT_EQ(tableFour.IsValidPosition(1, 2), true);
    EXPECT_EQ(tableFour.IsValidPosition(2, 2), true);
    EXPECT_EQ(tableFour.IsValidPosition(3, 2), true);
    EXPECT_EQ(tableFour.IsValidPosition(4, 2), true);
    EXPECT_EQ(tableFour.IsValidPosition(5, 2), false);
    EXPECT_EQ(tableFour.IsValidPosition(6, 2), false);

    EXPECT_EQ(tableFour.IsValidPosition(-1, 3), false);
    EXPECT_EQ(tableFour.IsValidPosition(0, 3), true);
    EXPECT_EQ(tableFour.IsValidPosition(1, 3), true);
    EXPECT_EQ(tableFour.IsValidPosition(2, 3), true);
    EXPECT_EQ(tableFour.IsValidPosition(3, 3), true);
    EXPECT_EQ(tableFour.IsValidPosition(4, 3), true);
    EXPECT_EQ(tableFour.IsValidPosition(5, 3), false);
    EXPECT_EQ(tableFour.IsValidPosition(6, 3), false);

    EXPECT_EQ(tableFour.IsValidPosition(-1, 4), false);
    EXPECT_EQ(tableFour.IsValidPosition(0, 4), false);
    EXPECT_EQ(tableFour.IsValidPosition(1, 4), true);
    EXPECT_EQ(tableFour.IsValidPosition(2, 4), true);
    EXPECT_EQ(tableFour.IsValidPosition(3, 4), true);
    EXPECT_EQ(tableFour.IsValidPosition(4, 4), false);
    EXPECT_EQ(tableFour.IsValidPosition(5, 4), false);
    EXPECT_EQ(tableFour.IsValidPosition(6, 4), false);

    EXPECT_EQ(tableFour.IsValidPosition(-1, 5), false);
    EXPECT_EQ(tableFour.IsValidPosition(0, 5), false);
    EXPECT_EQ(tableFour.IsValidPosition(1, 5), false);
    EXPECT_EQ(tableFour.IsValidPosition(2, 5), false);
    EXPECT_EQ(tableFour.IsValidPosition(3, 5), false);
    EXPECT_EQ(tableFour.IsValidPosition(4, 5), false);
    EXPECT_EQ(tableFour.IsValidPosition(5, 5), false);
    EXPECT_EQ(tableFour.IsValidPosition(6, 5), false);

    EXPECT_EQ(tableFour.IsValidPosition(-1, 6), false);
    EXPECT_EQ(tableFour.IsValidPosition(0, 6), false);
    EXPECT_EQ(tableFour.IsValidPosition(1, 6), false);
    EXPECT_EQ(tableFour.IsValidPosition(2, 6), false);
    EXPECT_EQ(tableFour.IsValidPosition(3, 6), false);
    EXPECT_EQ(tableFour.IsValidPosition(4, 6), false);
    EXPECT_EQ(tableFour.IsValidPosition(5, 6), false);
    EXPECT_EQ(tableFour.IsValidPosition(6, 6), false);
}

TEST(RectangularTable, IsValidPosition)
{
    auto tableOne = Robot::RectangularTable{0, 0};

    EXPECT_EQ(tableOne.IsValidPosition(0, -1), false);
    EXPECT_EQ(tableOne.IsValidPosition(0, -1), false);
    EXPECT_EQ(tableOne.IsValidPosition(0, -1), false);

    EXPECT_EQ(tableOne.IsValidPosition(0, 0), false);
    EXPECT_EQ(tableOne.IsValidPosition(0, 0), false);
    EXPECT_EQ(tableOne.IsValidPosition(0, 0), false);

    EXPECT_EQ(tableOne.IsValidPosition(0, 1), false);
    EXPECT_EQ(tableOne.IsValidPosition(0, 1), false);
    EXPECT_EQ(tableOne.IsValidPosition(0, 1), false);

    auto tableTwo = Robot::RectangularTable{3, 5};

    for(int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            EXPECT_EQ(tableTwo.IsValidPosition(i, j), true);
        }
    }
    EXPECT_EQ(tableTwo.IsValidPosition(-1, 0), false);
    EXPECT_EQ(tableTwo.IsValidPosition(3, 0), false);
    EXPECT_EQ(tableTwo.IsValidPosition(0, 5), false);
    EXPECT_EQ(tableTwo.IsValidPosition(3, 5), false);
}