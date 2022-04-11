#include "CircularTable.hpp"
#include <cmath>
#include <iostream>
namespace Robot
{
    bool CircularTable::IsValidPosition(int x, int y) const
    {
        float xPos = x + 0.5;
        float yPos = y + 0.5;
        return std::pow(xPos - m_diameter * 1.0 / 2, 2) + std::pow(yPos - m_diameter * 1.0 / 2, 2) <= std::pow(m_diameter * 1.0 / 2, 2);
    }

    void CircularTable::PrintTable(int x, int y, const std::string &facing)
    {
        ITable::PrintTable(this, x, y, facing, m_diameter, m_diameter);
    }
}