#pragma once

#include <string>
#include "../ToyRobot.hpp"
#include "ICommand.hpp"

namespace Robot
{
    class Place : public ICommand
    {
    public:
        Place(int x, int y, std::string facing) : m_x{x}, m_y{y}, m_facing{facing} {};
        ~Place() {};
        void Execute(ToyRobot &toyRobot) const override;

    private:
        int m_x = 0;
        int m_y = 0;
        std::string m_facing;

    };
}
