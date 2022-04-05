#include "ToyRobot/ToyRobot.hpp"
#include "Parser/Parser.hpp"
#include "Table/CircularTable.hpp"
#include "Table/RectangularTable.hpp"

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
