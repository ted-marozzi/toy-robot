#pragma once

#include <string>
#include "../ToyRobot.hpp"
#include "ICommand.hpp"

namespace Robot
{
    class Report : public ICommand
    {
    public:
        void Execute(ToyRobot &toyRobot) const override;

    };
}
