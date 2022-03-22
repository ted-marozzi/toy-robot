#pragma once

#include <string>
#include "../ToyRobot.hpp"
#include "ICommand.hpp"

namespace Robot
{
    class Right : public ICommand
    {
    public:
        void Execute(ToyRobot &toyRobot) const override;
    };
}
