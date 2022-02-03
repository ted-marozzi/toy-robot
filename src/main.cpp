#include <iostream>

#include "ToyRobot/ToyRobot.hpp"

int main()
{
    std::cout << "Hello, world!\n";
    auto robot = ToyRobot::ToyRobot{};

    robot.Talk();
}
