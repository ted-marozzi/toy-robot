#include "ToyRobot/ToyRobot.hpp"
#include "Parser/Parser.hpp"

int main()
{

    auto robot = Robot::ToyRobot{std::make_unique<Robot::Parser>()};
    robot.ParseInput();

    return 0;
}
