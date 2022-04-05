#pragma once
#include <memory>
#include <unordered_map>
#include <vector>
#include <string>
#include <functional>

#include "../ToyRobot.hpp"

namespace Robot
{
    class ToyRobot;
    class ICommand
    {
    public:
        virtual void Execute(ToyRobot &toyRobot) const = 0;
    };
}