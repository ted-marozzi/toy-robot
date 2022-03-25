#include "RectangularTable.hpp"
#include <iostream>

namespace Robot
{
    bool RectangularTable::IsValidPosition(int x, int y)
    {
        return x >= 0 && x < m_width && y >= 0 && y < m_height;
    }

    void RectangularTable::PrintTable(int x, int y, const std::string &facing)
    {
        std::cout << "\n";
        for (int j = m_height-1; j >= 0; j--)
        {
            for (int i = 0; i < m_width; i++)
            {
                if (j != y || i != x)
                {
                    std::cout << "\u2B1C ";
                    continue;
                }

                if (facing == "NORTH")
                {
                    std::cout << " \u2191 ";
                }
                else if (facing == "EAST")
                {
                    std::cout << " \u2192 ";
                }
                else if (facing == "SOUTH")
                {
                    std::cout << " \u2193 ";
                }
                else if (facing == "WEST")
                {
                    std::cout << " \u2190 ";
                }
            }
            std::cout << "\n";
        }
        std::cout << " \u21e7 (0, 0)\n";
    }
}