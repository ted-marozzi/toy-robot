#include <iostream>
#include "Move.hpp"
#include "../Parser/IParser.hpp"

namespace Robot
{

    void Move::Execute(ToyRobot &toyRobot) const
    {
        const auto willFallOff = []()
        {
            std::cout << "I can't move because I will fall off!\n\n";
        };

        if (toyRobot.m_facing == "NORTH")
        {
            if (toyRobot.m_y < GRID_HEIGHT - 1)
                toyRobot.m_y++;
            else
                willFallOff();
        }
        else if (toyRobot.m_facing == "EAST")
        {
            if (toyRobot.m_x < GRID_WIDTH - 1)
                toyRobot.m_x++;
            else
                willFallOff();
        }
        else if (toyRobot.m_facing == "SOUTH")
        {
            if (toyRobot.m_y >= 1)
                toyRobot.m_y--;
            else
                willFallOff();
        }
        else if (toyRobot.m_facing == "WEST")
        {
            if (toyRobot.m_x >= 1)
                toyRobot.m_x--;
            else
                willFallOff();
        }
        else if (toyRobot.m_facing == "")
        {
            std::cout << "Unable to Move because I haven't been placed yet\n\n";
        }
        else
        {
            std::cout << "Unable to Move due to invalid facing direction\n\n";
        }
    }

}