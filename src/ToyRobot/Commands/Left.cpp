#include <iostream>
#include "Left.hpp"

namespace Robot
{

    void Left::Execute(ToyRobot &toyRobot) const
    {
        if (toyRobot.m_facing == "")
        {
            std::cout << "Unable to turn as I am not placed yet\n\n";
            return;
        }
        else if (toyRobot.m_facing == "NORTH")
        {
            toyRobot.m_facing = "WEST";
        }
        else if (toyRobot.m_facing == "EAST")
        {
            toyRobot.m_facing = "NORTH";
        }
        else if (toyRobot.m_facing == "SOUTH")
        {
            toyRobot.m_facing = "EAST";
        }
        else if (toyRobot.m_facing == "WEST")
        {
            toyRobot.m_facing = "SOUTH";
        }
        else
        {
            std::cout << "Error: I am facing an invalid direction\n\n";
        }
    }


}
