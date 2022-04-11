#include "ToyRobot/ToyRobot.hpp"
#include "ToyRobot/Parser/Parser.hpp"
#include "ToyRobot/Table/CircularTable.hpp"
#include "ToyRobot/Table/RectangularTable.hpp"
#include "ToyRobot/Table/SquircleTable.hpp"

int main()
{

    auto robot = Robot::ToyRobot{
        std::make_shared<Robot::Parser>(),
        std::make_shared<Robot::CommandFactory>(
            std::make_shared<Robot::SquircleTable>(4,8))};

    robot.TurnOn();

    return 0;
}
