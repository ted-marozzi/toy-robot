#pragma once

#include "ITable.hpp"

namespace Robot
{
    class SquircleTable : public ITable
    {
    public:
        SquircleTable(int width, int height) : m_width{width}, m_height{height} {};
        bool IsValidPosition(float x, float y) const override;
        void PrintTable(int x, int y, const std::string &facing) override;

    private:
        int m_width, m_height;
    };

}
