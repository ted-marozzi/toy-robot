#include "ToyRobot/ToyRobot.hpp"

int main()
{
    auto robot = Robot::ToyRobot{};
    robot.ParseInput();

    return 0;
}
