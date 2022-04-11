#pragma once
#include "ITable.hpp"

namespace Robot
{
    class CircularTable : public ITable
    {
    public:
        CircularTable(int diameter) : m_diameter{diameter} {};
        bool IsValidPosition(int x, int y) const override;
        void PrintTable(int x, int y, const std::string &facing) override;

    private:
        int m_diameter;
    };

}