#pragma once

#include <string>
#include "../ToyRobot.hpp"
#include "ICommand.hpp"

namespace Robot
{
    class Move : public ICommand
    {
    public:
        virtual void Execute(ToyRobot &toyRobot) const override;
    };
}
