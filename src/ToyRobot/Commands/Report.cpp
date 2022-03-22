#include <iostream>
#include "Report.hpp"

namespace Robot
{

    void Report::Execute(ToyRobot &toyRobot) const
    {
        if (toyRobot.m_facing == "")
        {
            std::cout << "I am not placed yet\n\n";
            return;
        }
        std::cout << "Current postion: " << toyRobot.m_x << ", " << toyRobot.m_y << ", " << toyRobot.m_facing << "\n\n";
    }


}
