#pragma once

#include <string>
#include "../ToyRobot.hpp"
#include "Command.hpp"

namespace Robot
{
    class Place : public Command
    {
    public:
        virtual void Execute(ToyRobot &toyRobot) override;
    };
}
