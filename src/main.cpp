#include "ToyRobot/ToyRobot.hpp"
#include "Parser/Parser.hpp"
#include "Table/CircularTable.hpp"
#include "Table/RectangularTable.hpp"

int main()
{

    auto robot = Robot::ToyRobot{
        std::make_unique<Robot::Parser>(),
        std::make_unique<Robot::CommandFactory>(
            std::make_unique<Robot::RectangularTable>(3,6))};

    robot.TurnOn();

    return 0;
}
