#pragma once
#include <string>

namespace Robot
{
    class ITable
    {
    public:
        virtual bool IsValidPosition(float x, float y) const = 0;
        virtual void PrintTable(int x, int y, const std::string &facing) = 0;
        static void PrintTable(ITable *table, int x, int y, const std::string &facing, int width, int height);
    };
}; // namespace Robot
