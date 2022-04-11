#include "CircularTable.hpp"
#include <cmath>
#include <iostream>
namespace Robot
{
    bool CircularTable::IsValidPosition(float x, float y) const
    {
        return std::pow(x - m_diameter * 1.0 / 2, 2) + std::pow(y - m_diameter * 1.0 / 2, 2) <= std::pow(m_diameter * 1.0 / 2, 2);
    }

    void CircularTable::PrintTable(int x, int y, const std::string &facing)
    {
        ITable::PrintTable(this, x, y, facing, m_diameter, m_diameter);
    }
}