#include "RectangularTable.hpp"
#include <iostream>

namespace Robot
{
    bool RectangularTable::IsValidPosition(int x, int y)  const
    {
        float xPos = x + 0.5;
        float yPos = y + 0.5;
        return xPos > 0 && xPos < m_width && yPos > 0 && yPos < m_height;
    }

    void RectangularTable::PrintTable(int x, int y, const std::string &facing)
    {
        ITable::PrintTable(this, x, y, facing, m_width, m_height);
    }
}