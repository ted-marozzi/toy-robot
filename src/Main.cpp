#include "ToyRobot/ToyRobot.hpp"
#include "ToyRobot/Parser/Parser.hpp"
#include "ToyRobot/Table/CircularTable.hpp"
#include "ToyRobot/Table/RectangularTable.hpp"

int main()
{

    auto robot = Robot::ToyRobot{
        std::make_shared<Robot::Parser>(),
        std::make_shared<Robot::CommandFactory>(
            std::make_shared<Robot::CircularTable>(6))
    };

    robot.TurnOn();

    return 0;
}
