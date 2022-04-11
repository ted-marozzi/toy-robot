#include "RectangularTable.hpp"
#include <iostream>

namespace Robot
{
    bool RectangularTable::IsValidPosition(float x, float y) const
    {
        return x >= 0 && x < m_width && y >= 0 && y < m_height;
    }

    void RectangularTable::PrintTable(int x, int y, const std::string &facing)
    {
        ITable::PrintTable(this, x, y, facing, m_width, m_height);
    }
}