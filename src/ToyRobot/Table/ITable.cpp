#include <iostream>
#include <cmath>

#include "ITable.hpp"

namespace Robot
{
    void ITable::PrintTable(ITable *table, int x, int y, const std::string &facing, int width, int height)
    {
        std::cout << " \u21e9 (0, " << height - 1 << ")\n";
        for (int j = height - 1; j >= 0; j--)
        {
            for (int i = 0; i < width; i++)
            {

                // Robot not on this square
                // Convert back from the 0.5 offset to the robots integer reference frame
                if (j != y || i != x)
                {
                    // If is a table postion, print a table square
                    if (table && table->IsValidPosition(i, j))
                    {
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