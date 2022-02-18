#pragma once
#include <memory>
#include <unordered_map>
#include "../ToyRobot.hpp"

namespace Robot
{
    class ToyRobot;
    class Place;
    class Command
    {
    public:
        virtual void Execute(ToyRobot &toyRobot) = 0;
    };
}