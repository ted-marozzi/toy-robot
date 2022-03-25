#pragma once
#include <string>

namespace Robot
{
    class ITable {
        public:
            virtual bool IsValidPosition(int x, int y) = 0;
            virtual void PrintTable(int x, int y, const std::string &facing) = 0;
    };
} // namespace Robot

