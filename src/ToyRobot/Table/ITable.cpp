#include <iostream>
#include <cmath>

#include "ITable.hpp"

namespace Robot
{
    void ITable::PrintTable(ITable *table, int x, int y, const std::string &facing, int width, int height)
    {
        std::cout << " \u21e9 (0, " << height - 1 << ")\n";
        // Iterate the mid midpoint to check if the robot is on a grid square, this is because the spec defines the robots positions
        // as 0,0 for example but our table starts at 0,0 so we shift the reference to 0.5,0.5. A bit confusing but its the only way
        // i can see to use maths equations for the IsValidPositions
        for (float j = height - 0.5; j >= 0.5; j--)
        {
            for (float i = 0.5; i < width; i++)
            {

                // Robot not on this square
                // Convert back from the 0.5 offset to the robots integer reference frame
                if ((int)floor(j) != y || (int)floor(i) != x)
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