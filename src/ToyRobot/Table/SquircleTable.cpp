#include "SquircleTable.hpp"
#include <iostream>
#include <cmath>

namespace Robot
{
    bool SquircleTable::IsValidPosition(int x, int y) const
    {
        float xPos = x + 0.5;
        float yPos = y + 0.5;
        return std::pow((2.0 * xPos) / (1.0 * m_width) - 1.0, 4.0) + std::pow((2.0 * yPos) / (1.0 * m_height) - 1.0, 4.0) <= 1.0;
    }

    void SquircleTable::PrintTable(int x, int y, const std::string &facing)
    {
        ITable::PrintTable(this, x, y, facing, m_width, m_height);
    }
}