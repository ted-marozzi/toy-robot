#include <iostream>
#include "Right.hpp"

namespace Robot
{
    void Right::Execute(ToyRobot &toyRobot) const
    {
        if(toyRobot.m_facing == "")   {
            std::cout << "Unable to turn as I am not placed yet\n\n";
            return;
        }
        else if(toyRobot.m_facing == "NORTH")
        {
            toyRobot.m_facing = "EAST";
        }
        else if (toyRobot.m_facing == "EAST")
        {
            toyRobot.m_facing = "SOUTH";
        }
        else if (toyRobot.m_facing == "SOUTH")
        {
            toyRobot.m_facing = "WEST";
        }
        else if (toyRobot.m_facing == "WEST")
        {
            toyRobot.m_facing = "NORTH";
        }
        else
        {
            std::cout << "Error: I am facing an invalid direction\n\n";
        }
    }


}
