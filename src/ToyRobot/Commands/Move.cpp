#include <iostream>
#include "Move.hpp"
#include "../Parser/IParser.hpp"

namespace Robot
{

    void Move::Execute(ToyRobot &toyRobot) const
    {
        int x = toyRobot.m_x, y = toyRobot.m_y;
        if (toyRobot.m_facing == "NORTH")
        {
            y = toyRobot.m_y + 1;
        }
        else if (toyRobot.m_facing == "EAST")
        {
            x = toyRobot.m_x + 1;

        }
        else if (toyRobot.m_facing == "SOUTH")
        {
            y = toyRobot.m_y - 1;
        }
        else if (toyRobot.m_facing == "WEST")
        {
            x = toyRobot.m_x - 1;
        }
        else if (toyRobot.m_facing == "")
        {
            std::cout << "Unable to Move because I haven't been placed yet\n\n";
            return;
        }
        else
        {
            std::cout << "Unable to Move due to invalid facing direction\n\n";
            return;
        }

        if(!m_table->IsValidPosition(x, y))
        {
            std::cout << "Unable to move because I will fall off!\n\n";
            return;
        }
        toyRobot.m_y = y;
        toyRobot.m_x = x;
    }

}