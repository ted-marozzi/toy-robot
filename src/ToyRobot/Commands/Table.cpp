#include <iostream>
#include "Table.hpp"
#include "../Parser/IParser.hpp"

namespace Robot
{

    void Table::Execute(ToyRobot &toyRobot) const
    {
        m_table->PrintTable(toyRobot.m_x, toyRobot.m_y, toyRobot.m_facing);
    }

}