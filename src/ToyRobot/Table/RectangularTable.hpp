#pragma once

#include "ITable.hpp"

namespace Robot
{
    class RectangularTable : public ITable
    {
    public:
        RectangularTable(int width, int height) : m_width{width}, m_height{height} {};
        bool IsValidPosition(float x, float y) const override;
        void PrintTable(int x, int y, const std::string &facing) override;

    private:
        int m_width, m_height;
    };

}
