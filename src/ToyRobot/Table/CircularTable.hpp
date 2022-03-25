#pragma once
#include "ITable.hpp"

namespace Robot
{
    class CircularTable : public ITable
    {
    public:
        CircularTable(int radius) : m_radius{ radius } {};
        bool IsValidPosition(int x, int y) override;
        void PrintTable(int x, int y, const std::string &facing) override;

    private:
        int m_radius;
    };

}