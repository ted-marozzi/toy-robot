#include "CircularTable.hpp"
#include <cmath>
#include <iostream>
namespace Robot {
    bool CircularTable::IsValidPosition(int x, int y)
    {
        return std::pow(x - m_radius + 1, 2)
        + std::pow(y - m_radius + 1, 2) <= std::pow(m_radius - 1, 2);
    }

    void CircularTable::PrintTable(int x, int y, const std::string& facing)
    {
        std::cout << "\n";
        for (int j = (m_radius-1)*2; j >= 0; j--)
        {
            for (int i = 0; i <= 2*(m_radius-1); i++)
            {

                // Robot not on this square
                if (j != y || i != x)
                {
                    // If is a table postion, print a table square
                    if(IsValidPosition(i, j)) {
                        std::cout << "\u2B1C ";
                        continue;
                    }
                    // Else print a blank space
                    std::cout << "   ";
                    continue;
                }
                // Robot is on this square, so work out which way its facing
                if (facing == "NORTH")
                {
                    std::cout << " \u2191 ";
                    continue;
                }
                else if (facing == "EAST")
                {
                    std::cout << " \u2192 ";
                    continue;
                }
                else if (facing == "SOUTH")
                {
                    std::cout << " \u2193 ";
                    continue;
                }
                else if (facing == "WEST")
                {
                    std::cout << " \u2190 ";
                    continue;
                }
            }
            std::cout << "\n";
        }
        std::cout << " \u21e7 (0, 0)\n";
    }
}