#include <gtest/gtest.h>
#include <vector>
#include <memory>

#include "ToyRobot/Parser/IParser.hpp"
#include "ToyRobot/Parser/Parser.hpp"
#include "ToyRobot/Commands/ICommand.hpp"
#include "ToyRobot/Commands/CommandFactory.hpp"
#include "ToyRobot/ToyRobot.hpp"
#include "ToyRobot/Table/CircularTable.hpp"
#include "ToyRobot/Table/RectangularTable.hpp"
#include "ToyRobot/Table/SquircleTable.hpp"
#include <typeinfo>

TEST(RectangularTable, IsValidPosition)
{
    auto tableOne = Robot::RectangularTable{0, 0};

    EXPECT_EQ(tableOne.IsValidPosition(0, -1), false);
    EXPECT_EQ(tableOne.IsValidPosition(1, -1), false);
    EXPECT_EQ(tableOne.IsValidPosition(2, -1), false);

    EXPECT_EQ(tableOne.IsValidPosition(0, 0), false);
    EXPECT_EQ(tableOne.IsValidPosition(1, 0), false);
    EXPECT_EQ(tableOne.IsValidPosition(2, 0), false);

    EXPECT_EQ(tableOne.IsValidPosition(0, 1), false);
    EXPECT_EQ(tableOne.IsValidPosition(1, 1), false);
    EXPECT_EQ(tableOne.IsValidPosition(2, 1), false);

    auto tableTwo = Robot::RectangularTable{3, 5};

    for (int j = 0; j < 5; j++)
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

TEST(SquircleTable, IsValidPosition)
{
    auto tableOne = Robot::SquircleTable{7, 6};

    const std::vector<std::vector<bool>> expectedResult = {
        {false, true, true, true, true, true, false},
        {true, true, true, true, true, true, true},
        {true, true, true, true, true, true, true},
        {true, true, true, true, true, true, true},
        {true, true, true, true, true, true, true},
        {false, true, true, true, true, true, false},
    };

    for (int j = 0; j < expectedResult.size(); j++)
    {
        for (int i = 0; i < expectedResult[j].size(); i++)
        {
            EXPECT_EQ(tableOne.IsValidPosition(i, j), expectedResult[j][i]);
        }
    }
}

/*
 *  Parser Tests
 */
// Some includes errors require this for parser test??
TEST(Parser, ParserTestsFailWithoutThis)
{
    auto robot = Robot::ToyRobot{
        std::make_shared<Robot::Parser>(),
        std::make_shared<Robot::CommandFactory>(
            std::make_shared<Robot::RectangularTable>(3, 5))};
    robot.Help();
}

TEST(Parser, ParseCommandLine)
{
    auto parser = std::make_shared<Robot::Parser>();
    auto commandFactory = std::make_shared<Robot::CommandFactory>(
        std::make_shared<Robot::RectangularTable>(3, 5));

    // Invalid
    auto invalid = parser->ParseCommandLine("Hello world", commandFactory);
    EXPECT_EQ(invalid, nullptr);

    auto noCommand = parser->ParseCommandLine("", commandFactory);
    EXPECT_EQ(noCommand, nullptr);

    auto tooManySpaceSepArgs = parser->ParseCommandLine("Too Many Args", commandFactory);
    EXPECT_EQ(tooManySpaceSepArgs, nullptr);
    // Capitalization should be ignored and hence be valid
    auto capitalization = parser->ParseCommandLine("mOve", commandFactory);
    // Runtime class type check
    // Checks that the function returns a Move command
    EXPECT_EQ(typeid(capitalization).name(), typeid(commandFactory->CreateMoveCommand()).name());

    auto capitalizationTwo = parser->ParseCommandLine("MOVE", commandFactory);
    EXPECT_EQ(typeid(capitalization).name(), typeid(commandFactory->CreateMoveCommand()).name());

    auto notEnoughArgs = parser->ParseCommandLine("place", commandFactory);
    EXPECT_EQ(notEnoughArgs, nullptr);

    auto tooManyArgs = parser->ParseCommandLine("place 1,3,nor,2", commandFactory);
    EXPECT_EQ(tooManyArgs, nullptr);

    auto wrongDataType = parser->ParseCommandLine("place hello,1,world", commandFactory);
    EXPECT_EQ(wrongDataType, nullptr);

    auto wrongDirection = parser->ParseCommandLine("place 1,2,notvalid", commandFactory);
    EXPECT_EQ(wrongDirection, nullptr);

    auto offTheTable = parser->ParseCommandLine("place -1,2,north", commandFactory);
    EXPECT_EQ(offTheTable, nullptr);

    auto valid = parser->ParseCommandLine("place 1,2,north", commandFactory);
    EXPECT_EQ(typeid(valid).name(), typeid(commandFactory->CreatePlaceCommand(1, 2, "NORTH")).name());

    auto right = parser->ParseCommandLine("RIGHT", commandFactory);
    EXPECT_EQ(typeid(right).name(), typeid(commandFactory->CreateRightCommand()).name());

    auto left = parser->ParseCommandLine("LEFT", commandFactory);
    EXPECT_EQ(typeid(left).name(), typeid(commandFactory->CreateLeftCommand()).name());

    auto report = parser->ParseCommandLine("REPORT", commandFactory);
    EXPECT_EQ(typeid(report).name(), typeid(commandFactory->CreateReportCommand()).name());

    auto table = parser->ParseCommandLine("TABLE", commandFactory);
    EXPECT_EQ(typeid(table).name(), typeid(commandFactory->CreateTableCommand()).name());
}
