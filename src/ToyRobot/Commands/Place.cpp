#include <iostream>
#include <vector>
#include <algorithm>
#include "Place.hpp"

namespace Robot
{
    void Place::Execute(ToyRobot &toyRobot) const
    {
        std::cout << "Placed at "<< m_x << ", " << m_y << ", " << m_facing << "\n\n";
        toyRobot.m_x = m_x;
        toyRobot.m_y = m_y;
        toyRobot.m_facing = m_facing;
    }
}
